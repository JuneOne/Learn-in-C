#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

bool IsPrime( int n )
{
	if( n == 0 || n == 1 )
		return false;
	for( int i = 2; i <= sqrt(n); i++ )
		if( n % i == 0 )
			return false;
	return true;
}
int main()
{
	int Size, N, M;
	int cnt = 0;
	scanf("%d%d%d", &Size, &N, &M);
	while( !IsPrime(Size) )
		Size++;
	vector<int> V(Size);
	for( int i = 0; i < N; i++ ){
		int x, j;
		scanf("%d", &x);
		for( j = 0; j < Size; j++ ){
			if( V[(x%Size+j*j)%Size] == 0 ){
				V[(x%Size+j*j)%Size] = x;
				break;	
			}
		}
		if( j == Size )
			printf("%d cannot be inserted.\n", x);
	}
	for( int i = 0; i < M; i++ ){
		int value, j;
		scanf("%d", &value);
		for( j = 0; j < Size; j++ ){			
			if( V[(value%Size+j*j)%Size] == 0 || V[(value%Size+j*j)%Size] == value )
				break;

		}
		cnt += j+1;
	}
	printf("%.1f\n", 1.0*cnt / M);
}
