#include <stdio.h>
#include <stdlib.h>
long int a[2000000];
//long int b[1000000];

int cmp( const void *a, const void *b )
{
	return (*(int*)a > *(int*)b);
}

int main()
{
	long int i, j, N1, N2;
	scanf("%ld", &N1);
	for( i = 0; i < N1; i++ )
		scanf("%ld", &a[i]);
	scanf("%ld", &N2);
	for( j = 0; j < N2; j++ )
		scanf("%ld", &a[i++]);
	qsort(a, N1+N2, sizeof(a[0]), cmp);
	printf("%ld\n", a[(N1+N2-1)/2]);
	
	return 0;
}
