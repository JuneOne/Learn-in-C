// 考虑一下int可以有多大 12345678910好像就超了
#include <stdio.h>

char word[10][6] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void English( int N )
{
	if( N != 0 ){
		English( N / 10 );
		printf("%s ", word[N % 10]);
	}
}

int main()
{
	// int N;
	char c;
	int sum = 0;
	// scanf("%d", &N);
	// printf("%d", N);
	// while(N){
	// 	sum += N % 10;
	// 	N /= 10;
	// }
	while( ( c = getchar() ) != '\n' ){
		sum += c - '0';
	}
	English(sum/10);
	printf("%s\n", word[sum % 10]);

	return 0;
}