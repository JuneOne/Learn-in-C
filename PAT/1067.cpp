#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	int N, number;
	scanf("%d", &N);
	int pos[N];
	for( int i = 0; i < N; i++ ){
		scanf("%d", &number);
		pos[number] = i;
	}
	int nosort = N-1;
	for( int i = 1; i < N; i++ )
		if( pos[i] == i )
			nosort--;
	int cnt = 0;
	int k = 1;
	while( nosort > 0 ){
		while( pos[0] != 0 ){
			int temp = pos[0];
			pos[0] = pos[temp];
			pos[temp] = temp;
			cnt++;
			nosort--;
		}
		if( nosort != 0 ){
			for( int i = k; i < N; i++ ){
				if( pos[i] != i ){
					k = i+1;
					pos[0] = pos[i];
					pos[i] = 0;
					cnt++;
					break;
				}
			}
		}
	}
	
	printf("%d\n", cnt);
	
}
