#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <set>

using namespace std;

typedef struct node *GNode;
struct node{
	int vertex;
	GNode next;
}G[10005];

int S[10005];
int dep[10005];
bool visit[10005];
set<int> Root;

void dfs( int root, int deep )
{
	visit[root] = true;
	dep[root] = deep;
	GNode p = G[root].next;
	while( p != NULL ){
		if( !visit[p->vertex] )
			dfs( p->vertex, deep+1);
		p = p->next;
	}
}

void Insert( int V1, int V2 )
{
	GNode p = (GNode)malloc(sizeof(struct node));
	p->vertex = V2;
	p->next = G[V1].next;
	G[V1].next = p;
}

int find( int x )
{
	if( S[x] == x )
		return x;
	else
		return S[x]=find(S[x]);
}

void Union( int root1, int root2 )
{
	if( find(root1) == find(root2) )
		return;
	else
		S[find(root2)] = find(root1);
}

//void Union( int root1, int root2 )
//{
//	int faR1 = find(root1);
//	int faR2 = find(root2);
//	if( faR1 != faR2 )
//		S[faR2] = faR1;
//}

int main()
{
	int N, V1, V2;
	int cnt = 0;
	scanf("%d", &N);
	for( int i = 1; i <= N; i++ ){
		S[i] = i;
		G[i].next = NULL;
		visit[i] = false;
	}
	for( int i = 0; i < N-1; i++ ){
		scanf("%d%d", &V1, &V2);
		Insert(V1, V2);
		Insert(V2, V1);
		Union(V1, V2);
	}
	for( int i = 1; i <= N; i++ ){
		if( S[i] == i )
			cnt++;
	}

	if( cnt == 1 ){
		dfs(1,0);
		int max = -1, index;
		for( int i = 1; i <= N; i++ )
			if( max < dep[i] ){
				max = dep[i];
				index = i;
			}
		for( int i = 1; i <= N; i++ )
			if( dep[i] == max )
				Root.insert(i);
		for( int i = 1; i <= N; i++ ){
			visit[i] = false;
			dep[i] = 0;
		}

		dfs(index, 0);
		for( int i = 1; i <= N; i++ ){
			if( max < dep[i] )
				max = dep[i];
		}
		for( int i = 1; i <= N; i++ ){
			if( max == dep[i] )
				Root.insert(i);
		}
		for( set<int>::iterator it=Root.begin(); it != Root.end(); it++ )
			printf("%d\n", *it);
	} else {
		printf("Error: %d components\n", cnt);
	}
} 

// 换成set+将第一次dfs得到的点都记录下来就对了 ... 
