#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
	int address;
	int data;
	int next;
}List[100000];

bool Num[10001];

int main()
{
	int start, N;
	scanf("%d%d", &start, &N);
	node Res[N], Del[N];
	int len1 = 0, len2 = 0;
	for( int i = 0; i < N; i++ ) {
		int st, value, next;
		scanf("%d%d%d", &st, &value, &next);
		List[st].address = st;
		List[st].data = value;
		List[st].next = next;
	} 
	while( start != -1 )
	{
		int key = abs(List[start].data);
		if( Num[key] == false ){
			Res[len1].address = List[start].address;
			Res[len1].data = List[start].data;
			Res[len1].next = List[start].next;
			Num[key] = true;
			len1++;
		} else {
			Del[len2].address = List[start].address;
			Del[len2].data = List[start].data;
			Del[len2].next = List[start].next;
			len2++;
		}
		start = List[start].next;
	}
	if( len1 == 0 )
		printf("-1\n");
	else{		
		for( int i = 0; i < len1-1; i++ )
			printf("%05d %d %05d\n", Res[i].address, Res[i].data, Res[i+1].address);
		printf("%05d %d -1\n", Res[len1-1].address, Res[len1-1].data);
	}
	if( len2 == 0 ); 
//		printf("-1\n");
	else{
		for( int i = 0; i < len2-1; i++ )
			printf("%05d %d %05d\n", Del[i].address, Del[i].data, Del[i+1].address);
		printf("%05d %d -1\n", Del[len2-1].address, Del[len2-1].data);	
	}
}
