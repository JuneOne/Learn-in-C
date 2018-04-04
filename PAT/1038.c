#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char Num[10000][9];

int cmp( const void *a, const void *b )
{
	char temp1[20], temp2[20];
	strcpy(temp1, (char*)a);
	strcpy(temp2, (char*)b);
	strcat(temp1, (char*)b);
	strcat(temp2, (char*)a);
	return strcmp(temp1, temp2);	
}

int main()
{
	int i, j, N;
	scanf("%d", &N);
	for( i = 0; i < N; i++ )
		scanf("%s", Num[i]);
	qsort(Num, N, sizeof(Num[0]),cmp);
	i = 0, j = 0;
	while(i < N){
		while( Num[i][j] == '0' )
			j++;
		if( Num[i][j] == '\0' ){
			i++;
			j = 0;
			continue;
		}
//		printf("i = %d, j = %d\n", i, j);
		if( Num[i][j] != '\0' )
			break;
	}
	if( i == N )
		printf("0\n");
	else{
		printf("%s", Num[i]+j);
		i++;
		for( ; i < N; i++ )
			printf("%s", Num[i]);
		printf("\n");
	}

}
