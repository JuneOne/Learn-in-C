#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int main()
{
	int N, M, K;
	scanf("%d", &N);
	set<int> S[N];
	for( int i = 0; i < N; i++ )
	{
		scanf("%d", &M);
		while( M-- ){
			int number;
			scanf("%d", &number);
			S[i].insert(number);	
		}
	}
	scanf("%d", &K);
	while( K-- )
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		int same = 0, num2 = S[b].size();
		for( set<int>::iterator it = S[a].begin(); it != S[a].end(); it++ ){
			if( S[b].find(*it) != S[b].end() )
				same++;
			else
				num2++; 
		}
		printf("%.1f%\n", 1.0*same/num2 * 100);
	}
}
