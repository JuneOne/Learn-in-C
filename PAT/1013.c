#include <stdio.h>

#define MAXN 1000

int G[MAXN][MAXN], Nv, Ne;
int visit[MAXN];

void dfs( int v )
{
	int i;
	visit[v] = 1;
	for( i = 0; i < Nv; i++ )
	{
		if( visit[i] == 0 && G[i][v] == 1 )
			dfs(i);
	}
}

int main()
{
	int i, K, v1, v2, city;
	int cnt;
	scanf("%d%d%d", &Nv, &Ne, &K);
	for( i = 0; i < Ne; i++ )
	{
		scanf("%d%d", &v1, &v2);
		v1--; v2--;
		G[v1][v2] = G[v2][v1] = 1;
	}
	while( K-- )
	{
		cnt = 0;
		scanf("%d", &city);
		city--;
		for( i = 0; i < Nv; i++ )
			visit[i] = 0;
		visit[city] = 1;
		for( i = 0; i < Nv; i++ )
		{
			if( visit[i] == 0 )
			{
				dfs(i);
				cnt++;
			}
		}
		printf("%d\n", cnt-1);
	}

	return 0;
}