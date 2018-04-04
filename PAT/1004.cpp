#include <stdio.h>
#include <vector>

using namespace std;

vector<int> Son[100];
int dep[100], p;

void dfs( int root, int deep )
{
	if( deep > p )
		p = deep;
	if( Son[root].size() == 0 )
		dep[deep]++;
	else{
		for( vector<int>::iterator it = Son[root].begin(); it < Son[root].end(); it++ )
			dfs(*it, deep+1);
	}	
	
}

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	for( int i = 0; i < M; i++ ){
		int ID, K, son;
		scanf("%d%d", &ID, &K);
		while( K-- ){
			scanf("%d", &son);
			Son[ID].push_back(son);
		}
	}
	dfs(1, 0);
	printf("%d", dep[0]);
	for( int i = 1; i <= p; i++ )
		printf(" %d", dep[i]);
	printf("\n");
	
	return 0;
}
