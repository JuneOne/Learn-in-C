#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

struct node{
	double amount;
	double price;
}Moon[MAX];

int cmp( const void *a, const void *b )
{
	struct node *aa = (struct node *)a;
	struct node *bb = (struct node *)b;

	return ((1.0*aa->price/aa->amount < 1.0*bb->price/bb->amount)? 1:-1);
}

int main()
{
	int i, N, D;
	// int best[1001];
	scanf("%d%d", &N, &D);
	for( i = 0; i < N; i++ )
		scanf("%lf", &Moon[i].amount);
	for( i = 0; i < N; i++ )
		scanf("%lf", &Moon[i].price);
	qsort(Moon, N, sizeof(Moon[0]), cmp);
	// for( i = 0; i < N; i++ )
	// 	printf("%d ", Moon[i].amount);
	double profit = 0.0;
	for( i = 0; i < N; i++ )
	{
		if( D <= 0 ){
			break;
		} else {
			if( Moon[i].amount <= D ){
				profit += Moon[i].price;
				D -= Moon[i].amount;
			} else {
				profit += 1.0*D / Moon[i].amount * Moon[i].price;
				D = 0;
			}
		}
		// printf("amount = %d, price = %f, D = %d, profit = %f\n", Moon[i].amount, Moon[i].price, D, profit);
	}

	printf("%.2f\n", profit);

	return 0;

}