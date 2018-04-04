#include <stdio.h>

#define MAXN 501
#define INF 0x7FFFFFFF
struct node{
	int d;
	int c;
}G[MAXN][MAXN];

int Nv, Ne;
int dis[MAXN];
int cost[MAXN];
int path[MAXN];
int visit[MAXN];

void Dijkstra( int S )
{
	int i;
	for( i = 0; i < Nv; i++ ) {
		visit[i] = 0;
		if( G[S][i].d < INF ){
			dis[i] = G[S][i].d;
			cost[i] = G[S][i].c;
			path[i] = S;
		} else {
			path[i] = -1;
		}
	}
	
	dis[S] = 0;
	cost[S] = 0;
	visit[S] = 1;
	
	while(1){
		int MinV, MinDis = INF;
		for( i = 0; i < Nv; i++ ){
			if( visit[i] == 0 && dis[i] < MinDis ){
				MinDis = dis[i];
				MinV = i;
			}
		}
		if( MinDis == INF )
			break;
			
		visit[MinV] = 1;
		for( i = 0; i < Nv; i++ )
		{
			if( G[MinV][i].d < INF && visit[i] == 0 ){
				if( dis[i] > dis[MinV] + G[MinV][i].d ){
					dis[i] = dis[MinV] + G[MinV][i].d;
					cost[i] = cost[MinV] + G[MinV][i].c;
					path[i] = MinV;
				} else if ( dis[i] == dis[MinV] + G[MinV][i].d ){
					if( cost[i] > cost[MinV] + G[MinV][i].c ){
						cost[i] = cost[MinV] + G[MinV][i].c;
						path[i] = MinV;
					}
				}
			}
		}
	}
}

void Print( int e )
{
	if( path[e] != -1 )
		Print( path[e] );
	printf("%d ", e);
}
 
int main()
{
	int i, j;
	int start, end;
	int V1, V2, Dis, Cost;
	scanf("%d%d%d%d", &Nv, &Ne, &start, &end);
	for( i = 0; i < Nv; i++ ) {
		dis[i] = INF;
		cost[i] = INF;
		for( j = 0; j < Nv; j++ ){
			G[i][j].d = INF;
			G[i][j].c = INF;
		}
	}
	for( i = 0; i < Ne; i++ ) {
		scanf("%d%d%d%d", &V1, &V2, &Dis, &Cost);
		G[V1][V2].d = G[V2][V1].d = Dis;
		G[V1][V2].c = G[V2][V1].c = Cost;
	}
	Dijkstra(start);
	
	Print(end);
	printf("%d %d\n", dis[end], cost[end]);
	return 0;
}
