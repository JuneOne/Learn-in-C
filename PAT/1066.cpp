#include <stdio.h>
#include <stdlib.h>

typedef struct node *AvlTree;
struct node{
	int Data;
	AvlTree Left;
	AvlTree Right;
	int Height;
};

int Max( int a, int b )
{
	return a>b ? a:b;
}

int H( AvlTree T )
{
	if( T == NULL )
		return -1;
	else
		return T->Height;
}
AvlTree SingleLeft( AvlTree T )
{
	AvlTree K = T->Left;
	T->Left = K->Right;
	K->Right = T;
	
	T->Height = Max(H(T->Left), H(T->Right)) + 1;
	K->Height = Max(H(K->Left), T->Height) + 1;
	
	return K;
}

AvlTree SingleRight( AvlTree T )
{
	AvlTree K = T->Right;
	T->Right = K->Left;
	K->Left = T;
	
	T->Height = Max(H(T->Left), H(T->Right)) + 1;
	K->Height = Max(T->Height, H(K->Right)) + 1;
	
	return K;
}

AvlTree DoubleLeft( AvlTree T )
{
	T->Left = SingleRight(T->Left);
	return SingleLeft(T);
}

AvlTree DoubleRight( AvlTree T )
{
	T->Right = SingleLeft( T->Right );
	return SingleRight(T);
}

AvlTree Insert( AvlTree T, int X )
{
	if( T == NULL ){
		T = (AvlTree)malloc(sizeof(struct node));
		T->Data = X;
		T->Left = NULL;
		T->Right = NULL;
		T->Height = -1;
	} else if ( X < T->Data ){
		T->Left = Insert(T->Left, X);
		if( H(T->Left) - H(T->Right) == 2 ){
			if( X < T->Left->Data )
				T = SingleLeft(T);
			else
				T = DoubleLeft(T);
		} 
	} else if ( X > T->Data ){
		T->Right = Insert(T->Right, X);
		if( H(T->Right) - H(T->Left) == 2 ){
			if( X > T->Right->Data )
				T = SingleRight(T);
			else
				T = DoubleRight(T);
		}
	}
	
	T->Height = Max( H(T->Left), H(T->Right) ) + 1;
	
	return T;
}

int main()
{
	int i, value, N;
	AvlTree T = NULL;
	scanf("%d", &N);
	for( i = 0; i < N; i++ ){
		scanf("%d", &value);
		T = Insert(T, value);
	}
	printf("%d\n", T->Data);
	
	return 0;
}
