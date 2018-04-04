#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// printf("%04d") ----> 敲黑板
int IsPrime( int n )
{
	int i;
	for( i = 2; i <= sqrt(n); i++ )
		if( n % i == 0 )
			return 0;
	return 1;

}

int Find( int n, int *s, int len )
{
	int i;
	for( i = 1; i <= len; i++ )
	{
		if( s[i] == n )
			return i;
	}

	return 0;
}

int IsNew( int index, int *s, int len )
{
	int i;
	int flag = 1;
	for( i = 1; i <= len; i++ )
	{
		if( s[index] == s[i] && index != i )
		{
			if( i < index )
				flag = 0;
		}

	}

	return flag;

}

int main()
{
	int i, N, K;
	int *rank;
	int *list;

	scanf("%d", &N);
	rank = (int*)malloc(sizeof(int) * (N+1));
	for( i = 1; i <= N; i++ )
		scanf("%d", &rank[i]);
	scanf("%d", &K);
	list = (int*)malloc(sizeof(int) * (K+1));
	for( i = 1; i <= K; i++ )
		scanf("%d", &list[i]);
	for( i = 1; i <= K; i++ )
	{
		if( Find(list[i], rank, N) == 0  )
		{
			printf("%04d: Are you kidding?\n", list[i]);

		} else if ( IsNew(i, list, K) == 0 )
			printf("%04d: Checked\n", list[i]);
		else {	
			if( Find(list[i], rank, N) == 1 )
				printf("%04d: Mystery Award\n", list[i]);	
			else if ( IsPrime(Find(list[i], rank, N)) == 1 )
				printf("%04d: Minion\n", list[i]);
			else
				printf("%04d: Chocolate\n", list[i]);
		}
	}

	return 0;
}