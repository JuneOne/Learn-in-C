#include <stdio.h>
#include <stdlib.h>

void Exchange( int *a, int *b )
{
	int temp;
	if( *a > *b ){
		temp = *a;
		*a = *b;
		*b = temp;
	}
}
int main(int argc, char const *argv[])
{
	int i, N, M;
	int a, b;
	int *distance;
	int dis;
	int sum = 0;
	int d;

	scanf("%d", &N);
	distance = (int*)malloc(sizeof(int) * (N+1));
	distance[1] = 0;

	for( i = 2; i <= N; i++ ){	
		scanf("%d", &dis);
		distance[i] = distance[i-1] + dis;
		sum += dis;
	}
	scanf("%d", &dis);
	sum += dis;

	scanf("%d", &M);
	while( M-- ){
		scanf("%d%d", &a, &b);
		Exchange(&a, &b);
		d = distance[b] - distance[a];
		if( sum - d < d )
			d = sum - d;
		printf("%d\n", d);
	}

	return 0;
}