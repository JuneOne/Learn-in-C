#include <stdio.h>

int IsPalindromic( int *a, int len )
{
	int i;
	for( i = 0; i < len / 2; i++ )
		if( a[i] != a[len-1-i] )
			return 0;
	for( i = 0; i < len; i++ )
		printf("%d", a[i]);
	printf(" is a palindromic number.\n");
	return 1;
}

int Add( int *a, int len )
{
	int i, j;
	int b[10000];
	int c[10000] = {0};
	for( i = 0; i < len; i++ ){
		printf("%d", a[i]);
		b[len-1-i] = a[i];
	}
	printf(" + ");
	for( i = 0; i < len; i++ )
		printf("%d", b[i]);
	printf(" = ");

	for( i = len-1, j = 0; i >= 0; i--, j++ )
	{
		// printf("i=%d,j=%d\n", i, j);
		c[j] += a[i] + b[i];
		if( c[j] > 9 ){
			c[j+1]++;
			c[j] -= 10;
		}
	}

	// printf("c[j]=%d", c[j]);
	if( c[j] > 0 )
		len = j+1;
	else
		len = j;
	for( i = 0; i < len; i++ ){
		a[i] = c[len-1-i];
		printf("%d", a[i]);
	}

	printf("\n");
	
	return len;
}

int main()
{
	int i;
	int a[10000];
	char ch;
	int len = 0;
	int cnt = 0;
	while( (ch=getchar()) != '\n' )
		a[len++] = ch - '0';
	while( IsPalindromic(a, len) != 1 )
	{
		len = Add(a, len);
		cnt++;
		if( cnt > 9 ){
			printf("Not found in 10 iterations.\n");
			break;
		}

	}
}