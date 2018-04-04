#include <stdio.h>

#define MAXN 500
#define INF 65535

int G[MAXN][MAXN], Nv, Ne;
int dist[MAXN], path[MAXN], visit[MAXN];
int cnt[MAXN]; // 表示src到i的路径条数
int Team[MAXN];
int num[MAXN];

void Dijkstra( int S )
{
	int minV, V; // minV是未收录的最小dist的顶点
	int minDist;

	for( V = 0; V < Nv; V++ ){
		dist[V] = G[S][V];
		if( dist[V] < INF ){
			cnt[V] = 1;
			num[V] = Team[S] + Team[V];
		}
	}
	
	dist[S] = 0;
	visit[S] = 1;
	cnt[S] = 1;
	num[S] = Team[S];

	while(1)
	{
		minDist = INF;
		for( V = 0; V < Nv; V++ ){
			if( visit[V] == 0 && dist[V] < minDist ){
				minDist = dist[V];
				minV = V;
			}
		}
		if( minDist == INF )
			break;
		visit[minV] = 1;
		for( V = 0; V < Nv; V++ ){
			if( G[minV][V] < INF && visit[V] == 0 )
				if( dist[V] > dist[minV] + G[minV][V] ){
					dist[V] = dist[minV] + G[minV][V];
					// path[V] = minV;
					cnt[V] = cnt[minV];
					num[V] = num[minV] + Team[V];
				} else if( dist[V] == dist[minV] + G[minV][V] ){
					cnt[V] += cnt[minV];
					if( num[V] < num[minV] + Team[V] )
						num[V] = num[minV] + Team[V];
				}
		}
	}
}

int main()
{
	int i, j, V1, V2, Weight;
	int start, end;

	scanf("%d%d%d%d", &Nv, &Ne, &start, &end);
	for( i = 0; i < Nv; i++ )
		scanf("%d", &Team[i]);
	for( i = 0; i < Nv; i++ )
		for( j = 0; j < Nv; j++ )
			G[i][j] = INF;
	
	for( i = 0; i < Ne; i++ ){
		scanf("%d%d%d", &V1, &V2, &Weight);
		G[V1][V2] = Weight;
		G[V2][V1] = Weight;
	}

	Dijkstra(start);
	// printf("mindist(%d->%d) = %d\n", start, end, dist[end]);
	printf("%d %d\n", cnt[end], num[end]);

	return 0;
}

