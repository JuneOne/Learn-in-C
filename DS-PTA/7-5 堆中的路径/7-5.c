#include <stdio.h>
#include <stdlib.h>

#define MIN -1e6

typedef struct HeapStruct *Heap;
struct HeapStruct{
	int *Data;
	int size;
	int capacity;
};

Heap CreateHeap( int MaxSize )
{
	Heap H = (Heap)malloc(sizeof(struct HeapStruct));
	H->Data = (int*)malloc(sizeof(int) * (MaxSize + 1));
	H->size = 0;
	H->capacity = MaxSize;
	H->Data[0] = MIN;

	return H;
}

int IsFull( Heap H )
{
	if( H->size == H->capacity )
		return 1;
	else
		return 0;
}

void Insert( Heap H, int X )
{
	int i;

	if( IsFull( H ) )
	{
		printf("Heap Full!\n");
		return;
	}

	i = ++H->size;
	for( ; H->Data[i/2] > X; i /= 2 )
	{
		H->Data[i] = H->Data[i/2];
	}
	H->Data[i] = X;

}

void PrintPosition( Heap H, int P )
{
	int i;
	printf("%d", H->Data[P]);
	for( i = P / 2; i > 0; i /= 2 )
	{
		printf(" %d", H->Data[i]);
	}
	// printf("\n");
}

int main()
{
	int i, value, position;
	int N, M;
	Heap H;

	scanf("%d%d", &N, &M);
	H = CreateHeap(N);

	for( i = 0; i < N; i++ )
	{
		scanf("%d", &value);
		Insert(H, value);
	}
	for( i = 0; i < M; i++)
	{
		scanf("%d", &position);
		PrintPosition(H, position);
		if( i != M - 1 )
			printf("\n");
	}

	return 0;
}