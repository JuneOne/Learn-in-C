#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 10000

struct node{
	char name[11];
	char ID[11];
	int grade;
}Boy[MAXN], Girl[MAXN];

int cmp1( const void *a, const void *b )
{
	struct node *aa = (struct node *)a;
	struct node *bb = (struct node *)b;
	return (aa->grade > bb->grade);
}

int cmp2( const void *a, const void *b )
{
	struct node *aa = (struct node *)a;
	struct node *bb = (struct node *)b;
	return (aa->grade < bb->grade);
}

int main()
{
	int i, N;
	int len1, len2;
	char str1[11], str2[11];
	int grade;
	char Sex;
	len1 = len2 = 0;
	scanf("%d", &N);
	getchar();
	for( i = 0; i < N; i++ )
	{
		scanf("%s %c %s %d", str1, &Sex, str2, &grade);
		if( Sex == 'M' ){
			strcpy(Boy[len1].name, str1);
			strcpy(Boy[len1].ID, str2);
			Boy[len1].grade = grade;
			len1++;
		} else if( Sex == 'F' ) {
			strcpy(Girl[len2].name, str1);
			strcpy(Girl[len2].ID, str2);
			Girl[len2].grade = grade;
			len2++;			
		}
	}
	qsort(Boy,len1,sizeof(Boy[0]), cmp1);
	qsort(Girl,len2,sizeof(Girl[0]),cmp2);
	if( len1 != 0 && len2 != 0 ){
		printf("%s %s\n", Girl[0].name, Girl[0].ID);
		printf("%s %s\n", Boy[0].name, Boy[0].ID);
		printf("%d\n", Girl[0].grade-Boy[0].grade);
	} else if ( len1 == 0 && len2 != 0 ){
		printf("%s %s\n", Girl[0].name, Girl[0].ID);
		printf("Absent\nNA\n");	
	} else if ( len1 != 0 && len2 == 0 ){
		printf("Absent\n");
		printf("%s %s\n", Boy[0].name, Boy[0].ID);
		printf("NA\n");		
	} else {
		printf("Absent\nAbsent\nNA\n");
	}
//	printf("Boy:\n");
//	for( i = 0; i < len1; i++ )
//		printf("%s %s %d\n", Boy[i].name, Boy[i].ID, Boy[i].grade);
//	printf("Girl:\n");
//	for( i = 0; i < len2; i++ )
//		printf("%s %s %d\n", Girl[i].name, Girl[i].ID, Girl[i].grade);

}
