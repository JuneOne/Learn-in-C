#include <stdio.h>
#include <vector>
#include <memory.h>

#define INF 0x7fffffff

using namespace std;

vector<int> Vdis, Vtime;

int Gd[501][501], Gt[501][501], Nv, Ne;
int dis[501];
int tim[501];
int cnt[501];
int path[501];
bool visit[501];

void Print( int e, vector<int> &V)
{
	while( path[e] != -1 ){
		V.push_back(e);
		e = path[e];
	}
}

void DijkstraD( int S )
{
	for( int i = 0; i < Nv; i++ ){
		dis[i] = Gd[S][i];
		tim[i] = Gt[S][i];
		path[i] = -1;
		if( Gd[S][i] < INF )
			path[i] = S;
	}
	dis[S] = 0;
	tim[S] = 0;
	visit[S] = true;
	
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
			if( !visit[i] && Gd[Min][i] < INF ){
				if( dis[i] > dis[Min] + Gd[Min][i] ){
					dis[i] = dis[Min] + Gd[Min][i];
					tim[i] = tim[Min] + Gt[Min][i];
					path[i] = Min;
				} else if ( dis[i] == dis[Min] + Gd[Min][i] ){
					if( tim[i] > tim[Min] + Gt[Min][i] ){
						tim[i] = tim[Min] + Gt[Min][i];
						path[i] = Min;
					}
				}
			}
		}
	}
}

void DijkstraT( int S )
{
	for( int i = 0; i < Nv; i++ ){
		tim[i] = Gt[S][i];
		path[i] = -1;
		if( Gt[S][i] < INF ){
			cnt[i] = 1;
			path[i] = S;
		}
	}
	tim[S] = 0;
	cnt[S] = 0;
	visit[S] = true;
	
	while(1)
	{
		int Min, MinDist = INF;
		for( int i = 0; i < Nv; i++ )
			if( !visit[i] && tim[i] < MinDist ){
				MinDist = tim[i];
				Min = i;
			}
		if( MinDist == INF ) break;
		visit[Min] = true;
		for( int i = 0; i < Nv; i++ ){
			if( !visit[i] && Gt[Min][i] < INF ){
				if( tim[i] > tim[Min] + Gt[Min][i] ){
					tim[i] = tim[Min] + Gt[Min][i];
					cnt[i] = cnt[Min] + 1;
					path[i] = Min;
				} else if( tim[i] == tim[Min] + Gt[Min][i] ) {
					if( cnt[i] > cnt[Min] + 1 ){
						cnt[i] = cnt[Min] + 1;
						path[i] = Min;
					}
				}
			}
		}
	}
	
}

int main()
{
	int V1, V2, IsOne, dist, time;
	int start, end;
	bool IsSame = true;
	scanf("%d%d", &Nv, &Ne);
	for( int i = 0; i < Nv; i++ )
		for( int j = 0; j < Nv; j++ ){
			Gd[i][j] = INF;
			Gt[i][j] = INF;
		}
	for( int i = 0; i < Ne; i++ )
	{
		scanf("%d%d%d%d%d", &V1, &V2, &IsOne, &dist, &time);
		if( IsOne == 1 ){
			Gd[V1][V2] = dist;
			Gt[V1][V2] = time;
		} else {
			Gd[V1][V2] = Gd[V2][V1] = dist;
			Gt[V1][V2] = Gt[V2][V1] = time;
		}
	}
	scanf("%d%d", &start, &end);	
	DijkstraD(start);
	Print(end, Vdis);

	memset(visit, false, 501);
	DijkstraT(start);
	Print(end, Vtime);

	if( Vdis.size() != Vtime.size() )
		IsSame = false;
	else {
		for( int i = 0; i < Vdis.size(); i++ ){
			if( Vdis[i] != Vtime[i] ){
				IsSame = false;
				break;
			}
		}
	}
	if( IsSame == false ){
		printf("Distance = %d: %d", dis[end], start);
		for( int i = Vdis.size()-1; i >= 0; i-- )
			printf(" -> %d", Vdis[i]);
		printf("\n");
		printf("Time = %d: %d", tim[end], start);
		for( int i = Vtime.size()-1; i >= 0; i-- )
			printf(" -> %d", Vtime[i]);
		printf("\n");	
	} else {
		printf("Distance = %d; Time = %d: %d", dis[end], tim[end], start);
		for( int i = Vdis.size()-1; i >= 0; i-- )
			printf(" -> %d", Vdis[i]);
		printf("\n");
	}
	
	return 0;
}
