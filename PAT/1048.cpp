#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int dest[100000];

int N, M;
int Lmax;
bool flag = false;

void FindRight( int index, int C[] )
{
	int right = Lmax;
	int left = index;
	int D = M - C[left];
	left++;
//	cout << left << " " << right << endl;
	while( left <= right )
	{
		int mid = (left+right)/2;
		if( C[mid] > D ){
			right = mid - 1;
		} else if ( C[mid] < D ) {
			left = mid + 1;
		} else {
			flag = true;
			dest[index] = mid;
			break;
		}

	}
	
}

int main()
{
	scanf("%d%d", &N, &M);
	int Coin[N];
	for( int i = 0; i < N; i++ )
		scanf("%d", &Coin[i]);
	sort(Coin, Coin+N);
	Lmax = N-1; // 注意初始化为最后一个数咯 
	for( int i = 0; i < N; i++ )
		if( Coin[i] >= M ){
			Lmax = i;
			break;
		}
	for( int i = 0; i < N; i++ )
		FindRight(i, Coin);
	if( flag == false )
		printf("No Solution\n");
	else{
		for( int i = 0; i < N; i++ ){
			if( dest[i] != 0 ){
				printf("%d %d\n", Coin[i], Coin[dest[i]]);
				break;
			}
		}
	}
}
