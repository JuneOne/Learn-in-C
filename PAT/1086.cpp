#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stack>
#include <string.h>

using namespace std;

typedef struct TNode *Tree;
struct TNode{
	int value;
	Tree left;
	Tree right;
};

int pre[30];
int inord[30];
int N;
int pLen, iLen;
bool flag = true;

Tree BuildTree(int preNo, int inNo, int len)
{
	if( len <= 0 )
		return NULL;
	Tree T = (Tree)malloc(sizeof(struct TNode));
	T->value = pre[preNo];
	int index;
	for( int i = inNo; i < inNo+len; i++ )
		if( inord[i] == T->value ){
			index = i;
			break;
		}
	T->left = BuildTree(preNo+1, inNo, index-inNo);
	T->right = BuildTree(preNo+1+index-inNo, index+1, len-(index-inNo)-1);

	return T;
}

void PostOrder( Tree T )
{
	if( T ){
		PostOrder(T->left);
		PostOrder(T->right);
		if( flag ){
			printf("%d", T->value);
			flag = false;
		} else 
			printf(" %d", T->value);
	}
}
int main()
{
	char s[5];
	stack<int> S;
	scanf("%d", &N);
	for( int i = 0; i < 2*N; i++ ){
		scanf("%s", s);
		if( strcmp(s, "Push") == 0 ){
			int X;
			scanf("%d", &X);
			S.push(X);
			pre[pLen++] = X;
		}
		if( strcmp(s, "Pop") == 0 ){
			inord[iLen++] = S.top();
			S.pop();
		}
	}
	Tree T = BuildTree(0,0,N);
	PostOrder(T);
	printf("\n");
	
	return 0;
}
