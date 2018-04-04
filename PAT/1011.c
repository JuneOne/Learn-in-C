#include <stdio.h>

#define N 3

int main()
{
	int i;
	double W, T, L;
	double profit = 1.0;
	for( i = 0; i < N; i++ ){
		scanf("%lf%lf%lf", &W, &T, &L);
		if( W < T ){
			if( T < L ){
				printf("%c ", 'L');
				profit *= L;
			} else {
				printf("%c ", 'T');
				profit *= T;
			}
		} else {
			if( T > L ){
				printf("%c ", 'W');
				profit *= W;
			} else {
				if( W > L ){
					printf("%c ", 'W');
					profit *= W;
				} else {
					printf("%c ", 'L');
					profit *= L;
				}
			}
		}
	}

	profit = (profit*0.65-1)*2;
	// profit = profit*100 + 0.5;
	printf("%.2f\n",profit);
}