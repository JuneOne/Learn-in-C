#include <stdio.h>
#include <stdlib.h>

typedef struct node *AvlTree;
struct node{
	int data;
	AvlTree left;
	AvlTree right;
	int height;
};

int cnt, N;
bool flag = true;
bool space = false;

int max( int a, int b )
{
	return a > b ? a : b;
}

int Height( AvlTree T )
{
	if( T == NULL )
		return -1;
	else
		return T->height;	
}

AvlTree SingleLeft( AvlTree T )
{
	AvlTree K;
	K = T->left;
	T->left = K->right;
	K->right = T;
	
	T->height = max(Height(T->left), Height(T->right)) + 1;
	K->height = max(Height(K->left), T->height) + 1;
	
	return K;
}

AvlTree SingleRight( AvlTree T )
{
	AvlTree K;
	K = T->right;
	T->right = K->left;
	K->left = T;
	
	T->height = max(Height(T->left), Height(T->right)) + 1;
	K->height = max(T->height, Height(K->right)) + 1;
	
	return K;
}

AvlTree DoubleLeft( AvlTree T )
{
	T->left = SingleRight(T->left);
	return SingleLeft(T);
}

AvlTree DoubleRight( AvlTree T )
{
	T->right = SingleLeft(T->right);
	return SingleRight(T);	
}

AvlTree Insert( AvlTree T, int X )
{
	if( T == NULL )	{
		T = (AvlTree)malloc(sizeof(struct node));
		T->data = X;
		T->left = T->right = NULL;
	} else if ( X < T->data ){
		T->left = Insert(T->left, X);
		if( Height(T->left) - Height(T->right) == 2 ){
			if( X < T->left->data )
				T = SingleLeft(T);
			else
				T = DoubleLeft(T);
		}
	} else if ( X > T->data ){
		T->right = Insert(T->right, X);
		if( Height(T->right) - Height(T->left) == 2 ){
			if( X > T->right->data )
				T = SingleRight(T);
			else
				T = DoubleRight(T);
		}
	}
	
	T->height = max(Height(T->left), Height(T->right)) + 1;
	
	return T;
}

void LevelTravelsal( AvlTree T )
{
	AvlTree Queue[50];
	int front = 0, rear = 0;
	Queue[++rear] = T;
	cnt++;
	while( front != rear )
	{
		AvlTree tmp = Queue[++front];
		if( !space ){
			printf("%d", tmp->data);
			space = true;
		} else
			printf(" %d", tmp->data);
		if( tmp->left == NULL ){
			if( cnt != N )	flag = false;
		} else {
			Queue[++rear] = tmp->left;
			cnt++;
		}
		if( tmp->right == NULL ){
			if( cnt != N )  flag = false;
		} else {
			Queue[++rear] = tmp->right;
			cnt++;
		}
	}
}

int main()
{
	int value;
	AvlTree T = NULL;
	scanf("%d", &N);
	for( int i = 0; i < N; i++ ){
		scanf("%d", &value);
		T = Insert(T, value);
	}
	
	LevelTravelsal(T);
	if( flag ) 
		printf("\nYES\n");
	else 
		printf("\nNO\n");
	
	return 0;	
}
