#include <stdio.h>

int a[10000];
int b[10000];
int len;

void Add()
{
	int i, j;
	int c[10000] = {0};
	for( i = 0; i < len; i++ )
		b[len-1-i] = a[i];
	for( i = len-1, j = 0; i >= 0; i--, j++ )
	{
		c[j] += a[i] + b[i];
		if( c[j] > 9 ){
			c[j] -= 10;
			c[j+1]++;
		}
	}
	if( c[j] > 0 )
		len++;
	for( i = 0; i < len; i++ )
		a[i] = c[len-1-i];
}

int IsPalindromic()
{
	int i;
	for( i = 0; i < len; i++ )
		if( a[i] != a[len-1-i] ){
			Add();
			return 0;
		}
	return 1;
}

int main()
{
	char c;
	int i, j, Max;

	while( (c=getchar()) != ' ' )
		a[len++] = c - '0';
	scanf("%d", &Max);
	for( i = 0; i < Max; i++ )
		if( IsPalindromic() == 1 )
			break;
	for( j = 0; j < len; j++ )
		printf("%d", a[j]);
	printf("\n%d\n", i);

	return 0;
}