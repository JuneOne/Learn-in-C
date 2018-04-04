#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

typedef struct gnode *GNode;
struct gnode{
	int vertex;
	GNode next;
}LGraph[MAX];

int Nv;
int visit[MAX];
int deep[MAX];
int choose[MAX];

void bfs( int v )
{
	int i;
	int queue[MAX];
	int rear, front;
	for( i = 1; i <= Nv; i++ )
	{
		visit[i] = 0;
		deep[i] = 0;
	}

	rear = front = 0;
	visit[v] = 1;
	queue[++rear] = v;

	while( rear != front )
	{
		v = queue[++front];
		GNode p = LGraph[v].next;
		while( p != NULL )
		{
			int w = p->vertex;
			if( visit[w] == 0 ){
				visit[w] = 1;
				deep[w] = deep[v] + 1;
				queue[++rear] = w;
			}
			p = p->next;
		}
	}
}

int main()
{
	int i, V1, V2;
	GNode E1, E2;
	scanf("%d", &Nv);
	for( i = 1; i <= Nv; i++ )
		LGraph[i].next = NULL;
	for( i = 1; i < Nv; i++ )
	{
		E1 = (GNode)malloc(sizeof(struct gnode));
		E2 = (GNode)malloc(sizeof(struct gnode));
		scanf("%d %d", &V1, &V2);

		E1->vertex = V2;
		E1->next = LGraph[V1].next;
		LGraph[V1].next = E1;

		E2->vertex = V1;
		E2->next = LGraph[V2].next;
		LGraph[V2].next = E2;
	}

	int cnt = 0;
	for( i = 1; i <= Nv; i++ )
	{
		if( visit[i] == 0 ){
			bfs(i);
			cnt++;
		}
	}

	if( cnt == 1 )
	{
		int max = -1;
		int maxind;
		for( i = 1; i <= Nv; i++ )
		{
			if( deep[i] > max )
			{
				max = deep[i];
				maxind = i;
			}
		}

		bfs(maxind);
		max = -1;
		for( i = 1; i <= Nv; i++ ){
			if( deep[i] > max )
				max = deep[i];
		}
		for( i = 1; i <= Nv; i++ )
			if( deep[i] == max )
				choose[i] = 1;

		choose[maxind] = 1;
		for( i = 1; i <= Nv; i++ )
			if( choose[i] == 1 )
				printf("%d\n", i);

	} else if ( cnt > 1 )
		printf("Error: %d components\n", cnt);
}