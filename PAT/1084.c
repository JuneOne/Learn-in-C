#include <stdio.h>

char worn[37];
int cnt = 0;

int find( char c )
{
	int i;
	for( i = 0; i < cnt; i++ )
		if( worn[i] == c )
			return 1;

	return 0;
}

int main()
{
	int i, j;
	char str1[81];
	char str2[81];
	scanf("%s%s", str1, str2);
	for( i = 0; str1[i] != '\0'; i++ )
		if( str1[i] >= 'a' && str1[i] <= 'z' )
			str1[i] += 'A' - 'a';
	for( i = 0; str2[i] != '\0'; i++ )
		if( str2[i] >= 'a' && str2[i] <= 'z' )
			str2[i] += 'A' - 'a';
	for( i = 0, j = 0; str1[i] != '\0'; i++ ){
		if( find(str1[i]) )
			continue;
		else {
			if( str1[i] != str2[j] ){
				worn[cnt++] = str1[i];
				continue;
			} else {
				j++;
			}
		}
	}

	for( i = 0; i < cnt; i++ )
		putchar(worn[i]);
	putchar('\n');

	return 0;
}