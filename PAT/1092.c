#include <stdio.h>

char s1[1000];
char s2[1000];

int Find( char c )
{
	int i;
	for( i = 0; s1[i] != '\0'; i++ ){
		if( s1[i] == c ){
			s1[i] = ' ';
			return 1;
		}
	}

	return -1;
}

int main()
{
	char c;
	int len1 = 0, len2 = 0;
	int i;
	int extra = 0, miss = 0;
	while( (c = getchar()) != '\n' )
		s1[len1++] = c;
	s1[len1] = '\0';
	while( (c = getchar()) != '\n' )
		s2[len2++] = c;
	s2[len2] = '\0';

	for( i = 0; s2[i] != '\0'; i++ ){
		if( Find(s2[i]) == -1 ){
			miss++;
		}
	}
	if( miss > 0 ){
		printf("No %d\n", miss);
	} else {
		printf("Yes %d\n", len1-len2);
	}
}