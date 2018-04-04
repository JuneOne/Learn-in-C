#include <stdio.h>

char s2[10000];

int IsFound( char c )
{
	int i;
	for( i = 0; s2[i] != '\0'; i++ ){
		if( s2[i] == c )
			return 1;
	}
	return 0;
}
int main()
{
	int i, j;
	char s1[10000];
	char c;
	i = j = 0;
	while( (c = getchar()) != '\n' ){
		s1[i++] = c;
	}
	s1[i] = '\0';
	while( (c = getchar()) != '\n' ){
		s2[j++] = c;
	}
	s2[j] = '\0';
	// scanf("%s", s2);
	for( i = 0; s1[i] != '\0'; i++ ){
		if( IsFound(s1[i]) )
			continue;
		else
			printf("%c", s1[i]);
	}

	return 0;
}