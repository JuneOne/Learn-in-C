#include <stdio.h>
#include <vector>
#define MAXN 100

using namespace std;

vector<int> Son[MAXN];
int dep[MAXN];
int cnt[MAXN];
int maxL;

void BFS( int root ){
	int Queue[MAXN];
	int rear = 0, front = 0;
	Queue[++rear] = root;
	while( front < rear )
	{
		int parent = Queue[++front];
		if( dep[parent] > maxL )
			maxL = dep[parent];
		if( Son[parent].size() == 0 )
			cnt[dep[parent]]++;
		for( int i = 0; i < Son[parent].size(); i++ ){
			dep[Son[parent][i]] = dep[parent] + 1;
			Queue[++rear] = Son[parent][i];
		}
	}
}

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	while( M-- ){
		int ID, K, son;
		scanf("%d%d", &ID, &K);
		while( K-- ){
			scanf("%d", &son);
			Son[ID].push_back(son);
		}
	}
	BFS(1);
	printf("%d", cnt[0]);
	for( int i = 1; i <= maxL; i++ )
		printf(" %d", cnt[i]);
	printf("\n");
	
	return 0;
}
