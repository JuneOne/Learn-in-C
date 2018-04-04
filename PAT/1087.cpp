#include <stdio.h>
#include <map>
#include <string.h>
#include <iostream>

#define INF 0x7fffffff

using namespace std;

int G[205][205], happy[205], Nv, Ne;
int dis[205];	 
int ha[205];
int cnt[205];	// 路径数 
int vnum[205];  // 顶点数
int path[205];
bool visit[205];

map<string, int> m1;
map<int, string> m2;

void Dijkstra( int S )
{
	for( int i = 0; i < Nv; i++ ){
		dis[i] = G[S][i];
		path[i] = -1;
		if( G[S][i] != INF ){
			ha[i] = happy[i];
			cnt[i] = 1;
			vnum[i] = 1;
			path[i] = S;
		}
	}
	
	visit[S] = true;
	dis[S] = 0;
	ha[S] = 0;
	cnt[S] = 1;
	
	while(1)
	{
		int Min, MinDist = INF;
		for( int i = 0; i < Nv; i++ ){
			if( !visit[i] && dis[i] < MinDist ){
				Min = i;
				MinDist = dis[i];
			}
		}
		if( MinDist == INF ) break;
		visit[Min] = true;
		
		for( int i = 0; i < Nv; i++ ){
			if( !visit[i] && G[Min][i] < INF ){
				if( dis[i] > dis[Min] + G[Min][i] ){
					dis[i] = dis[Min] + G[Min][i];
					path[i] = Min;
					cnt[i] = cnt[Min];
					vnum[i] = vnum[Min] + 1;
					ha[i] = ha[Min] + happy[i];
				} else if( dis[i] == dis[Min] + G[Min][i] ){
					cnt[i] += cnt[Min];
					if( ha[Min] + happy[i] > ha[i] ){
						ha[i] = ha[Min] + happy[i];
						path[i] = Min;
						vnum[i] = vnum[Min] + 1;
					} else if( ha[Min] + happy[i] == ha[i] ){
						if( vnum[i] > vnum[Min] + 1 ){
							path[i] = Min;
							vnum[i] = vnum[Min] + 1;
						}
					}
				}
			}
		}
	}
}

void Print( int e )
{
	if( path[e] != 0 )
		Print(path[e]);
	printf("->%s", m2[e].c_str());
}

int main()
{
	int happiness;
	char cname[4];
	scanf("%d%d%s", &Nv, &Ne, cname);
	string start(cname);
	m1[start] = 0;
	m2[0] = start;
	for( int i = 1; i < Nv; i++ ){
		scanf("%s%d", cname, &happiness);
		string city(cname);
		m1[city] = i;
		m2[i] = city;
		happy[i] = happiness;
	}
	for( int i = 0; i < Nv; i++ )
		for( int j = 0; j < Nv; j++ )
			G[i][j] = INF;
	for( int i = 0; i < Ne; i++ )
	{
		int V1, V2, cost;
		char c1[4], c2[4];
		scanf("%s%s%d", c1, c2, &cost);
		string city1(c1), city2(c2);
		V1 = m1[city1]; V2 = m1[city2];
		G[V1][V2] = G[V2][V1] = cost;
	}
	Dijkstra(0);

	int end = m1["ROM"];

	printf("%d %d %d %d\n", cnt[end], dis[end], ha[end], (int)(1.0*ha[end]/vnum[end]));
	printf("%s", start.c_str());
	Print(end);
	printf("\n");
	
	return 0;
}
