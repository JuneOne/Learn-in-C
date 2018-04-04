#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int CBT[1001];
int data[1001];
int N;
int index = 0;

void Insert( int root )
{
	if( root <= N )
	{
		Insert(2*root);
		CBT[root] = data[index++];
		Insert(2*root+1);
	}
}

int main()
{
	scanf("%d", &N);
	for( int i = 0; i < N; i++ )
		scanf("%d", &data[i]);
	sort(data, data+N);
	Insert(1);
	printf("%d", CBT[1]);
	for( int i = 2; i <= N; i++ )
		printf(" %d", CBT[i]);
	printf("\n");
	
	return 0;
}

