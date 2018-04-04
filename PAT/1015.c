#include <stdio.h>
#include <math.h>

int sum;
int D;

int IsPrime( int N )
{
	int i;
	if( N == 1 )
		return 0;
	for( i = 2; i <= sqrt(N); i++ ){
		if( N % i == 0 )
			return 0;
	}

	return 1;
}

void Reverse( int N )
{
	if( N > 0 ){		
		sum = D*sum;
		sum += N % D;
		// printf("sum = %d\n", sum);
		Reverse( N / D );
	}

}

int main()
{
	int N;

	while(1){
		scanf("%d", &N);
		if( N < 0 ){
			break;
		}
		scanf("%d", &D);
		sum = 0;
		Reverse(N);
		if(  IsPrime(N) && IsPrime(sum) )
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}