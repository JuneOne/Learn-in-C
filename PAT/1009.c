#include <stdio.h>

double a[1001];
double b[1001];
double c[2001];

int main()
{
	int i, j, K1, K2, exp;
	// int maxe1, maxe2;
	int cnt = 0;
	scanf("%d", &K1);
	while( K1-- )
	{
		scanf("%d", &exp);
		scanf("%lf", &a[exp]);
		// printf("%f\n", a[exp]);
	}
	scanf("%d", &K2);
	while( K2-- )
	{
		scanf("%d", &exp);
		scanf("%lf", &b[exp]);
		// printf("%f\n", b[exp]);
	}

	for( i = 0; i < 1001; i++ ){
		if( a[i] != 0 ){
			for( j = 0; j < 1001; j++ ){
				if( b[j] != 0 ){
					c[i+j] += a[i]*b[j];
					// printf("c[%d+%d] = %f\n", i, j, c[i+j]);
				}
			}

		}
	}

	for( i = 0; i < 2001; i++ )
		if( c[i] != 0 )
			cnt++;
	printf("%d", cnt);
	for( i = 2000; i >= 0; i-- )
		if( c[i] != 0 )
			printf(" %d %.1f", i, c[i]);
	printf("\n");

	return 0;
	
}