#include <stdio.h>

int a[11];
int b[11];
int len;

int IsPalindromic()
{
	int i;
	for( i = 0; i < len/2; i++ )
		if( a[i] != a[len-1-i] )
			return 0;
	return 1;
}

// void Add()
// {

// }

int main()
{
	char c;
	int i, Max;
	int step = 0;
	while( (c=getchar()) != ' ' )
		a[len++] = c - '0';
	printf("%d", IsPalindromic());
	// scanf("%d", &Max);
	// while( IsPalindromic() != 1 )
	// {
	// 	Add();
	// 	step++;
	// 	if( step > Max )
	// 		break;
	// }
	// for( i = 0; i < len; i++ )
	// 	printf("%d", a[i]);
	// printf("\n");
	// if( step > Max )
	// 	printf("%d\n", Max);
	// else
	// 	printf("%d\n", step);

	return 0;
}