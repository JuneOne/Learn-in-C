#include <stdio.h>
#define ERROR -100
typedef struct SNode *Stack;
struct SNode{
	int *Data;
	int Top;
	int Maxsize;
};

Stack CreateStack( int size )
{
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (int*)malloc(sizeof(int) * size);
	S->Top = -1;
	S->Maxsize = size;
	return S;
}

void Push( Stack S, int X )
{
	if( S->Top == S->Maxsize )
	{
		printf("FULL\n");
		return;
	}
	S->Data[++(S->Top)] = X;
}

int Pop( Stack S )
{
	if( S->Top == -1 ){
		printf("Empty\n");
		return ERROR;
	}
	return S->Data[S->Top--]; /* the same as (S->Top)-- */
}

void Print( Stack S )
{
	int i;
	for( i = 0; i < S->Top + 1; i++ )
		printf("%d ", S->Data[i]);
}

int main()
{
	Stack S;
	S = CreateStack(5);
	Push(S,1);
	Push(S,2);
	Pop(S);
	Print(S);
	return 0;
}

