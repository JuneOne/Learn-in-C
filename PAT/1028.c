#include <stdio.h>
#include <stdlib.h>

struct node{
	int ID;
	char name[10];
	int grade;
}stu[100000];

int cmp1( const void *a, const void *b )
{
	struct node *aa = (struct node *)a;
	struct node *bb = (struct node *)b;
	
	return (aa->ID > bb->ID);
}

int cmp2( const void *a, const void *b )
{
	struct node *aa = (struct node *)a;
	struct node *bb = (struct node *)b;
	
	if( strcmp(aa->name, bb->name) == 0 )
		return (aa->ID > bb->ID);
	else
		return strcmp(aa->name, bb->name);
}

int cmp3( const void *a, const void *b )
{
	struct node *aa = (struct node *)a;
	struct node *bb = (struct node *)b;
	if( aa->grade == bb->grade )
		return (aa->ID > bb->ID);
	else
		return (aa->grade > bb->grade);
}

int main()
{
	int i, N, C;
	scanf("%d%d", &N, &C);
	for( i = 0; i < N; i++ )
		scanf("%d%s%d", &stu[i].ID, stu[i].name, &stu[i].grade);
	switch(C){
		case 1: qsort(stu, N, sizeof(stu[0]), cmp1); break;
		case 2: qsort(stu, N, sizeof(stu[0]), cmp2); break;
		case 3: qsort(stu, N, sizeof(stu[0]), cmp3); break;
	}
	for( i = 0; i < N; i++ )
		printf("%06d %s %d\n", stu[i].ID, stu[i].name, stu[i].grade);
		
	return 0;
}
