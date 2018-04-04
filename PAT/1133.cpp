#include <stdio.h>
#include <vector>
using namespace std;

struct node{
	int data;
	int next;
}T1[100005];

vector<int> V[3];

int main()
{
	int start, N, K;
	int index;
	scanf("%d%d%d", &start, &N, &K);
	for( int i = 0; i < N; i++ ){
		scanf("%d", &index);
		scanf("%d%d", &T1[index].data, &T1[index].next);
	}
	int cnt = 0;
	while( start != -1 )
	{
		if( T1[start].data < 0 )
			V[0].push_back(start);
		else if ( T1[start].data <= K )
			V[1].push_back(start);
		else
			V[2].push_back(start);
		start = T1[start].next;
	}
	bool flag = false;
	for( int i = 0; i < 3; i++ ){
		for( int j = 0; j < V[i].size(); j++ ){
			if( !flag ){
				printf("%05d %d ", V[i][j], T1[V[i][j]].data);
				flag = true;
			} else
				printf("%05d\n%05d %d ", V[i][j], V[i][j], T1[V[i][j]].data);
		}
	}
	printf("-1\n");
}
