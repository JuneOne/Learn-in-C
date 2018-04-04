#include <stdio.h>
#include <vector>

using namespace std;

vector<int> Son[100];
int pop[100];
int level;

void dfs( int root, int deep )
{
	if( deep > level )
		level = deep;
	pop[deep]++;
	for( vector<int>::iterator it = Son[root].begin(); it < Son[root].end(); it++ )	{
		dfs(*it, deep+1);
	}	
}

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	for( int i = 0; i < M; i++ )
	{
		int ID, K, son;
		scanf("%d%d", &ID, &K);
		while( K-- ){
			scanf("%d", &son);
			Son[ID].push_back(son);
		} 
	}
	dfs(1, 1);
	int max = 0, index;
	for( int i = 1; i <= level; i++ )
		if( pop[i] > max ){
			max = pop[i];
			index = i;
		}
	printf("%d %d\n", max, index);
	
	return 0;
	
	return 0;
}
