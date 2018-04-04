#include <stdio.h>

int main()
{
	int i, j, len = 0;
	int n1, n2;
	char str[1000];
	scanf("%s", str);
	while( str[len] != '\0')
		len++;
	// printf("%d\n", len);
	if( ( len + 2 ) % 3 == 0 )
		n1 = n2 = ( len + 2 ) / 3;
	else if ( ( len + 2 ) % 3 == 1 ){
		n2 = ( len + 2 ) / 3 + 1;
		n1 = ( len + 2 - n2 ) / 2;
	} else {
		n2 = ( len + 2 ) / 3 + 2;
		n1 = ( len + 2 - n2 ) / 2;
	}
	for( i = 0; i < n1-1; i++ ){
		printf("%c", str[i]);
		for( j = 0; j < n2 - 2; j++ )
			putchar(' ');
		printf("%c\n", str[len-i-1]);
	}
	for( i = n1-1; i < n1 + n2 - 1; i++ )
		printf("%c", str[i]);

	return 0;
}