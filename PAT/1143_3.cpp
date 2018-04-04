#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

map<int, bool> m;

int main()
{
	int M, N;
	int u, v, parent;
	scanf("%d%d", &M, &N);
	vector<int> pre(N);
	for( int i = 0; i < N; i++ ){
		scanf("%d", &pre[i]);
		m[pre[i]] = true;
	}
	for( int i = 0; i < M; i++ ) {
		scanf("%d%d", &u, &v);
		if( !m[u] && !m[v] )
			printf("ERROR: %d and %d are not found.\n", u, v);
		else if( !m[u] || !m[v] )
			printf("ERROR: %d is not found.\n", m[u] == false ? u:v);
		else{
			for( int j = 0; j < N; j++ ){
				parent = pre[j];
				if( parent >= u && parent <= v || parent <= u && parent >= v )
					break; 
			}
			if( parent == u || parent == v )
				printf("%d is an ancestor of %d.\n", parent, parent == u ? v:u);
			else
				printf("LCA of %d and %d is %d.\n", u, v, parent);				
		}
	}
}
