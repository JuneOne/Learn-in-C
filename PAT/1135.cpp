#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct RBnode *RBTree;
struct RBnode{
	int Data;
	RBTree Left;
	RBTree Right;
};

int pre2[30];
int len = 0;

RBTree Insert( RBTree T, int X )
{
	if( T == NULL ){
		T = (RBTree)malloc(sizeof(struct RBnode));
		T->Left = T->Right = NULL;
		T->Data = X; 
	} else if ( abs(X) < abs(T->Data) ) // abs(T->Data) 
		T->Left = Insert(T->Left, X);
	else if ( abs(X) > abs(T->Data) )
		T->Right = Insert(T->Right, X);
	
	return T;
}

void PreOrder( RBTree T )
{
	if( T != NULL ){
		pre2[len++] = T->Data;
		PreOrder(T->Left);
		PreOrder(T->Right);
	}
}

bool IsBST( int pre[], int len )
{
	for( int i = 0; i < len; i++ )
		if( pre[i] != pre2[i] )
			return false;
	return true;
}

bool Judge1( RBTree T ) // 红节点的儿子是黑 
{
	if( T == NULL )
		return true;
	if( T->Data < 0 ){
		if( T->Left != NULL && T->Left->Data < 0 || T->Right != NULL && T->Right->Data < 0)
			return false;
	}
	return Judge1(T->Left) && Judge1(T->Right);
}

int Height( RBTree T )
{
	if( T == NULL )
		return 0;
	int l = Height(T->Left);
	int r = Height(T->Right);
	if( T->Data > 0 )
		return (l > r ? l : r)+1;
	else
		return (l > r ? l : r);	
}

bool Judge2( RBTree T ) // 左右子树的黑节点树 
{
	if( T == NULL )
		return true;
	int l = Height(T->Left);
	int r = Height(T->Right);
	if( l != r )
		return false;
		
	return Judge2(T->Left) && Judge2(T->Right);
}

int main()
{
	int N, K;
	int pre[30];
	scanf("%d", &K);
	while( K-- )
	{
		len = 0;
		RBTree T = NULL;
		scanf("%d", &N);
		for( int i = 0; i < N; i++ ){
			scanf("%d", &pre[i]);
			T = Insert(T, pre[i]);
		}
		PreOrder(T);
		if( T == NULL )
			printf("Yes\n");
		else if( T->Data > 0 && IsBST(pre, N) && Judge1(T) && Judge2(T) )
			printf("Yes\n");
		else
			printf("No\n");
	}
}
