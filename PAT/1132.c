#include <stdio.h>
#include <math.h>

int Digit( int n )
{
	int cnt = 0;
	while( n ){
		n /= 10;
		cnt++;
	}
	return cnt;
}

int main()
{
	int i, N;
	int len;
	int number, temp;
	int left, right;
	scanf("%d", &N);
	while( N-- )
	{
		left = right = 0;
		scanf("%d", &number);
		len = Digit(number);
		right = number % ((int)pow(10, len/2));
		left = (number-right) / ((int)pow(10, len/2));
		if( right == 0 )
			printf("No\n");
		else{
			if( number % ( left * right ) == 0 )
				printf("Yes\n");
			else
				printf("No\n");
		}
	}

	return 0;

}