#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
	int Nv, Ne, K;
	scanf("%d%d", &Nv, &Ne);
	vector<int> V[Nv];
	bool Find[Ne];
	for( int i = 0; i < Ne; i++ ){
		int V1, V2;
		scanf("%d%d", &V1, &V2);
		V[V1].push_back(i);
		V[V2].push_back(i);
	}
	scanf("%d", &K);
	while( K-- )
	{
		int N;
		scanf("%d", &N);
		for( int i = 0; i < Ne; i++ )
			Find[i] = false;
		while( N-- ){
			int vertex;
			scanf("%d", &vertex);
			for( vector<int>::iterator it = V[vertex].begin(); it != V[vertex].end(); it++ )
				Find[*it] = true;
		}
		bool IsSet = true;
		for( int i = 0; i < Ne; i++ )
			if( Find[i] == false ){
				IsSet = false;
				printf("No\n");
				break;
			}
		if( IsSet )
			printf("Yes\n");
	}
}
