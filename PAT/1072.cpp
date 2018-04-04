#include <stdio.h>
#include <memory.h>

#define INF 0x7fffffff

using namespace std;

int G[1015][1015], Nv;
int dis[1015];
bool visit[1015];

int N, M, K, DS;

int toVertex( char g[] )
{
	int V = 0;
	if( g[0] == 'G' ){
		for( int j = 1; g[j] != '\0'; j++ )
			V = 10*V + g[j] - '0';
		V += N;
	} else {
		for( int j = 0; g[j] != '\0'; j++ )
			V = 10*V + g[j] - '0';
	}	
	return V;	
}

void Dijkstra( int S )
{
	for( int i = 1; i <= Nv; i++ )
		dis[i] = G[S][i];
//	for( int i = 1; i <= Nv; i++ )
//		printf("%d ", dis[i]);
//	printf("\n");
	dis[S] = 0;	
	visit[S] = true;
	
	while(1)
	{
		int Min, MinDist = INF;
		for( int i = 1; i <= Nv; i++ ){
			if( !visit[i] && dis[i] < MinDist ){
				Min = i;
				MinDist = dis[i];
			}
		}
		if( MinDist == INF ) break;
		visit[Min] = true;
		for( int i = 1; i <= Nv; i++ ){
			if( !visit[i] && G[Min][i] < INF ){
				if( dis[i] > dis[Min] + G[Min][i] )
					dis[i] = dis[Min] + G[Min][i];
			}
		}
	}
}

int main()
{
	int V1, V2, weight;
	char g1[4], g2[4];
	scanf("%d%d%d%d", &N, &M, &K, &DS);
	Nv = N+M;
	for( int i = 1; i <= Nv; i++ )
		for( int j = 1; j <= Nv; j++ )
			G[i][j] = INF;
	for( int i = 0; i < K; i++ ){
		scanf("%s%s%d", g1, g2, &weight);
		V1 = toVertex(g1);
		V2 = toVertex(g2);
		G[V1][V2] = G[V2][V1] = weight;
	}
	int ansMin = -1, ansD = INF;
	int index = -1;
	for( int m = N+1; m <= Nv; m++ )
	{
		int Min = INF, D = 0;
		double Arg;
		memset(visit, false, 1015);
		Dijkstra(m);
		
		for( int i = 1; i <= N; i++ ){
			if( dis[i] > DS ){
				Min = -1;
				break;
			} else if( dis[i] < Min )
				Min = dis[i];
			D += dis[i];
		}
		if( Min == -1 ) continue;
		if( Min > ansMin ){
			ansMin = Min;
			ansD = D;
			index = m;
		} else if ( Min == ansMin && D < ansD ){
			ansD = D;
			index = m;
		}
	}
	
	if( ansMin == -1 )
		printf("No Solution\n");
	else{
		printf("G%d\n%.1f %.1f\n", index-N, (double)ansMin, 1.0*ansD/N); 
	}
}
