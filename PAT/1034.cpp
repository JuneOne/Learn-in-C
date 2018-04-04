#include <stdio.h>
#include <map>
#include <iostream>

using namespace std;

map<string, int> m1;
map<int, string> m2;
map<string, int> ans;

int Nv = 0;
int G[2005][2005], W[2005]; // 1000条边，可能有2000个顶点 
bool visit[1001];
int cnt, total, head;

int stoif( string s )
{
	if( m1[s] == 0 ){
		m1[s] = ++Nv;
		m2[Nv] = s;
		return Nv;
	} else 
		return m1[s];
}

void dfs(int S)
{
	visit[S] = true;
	cnt++;
	if( W[S] > W[head] )
		head = S;
	for( int i = 1; i <= Nv; i++ ){
		if( G[S][i] > 0 ){ // 可能会有环的 
			total += G[S][i];
			G[S][i] = G[i][S] = 0;
			if( !visit[i] )
				dfs(i);
		}
	}
}

int main()
{
	int Ne, K;
	char name1[4], name2[4];
	int V1, V2, time;
	scanf("%d%d", &Ne, &K);
	for( int i = 0; i < Ne; i++ )
	{
		scanf("%s%s%d", name1, name2, &time);
		string s1(name1), s2(name2);
		V1 = stoif(s1);
		V2 = stoif(s2);
		G[V1][V2] += time;
		G[V2][V1] += time;
		W[V1] += time;
		W[V2] += time;
	}
	for( int i = 1; i <= Nv; i++ ){
		if( !visit[i] )
		{
			head = i, cnt = 0, total = 0;
			dfs(i);
//			cout << "head = " << i << "cnt = " << cnt << "total = " << total << endl;
			if( total > K && cnt > 2 )
				ans.insert(pair<string, int>(m2[head], cnt));
		}
	}

	printf("%d\n", ans.size());
	for( map<string, int>::iterator it = ans.begin(); it != ans.end(); it++ ){
		printf("%s %d\n", it->first.c_str(), it->second);
	}
	
	return 0;
}
