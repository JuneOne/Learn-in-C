#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX 2500
struct node{
	int num;
	char **name;
}List[MAX];

int course[MAX];

int main()
{
	int i, j, p, N, K;
	int index, number;
	scanf("%d%d", &N, &K);
	for( j = 0; j < K; j++)
	{
		scanf("%d", &index);
		scanf("%d", &number);
		getchar();
		List[index].num = number;
		List[index].name = (char**)malloc(sizeof(char*)*number);
		for( i = 0; i < number; i++ ){
			List[index].name[i] = (char*)malloc(sizeof(char)*5);
			scanf("%s", List[index].name[i]);
		}
	}
	for( i = 0; i < N; i++ )
	{
		char stu[5];
		int cnt = 0;
		scanf("%s", stu);
		memset(course, 0, MAX);
		for( j = 1; j <= K; j++ ){
			for( p = 0; p < List[j].num; p++ ){
				if( strcmp( List[j].name[p], stu ) == 0 ){
					course[cnt++] = j;
					break;
				}
			}
		}
		printf("%s %d", stu, cnt);
		for( j = 0; j < cnt; j++ )
			printf(" %d", course[j]);
		printf("\n");
	}
//	for( i = 1; i <= K; i++ ){
//		for( j = 0; j < List[i].num; j++ )
//			printf("%s ", List[i].name[j]);
//		printf("\n");
//	}
}
