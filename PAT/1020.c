#include <stdio.h>
#include <stdlib.h>

#define NOTFOUND -1

typedef struct TNode* Tree;
typedef struct QNode* Queue;
struct TNode{
	int Data;
	Tree Left;
	Tree Right;
};

struct QNode{
	int *Data;
	int front, rear;
	int MaxSize;
};

int post[30];
int inorder[30];
int cur, N;


Queue CreateQueue( int MaxSize )
{
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Data = (int*)malloc(sizeof(int)*MaxSize);
	Q->front = Q->rear = 0;
	Q->MaxSize = MaxSize;

	return Q;
}

void EnQueue( Queue Q, int x )
{
	if( (Q->rear+1) % Q->MaxSize == Q->front ){
		printf("Queue Full!\n");
		return;
	}
	Q->rear = (Q->rear+1) % Q->MaxSize;
	Q->Data[Q->rear] = x;
}

int DeQueue( Queue Q )
{

}

int FindRoot( int x )
{
	int i;
	for( i = 0; i < N; i++ ){
		if( inorder[i] == x )
			return i;
	}

	return NOTFOUND;
}

Tree CreateTree( int left, int right )
{
	if( left > right )
		return NULL;
	int root = post[cur--];
	int index = FindRoot(root);
	Tree T;
	T = (Tree)malloc(sizeof(struct TNode));
	T->Data = root; 

	if( left == right ){
		T->Left = NULL;
		T->Right = NULL;
	} else {
		T->Right = CreateTree(index+1, right);
		T->Left = CreateTree(left, index-1);
	}

	return T;
}

// void PreOrderTraversal( Tree T )
// {
// 	if( T != NULL ){
// 		printf("%d ", T->Data);
// 		PreOrderTraversal( T->Left );
// 		PreOrderTraversal( T->Right );
// 	}
// }

void LevelTraversal( Tree T )
{
	Tree queue[100];
	Tree temp;
	int rear, front;
	rear = front = 0;
	if( !T )
		return;
	printf("%d", T->Data);
	if( T->Left != NULL )
		queue[(++rear) % 100] = T->Left;
	if( T->Right != NULL )
		queue[(++rear) % 100] = T->Right;	
	
	while( (rear % 100 ) != front )
	{
		temp = queue[(++front) % 100];
		printf(" %d", temp->Data);
		if( temp->Left != NULL )
			queue[(++rear) % 100] = temp->Left;
		if( temp->Right != NULL )
			queue[(++rear) % 100] = temp->Right;
	}
}

int main()
{
	int i;
	Tree T;
	scanf("%d", &N);
	for( i = 0; i < N; i++ )
		scanf("%d", &post[i]);
	for( i = 0; i < N; i++ )
		scanf("%d", &inorder[i]);
	cur = N-1;
	T = CreateTree(0,N-1);
	// PreOrderTraversal(T);
	LevelTraversal(T);

	return 0;
}