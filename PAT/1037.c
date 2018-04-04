#include <stdio.h>
#include <stdlib.h>

int Coup[100000], Prod[100000];

int cmp( const void *a, const void *b )
{
	return (*(int*)a > *(int*)b);
}

int main()
{
	int i, j;
	int NC, NP;
	int sum = 0;
	int result;
	scanf("%d", &NC);
	for( i = 0; i < NC; i++ )
		scanf("%d", &Coup[i]);
	scanf("%d", &NP);
	for( i = 0; i < NP; i++ )
		scanf("%d", &Prod[i]);
		
	qsort(Coup, NC, sizeof(Coup[0]), cmp);
	qsort(Prod, NP, sizeof(Prod[0]), cmp);
	
	for( i = 0; Coup[i] < 0 && Prod[i] < 0 && i < NC && i < NP; i++ )
		sum += Coup[i]*Prod[i];
		
	for( i = NC-1, j = NP-1; Coup[i] > 0 && Prod[j] > 0 && i >= 0 && j >= 0; i--, j-- )
		sum += Coup[i]*Prod[j];
		
	printf("%d\n", sum);
	
	return 0;
}
