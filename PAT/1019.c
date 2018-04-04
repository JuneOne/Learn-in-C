#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void IsPalindromic( int N, int b )
{
	int *result;
	int i, len;

	for( i = 0; pow( b, i ) <= N; i++ );
	len = i;
	if( len == 1 ){
		printf("Yes\n");
		printf("%d\n", N);
		return;
	}
	result = (int*)malloc(sizeof(int) * len);
	i = 0;
	while( N > 0 ){
		result[i++] = N % b;
		N /= b;
	}

	for( i = 0; i < len; i++ ){
		if( result[i] != result[len-1-i] ){
			printf("No\n");
			break;
		}
	}
	if( i == len )
		printf("Yes\n");
	printf("%d", result[len-1]);
	for( i = len-2; i >= 0; i-- )
		printf(" %d", result[i]);
	printf("\n");
	
}

int main()
{
	int b, N;
	scanf("%d%d", &N, &b);

	IsPalindromic(N, b);

	return 0;
}