#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool IsPrime( int N )
{
	for( int i = 2; i <= sqrt(N); i++ )
		if( N % i == 0 )
			return false;
	return true;
}

int main()
{
	long int N, temp;
	scanf("%ld", &N);
	if( N == 1 )
		printf("1=1\n");
	else
		printf("%ld=", N);
	temp = N;
	for( long int i = 2; i <= N && temp > 1 ; i++ )
	{
		if( IsPrime(i) && temp % i == 0 ){
			int cnt = 0;
			while( temp % i == 0 )
			{
				cnt++;
				temp /= i;
			}
			if( cnt == 1 ){
				printf("%d", i);
			} else if ( cnt > 1 )
				printf("%d^%d", i, cnt);
			if( temp != 1 )
				printf("*");
		}
	}
}
