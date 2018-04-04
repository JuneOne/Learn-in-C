#include <stdio.h>
#include <stdlib.h>

typedef struct color Color;
struct color
{
	int value;
	int cnt;
};

int main()
{
	Color **a;
	int i, j, M, N;
	scanf("%d%d", &M, &N);
	a = (Color**)malloc(sizeof(struct color *) * N);
	// for( i = 0; i < N; i++ )
	// 	a[i] = (Color*)malloc(sizeof(struct color) * M);
	// for( i = 0; i < N; i++ )
	// 	for( j = 0; j < M; j++ )
	// 		scanf("%d", &a[i][j].value);
	
	// for( i = 0; i < N; i++ ){
	// 	for( j = 0; j < M; j++ )
	// 		printf("%d ", a[i][j].value);	
	// 	printf("\n");
	// }

}