#include <stdio.h>
#include <math.h>

int main()
{
	int i, j, N;
	int a;
	int cnt = 0;
	int temp;
	int factor;
	scanf("%d", &N);

	for( i = 2; i <= sqrt(N); i++ )
	{
		if( N % i == 0 ){
			a = N / i;
			temp = 1;
			for( j = i+1; j <= a ; j++ )
			{
				if( a % j == 0 ){
					a /= j;
					temp++;
				} else {
					break;
				}
			}
		}
		if( temp > cnt ){
			cnt = temp;
			factor = i;
		}
	}
	if( cnt == 0 ){
		printf("1\n");
		printf("%d\n", N);
	} else {
		printf("%d\n", cnt);
		printf("%d", factor);
		for( i = factor+1, j = 1; j < cnt; i++, j++ )
			printf("*%d", i);
	}
	return 0;

}