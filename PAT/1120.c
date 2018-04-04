#include <stdio.h>

int Calculate( int n )
{
	int sum = 0;
	while( n )
	{
		sum += n % 10;
		n /= 10;
	}

	return sum;
}

int main()
{
	int i, N;
	int number;
	int index;
	int space = 0;
	int id[37] = {0};
	int cnt = 0;
	scanf("%d", &N);
	while( N-- )
	{
		scanf("%d", &number);
		id[Calculate(number)]++;
	}

	for( i = 0; i <= 36; i++ )
		if( id[i] > 0 )
			cnt++;
	printf("%d\n", cnt);
	for( i = 0; i <= 36; i++ )
		if( id[i] > 0 ){
			if( space == 0 ){
				space = 1;
				printf("%d", i);
			} else {
				printf(" %d", i);
			}
		}
	printf("\n");

	return 0;
}