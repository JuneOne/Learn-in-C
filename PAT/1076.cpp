#include <stdio.h>
#include <vector>
#include <memory.h>

using namespace std;

vector<int> V[1005];
bool visit[1005];
int level[1005];
int N, L;

int cnt;

void bfs( int root )
{
	int Queue[1005];
	int front = 0, rear = 0;
	Queue[++rear] = root;
	level[root] = 0;
	visit[root] = true;
	
	while( front != rear )
	{
		int parent = Queue[++front];
		if( level[parent] == L )
			break;
		for( int i = 0; i < V[parent].size(); i++ ){
			if( !visit[V[parent][i]] ){
				Queue[++rear] = V[parent][i];
				visit[V[parent][i]] = true;
				level[V[parent][i]] = level[parent] + 1;
				cnt++;
			}
		}
	}
}

int main()
{
	int M, user, K, ID;
	scanf("%d%d", &N, &L);
	for( int i = 1; i <= N; i++ ){
		scanf("%d", &M);
		for( int j = 0; j < M; j++ ){
			scanf("%d", &user);
			V[user].push_back(i);
		}
	}
	scanf("%d", &K);
	for( int i = 0; i < K; i++ ){
		cnt = 0;
		memset(visit, false, 1005);
		memset(level, 0, 1005);
		scanf("%d", &ID);
		bfs(ID);
		printf("%d\n", cnt);
	}

	return 0;
}
