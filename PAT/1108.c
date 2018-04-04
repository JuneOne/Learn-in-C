#include <stdio.h>

int main()
{
	int i, N;
	int dot;
	int flag;
	int error;
	double number;
	int fraction;
	double sum = 0.0;
	char s[10000];
	int cnt = 0;
	scanf("%d", &N);

	while( N-- )
	{
		scanf("%s", s);
		i = fraction = 0;
		dot = flag = error = 0;
		number = 0.0;
		if( s[0] == '-' ){
			flag = 1;
			i++;
		}

		for(; s[i] != '\0'; i++ ){
			if( s[i] >= '0' && s[i] <= '9' ){
				number *= 10;
				number += s[i] - '0';
				// printf("number = %f\n", number);
				if( dot == 1 ){
					fraction++;
					if( fraction > 2 ){
						error = 1;
						break;
					}
				}
			} else if ( s[i] == '.' ){
				if( dot == 0 )
					dot = 1;
				else{
					error = 1;
					break;
				}
			} else {
				error = 1;
				break;
			}
		}

		if( error == 1 ){
			printf("ERROR: ");
			printf("%s ", s);
			printf("is not a legal number\n");
		} else {
			if( flag == 1 )
				number = -number;
			while( fraction-- )
				number /= 10;
			// printf("number = %f\n", number);
			if( number < -1000 || number > 1000 ){
				printf("ERROR: ");
				printf("%s ", s);
				printf("is not a legal number\n");
			} else {
				sum += number;
				cnt++;
			}
		}
	}

	if( cnt == 0 )
		printf("The average of 0 numbers is Undefined\n");
	else if ( cnt == 1 )
		printf("The average of 1 number is %.2f\n", sum);
	else
		printf("The average of %d numbers is %.2f\n", cnt, sum / cnt );

	return 0;
}