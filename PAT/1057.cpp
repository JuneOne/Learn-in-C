#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int S1[10000], S2[10000];
int len = 0;

void Push()
{
	int X;
	scanf("%d", &X);
	S1[len] = S2[len] = X;
	len++;
}

void Pop()
{
	if( len == 0 ){
		printf("Invalid\n");
		return;
	} else {
		int X = S1[--len];
		printf("%d\n", X);
	}
}

void PeekMedian()
{
	if( len == 0 ){
		printf("Invalid\n");
		return;
	} else {
		sort(S2, S2+len);
		printf("%d\n", S2[(len-1)/2]);
	}
	
}

int main()
{
	int N;
	char Oper[11];
	scanf("%d", &N);
	getchar();
	while( N-- )
	{
		scanf("%s", Oper);
		if( strcmp(Oper, "Pop") == 0 ){
			Pop();
		} else if ( strcmp(Oper, "Push") == 0 ){
			Push();
		} else if ( strcmp(Oper, "PeekMedian") == 0 ){
			PeekMedian();
		}
	}
	return 0;
}
