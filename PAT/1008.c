#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, N;
	int* floor;
	int total = 0;

	scanf("%d", &N);
	floor = (int*)malloc(sizeof(int)*N);
	for( i = 0; i < N; i++ )
		scanf("%d", &floor[i]);

	total += floor[0]*6 + 5;

	for( i = 1; i < N; i++ ){
		if( floor[i] > floor[i-1] ){
			total += (floor[i] - floor[i-1]) * 6;
		}
		if( floor[i] < floor[i-1] ){
			total += (floor[i-1] - floor[i]) * 4;
		}
		total += 5;
	}

	printf("%d\n", total);

	return 0;
}