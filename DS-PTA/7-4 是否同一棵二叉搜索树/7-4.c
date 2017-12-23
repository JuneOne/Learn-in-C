#include <stdio.h>
#include <stdlib.h>

typedef struct TNode *BinTree;
struct TNode{
	int data;
	BinTree Left;
	BinTree Right;
};

BinTree InsertTree( BinTree T, int X )
{
	if( T == NULL )
	{
		T = (BinTree)malloc(sizeof(struct TNode));
		T->data = X;
		T->Left = NULL;
		T->Right = NULL;
	}else{
		if( X < T->data )
			T->Left = InsertTree(T->Left, X);
		else if( X > T->data )
			T->Right = InsertTree(T->Right, X);
	}

	return T;
}

// void PreOrderTraversal( BinTree T)
// {
// 	if( T != NULL )
// 	{
// 		printf("%d ", T->data);
// 		PreOrder(T->Left);
// 		PreOrder(T->Right);
// 	}
// }

int IsSame( BinTree T1, BinTree T2 )
{
	if( T1 == NULL && T2 == NULL )
		return 1;
	if( T1 != NULL && T2 == NULL || T1 == NULL && T2 != NULL )
		return 0;
	if( T1->data != T2->data )
		return 0;
	return IsSame(T1->Left, T2->Left) && IsSame(T1->Right, T2->Right);
}

int main()
{
	int i, value;
	int N, L;
	BinTree T, Tcmp;

	while(1){
		scanf("%d", &N);
		if( N == 0 )
			break;
		scanf("%d", &L);
		T = NULL;
		for( i = 1; i <= N; i++ ){
			scanf("%d", &value);
			T = InsertTree(T, value);
		}
		while(L--)
		{
			Tcmp = NULL;
			for( i = 1; i <= N; i++ ){
				scanf("%d", &value);
				Tcmp = InsertTree(Tcmp, value);
			}
			if(IsSame(T, Tcmp))
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	// PreOrderTraversal(T);
	return 0;
}