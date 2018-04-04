#include <stdio.h>
#include <stdlib.h>

int choose[1000];
int cnt = 0;
char **str;

int IsChoose( char c[] )
{
	int i;
	for( i = 0; i < cnt; i++ ){
		if( strcmp(str[choose[i]], c) == 0 )
			return 1;
	}
	return 0;
}

int main()
{
	int i, j, M, N, S;

	scanf("%d%d%d", &M, &N, &S);
	str = (char**)malloc(sizeof(char*)*(M+1));
	for( i = 1; i <= M; i++ )
		str[i] = (char*)malloc(sizeof(char)*21);
	for( i = 1; i <= M; i++ )
		scanf("%s", str[i]);
	if( S > M )
		printf("Keep going...\n");
	else{
		for( i = S; i <= M; i += N )
		{
			if( IsChoose(str[i]) ){
				i = i - N + 1;
			} else {
				printf("%s\n", str[i]);
				choose[cnt++] = i;
			}
		}
	}
}