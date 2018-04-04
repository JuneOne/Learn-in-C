#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[12][4] = {"jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char b[12][4] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

void Mar_to_Earth( char s[], int len )
{
	int i, j = 0;
	if( len == 3 || len == 4 ){
		if ( strcmp(s, "tret") == 0 ){
			printf("0\n");
			return;
		} else {
			for( i = 0; i < 12; i++ ){
				if( strcmp(s, a[i]) == 0 ){
					printf("%d\n", i+1);
					return;
				}
			}

			for( i = 0; i < 12; i++ ){
				if( strcmp(s, b[i]) == 0 ){
					printf("%d\n", 13*(i+1));
					return;
				}
			}
		}
	} else {
		char s1[5], s2[5];

		int number = 0;
		for( i = 0; s[i] != ' ' ; i++ ){
			s1[i] = s[i]; 
		}
		s1[i] = '\0';
		for( i = i + 1; s[i] != '\0'; i++ ){
			s2[j++] = s[i];
		}
		s2[j] = '\0';
		// printf("%s %s", s1, s2);
		for( i = 0; i < 13; i++ ){
			if( strcmp(s1, b[i]) == 0 ){
				number += 13 * (i+1);
				break;
			}
		}
		for( i = 0; i < 13; i++ ){
			if( strcmp(s2, a[i]) == 0 ){
				number += i+1;
				break;
			}
		}
		printf("%d\n", number);
		return;
	}
}

void Earth_to_Mar( char s[] )
{
	int i;
	int number = 0;
	for( i = 0; s[i] != '\0'; i++ ){
		number *= 10;
		number += s[i] - '0'; 
	}
	if( number == 0 ){
		printf("tret\n");
		return;
	} else if ( number < 13 ){
		printf("%s\n", a[number-1]);
		return;
	} else if ( number % 13 == 0 ){
		printf("%s\n", b[number/13-1]);
		return;
	} else {
		printf("%s ", b[number/13-1]);
		printf("%s\n", a[number%13-1]);
		return;
	}
}

int main()
{
	int i, N;
	char c;
	char num[10];

	scanf("%d", &N);
	getchar();
	while(N--){
		// printf("N=%d\n", N);
		i = 0;
		while( ( c = getchar() ) != '\n' )
			num[i++] = c;
		num[i] = '\0';
		if( num[0] >= '0' && num[0] <= '9' )
			Earth_to_Mar(num);
		else
			Mar_to_Earth(num, i);
	}

	return 0;
}