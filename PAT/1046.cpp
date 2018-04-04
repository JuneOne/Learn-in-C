#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
	int Nv, Ne, K;
	int V1, V2;
	scanf("%d%d", &Nv, &Ne);
	vector<int> G[Nv+1];
	vector<int> Ind(Nv+1);
	
	for( int i = 0; i < Ne; i++ )
	{
		scanf("%d%d", &V1, &V2);
		G[V1].push_back(V2);
		Ind[V2]++;
	}

	scanf("%d", &K);
	vector<int> query;
	for( int i = 0; i < K; i++ ){
		vector<int> I2(Ind);		
		int flag = true;
		for( int j = 0; j < Nv; j++ ){
			int p;
			scanf("%d", &p);
			if( I2[p] != 0 ){
				if( flag ){
					query.push_back(i);
					flag = false;
				}
			} else if( flag ){
				for( int k = 0; k < G[p].size(); k++ )
					I2[G[p][k]]--;
			}
		}
	}
	printf("%d", query[0]);
	for( int i = 1; i < query.size(); i++ )
		printf(" %d", query[i]);
	printf("\n");
	
	return 0;
}
