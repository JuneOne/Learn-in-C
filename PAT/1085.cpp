#include <cstdio>
#include <algorithm>

using namespace std;

int Seq[10005];
int N, p;

int FindMax( int start )
{
	int left = start;
	int right = N-1;
	int mid;
	while( left <= right )
	{
		mid = (left+right) / 2;
		if( Seq[mid] > Seq[start]*p ){
			right = mid-1;
		} else if( Seq[mid] < Seq[start]*p){
			left = mid + 1;
		} else {
			left = mid + 1;
			break;
		}
	}
	
	return left;	
}

int main()
{
	scanf("%d%d", &N, &p);
	for( int i = 0; i < N; i++ )
		scanf("%d", &Seq[i]);
	sort(Seq, Seq+N);
	int max = 0, temp;
	for( int i = 0; i < N ; i++ ){
		temp = FindMax(i)-i;
		if( temp > max )
			max = temp;
	}
	
	printf("%d\n", max);
	
	return 0;
		
}
