#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAXN 100
using namespace std;

vector<int> Son[MAXN];
int weight[MAXN];
int S;
int path[MAXN];
vector<int> leaf;

void dfs( int root, int w, int father )
{
	path[root] = father;
	if( w == S && Son[root].size() == 0 ) 
		leaf.push_back(root);
	for( vector<int>::iterator it = Son[root].begin(); it != Son[root].end(); it++){
		dfs(*it, w+weight[*it], root);
	}
}

bool cmp(int a, int b)
{
	return weight[a] > weight[b];
}

void PrintPath( int end )
{
	if( path[end] != 0 )
		PrintPath(path[end]);
	printf(" %d", weight[end]);
}

int main()
{
	int N, M;
	scanf("%d%d%d", &N, &M, &S);
	for( int i = 0; i < N; i++ )
		scanf("%d", &weight[i]);
	for( int i = 0; i < M; i++ ){
		int ID, K, son;
		scanf("%d%d", &ID, &K);
		while( K-- ){
			scanf("%d", &son);
			Son[ID].push_back(son);
		}
	}
	if( M == 0 ){
		if( weight[0] == S )
			printf("%d\n", weight[0]);
		return 0;
	}
	
	for( int i = 0; i < N; i++ )
		sort(Son[i].begin(), Son[i].end(), cmp);
	for( int i = 0; i < N; i++ )
		path[i] = -1;
	dfs(0, weight[0], -1);
	for( int i = 0; i < leaf.size(); i++ ){
		printf("%d", weight[0]); // 控制输出结果末尾没有空格 
		PrintPath(leaf[i]);
		printf("\n");
	}
		
	return 0;

}
