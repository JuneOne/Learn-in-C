#include <stdio.h>
#include <stdlib.h>

#define ERROR 1e8

typedef enum {false, true} bool;
struct QNode{
	int *Data;
	int front, rear;
	int MaxSize;
};
typedef struct QNode *Queue;

Queue CreateQueue( int MaxSize )
{
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Data = (int*)malloc(MaxSize * sizeof(int));
	Q->front = Q->rear = 0;
	Q->MaxSize = MaxSize;
	return Q;
}

bool Isfull( Queue Q )
{
	if ( (Q->rear+1) % Q->MaxSize == Q->front )
		return true;
	return false;
}

bool IsEmpty( Queue Q )
{
	if( Q->rear == Q->front )
		return true;
	return false;
}

void EnQueue( Queue Q, int X )
{
	if( Isfull(Q) ){
		printf("Full\n");
		return;
	}
	Q->rear = (Q->rear+1) % Q->MaxSize;
	Q->Data[Q->rear] = X;
}

int Dequeue( Queue Q )
{
	if( IsEmpty(Q) ){
		printf("Empty\n");
		return ERROR;
	}
	Q->front = (Q->front+1) % Q->MaxSize;
	return Q->Data[Q->front];
}

void Print( Queue Q )
{
	int i;
	if( IsEmpty(Q) )
		return;
	for( i = Q->front+1; (i % Q->MaxSize) <= Q->rear; i++ )
	{
		printf("%d ", Q->Data[i]);
	}
}

int main()
{
	Queue Q;
	Q = CreateQueue(5);
	EnQueue(Q, 1);
	EnQueue(Q, 2);
	printf("%d\n",Dequeue(Q));
	EnQueue(Q, 3);
	Print(Q);
}