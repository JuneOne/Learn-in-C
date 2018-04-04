#include <stdio.h>
#include <stdlib.h>

// double *number;

int main()
{
	int i, j, N;
	double temp;
	double sum = 0.0;
	scanf("%d", &N);
	// number = (double*)malloc(sizeof(double)*N);
	// for( i = 0; i <= N; i++ )
	// 	number[i] = 0;
	for( i = 0; i < N; i++ ){
		scanf("%lf", &temp);
		sum += temp*(N-i)*(i+1);
	}
	// for( i = 1; i <= N; i++ )
	// 	for( j = i; j <= N; j++ )
	// 		sum += number[j] - number[i-1];

	printf("%.2f", sum);
}