#include <stdio.h>

#define MAX 1000000
#define Null -1

struct node{
	char c;
	int next;
	int flag;
}List[MAX];

int main()
{
	int i, index, IsFound = 0;
	int start1, start2, N;
	scanf("%d%d%d", &start1, &start2, &N);
	for( i = 0; i < N; i++ ){
		scanf("%d ", &index);   //要有空格 
		scanf("%c %d", &List[index].c, &List[index].next);
		List[index].flag = 0;
	}
	
	while( start1 != Null ) // 一开始写成List[start1].next != -1, 有问题，因为有可能是空的，即输入是-1,-1,0，就死循环了。 
	{
		List[start1].flag = 1;
		start1 = List[start1].next;
	}
	while( start2 != Null )
	{
		if(	List[start2].flag == 1 ){
			printf("%05d\n", start2); //记得补全0 
			IsFound = 1;
			break;
		}
		start2 = List[start2].next;
	}
	if( IsFound == 0 )
		printf("-1\n");
	return 0;
} 
