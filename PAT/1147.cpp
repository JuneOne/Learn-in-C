#include <stdio.h>
#include <vector>

using namespace std;

vector<int> V;
int M, N;
bool space;

bool IsMax()
{
	for( int i = N/2; i > 0; i-- )
	{
		if( 2*i + 1 <= N ){
			if( V[2*i+1] > V[i] || V[2*i] > V[i] )
				return false;
		} else {
			if( V[2*i] > V[i] )
				return false;
		}
	}
	
	return true;
}

bool IsMin()
{
	for( int i = N/2; i > 0; i-- )
	{
		if( 2*i + 1 <= N ){
			if( V[2*i+1] < V[i] || V[2*i] < V[i] )
				return false;
		} else {
			if( V[2*i] < V[i] )
				return false;
		}
	}
	
	return true;
}

void PostOrder( int root )
{
	if( root <= N ){
		PostOrder( 2*root );
		PostOrder( 2*root+1 );
		if( !space ){
			printf("%d", V[root]);
			space = true;
		} else 
			printf(" %d", V[root]);
	}
}

int main()
{
	scanf("%d%d", &M, &N);
	V.resize(N+1);
	while( M-- )
	{
		int Min = 0x7fffffff;
		int Max = 0xffffffff;
		bool flag = false;
		space = false;
		for( int i = 1; i <= N; i++ )
		{
			scanf("%d", &V[i]);
			if( V[i] < Min ) Min = V[i];
			if( V[i] > Max ) Max = V[i];
		}
		if( V[1] == Max ){
			if( IsMax() ){ 
				printf("Max Heap\n");
				flag = true;
			}
		} else if ( V[1] == Min )
			if( IsMin() ){
				printf("Min Heap\n");
				flag = true;
			}				
		if( !flag )
			printf("Not Heap\n");
		
		PostOrder(1);
		printf("\n");
	}
}
