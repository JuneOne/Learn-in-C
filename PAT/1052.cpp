#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node{
	int start;
	int value;
	int next;
};

bool cmp( struct Node a, struct Node b )
{
	return a.value < b.value;
}

int main()
{
	int N, start;
	scanf("%d %d", &N, &start);	
	Node L[100000], List[N];
	for( int i = 0; i < N; i++ )
	{
		int st, value, end;
		scanf("%d%d%d", &st, &value, &end);
		L[st].start = st;
		L[st].value = value;
		L[st].next = end;
	}
	int index = 0;
	while( start != -1 ) // 哇，还会有给坏的节点的吗？ 
	{
		List[index].start = L[start].start;
		List[index].value = L[start].value;
		List[index].next = L[start].next;
		start = L[start].next;
		index++;
	}
	sort(List, List+index, cmp);
	if( index == 0 )
		printf("0 -1\n");
	else{
		for( int i = 0; i < index-1; i++ )
			List[i].next = List[i+1].start;
		List[index-1].next = -1;
		printf("%d %05d\n", index, List[0].start);
		for( int i = 0; i < index-1; i++ )
			printf("%05d %d %05d\n", List[i].start, List[i].value, List[i].next);
		printf("%05d %d %d\n", List[index-1].start, List[index-1].value, List[index-1].next);	
	}
}
