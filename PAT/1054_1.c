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
	Color *a;
	int i, j, M, N;
	int x;
	scanf("%d%d", &M, &N);
	int k = 0;
	int len = 0;

	a = (Color*)malloc(sizeof(struct color) * M * N);
	for( i = 0; i < M*N; i++ )
	{
		a[i].value = -1;
		a[i]. cnt = 0;
	}

	for( i = 0; i < N; i++ ){
		for( j = 0; j < M; j++ ){
			scanf("%d", &x);
			for( k = 0; k < len; k++){
				if( a[k].value == x ){
					a[k].cnt++;
					break;
				}
			}
			if( k == len ){
				a[len].value = x;
				a[len].cnt = 1;
				len++;
			}
		}
	}
	for( k = 0; k < len; k++ ){
		// printf("%d:%d\n", a[k].value, a[k].cnt);
		if( a[k].cnt > M*N/2 )
			printf("%d\n", a[k].value);
	}

	return 0;
}