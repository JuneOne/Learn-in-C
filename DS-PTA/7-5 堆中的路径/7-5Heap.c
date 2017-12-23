#include <stdio.h>
#include <stdlib.h>

#define MAX 1e6

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
	H->Data[0] = MAX;

	return H;
}

int IsFull( Heap H )
{
	if( H->size == H->capacity )
		return 1;
	else
		return 0;
}

int IsEmpty( Heap H )
{
	if( H->size == 0 )
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
	for(; H->Data[i/2] < X; i /= 2)
	{
		H->Data[i] = H->Data[i/2];
	}
	H->Data[i] = X;
}

int Delete( Heap H )
{
	int Parent, Child;
	int MaxItem, Last;

	if( IsEmpty( H ) )
	{
		printf("Heap Empty!\n");
		return -1;
	}

	MaxItem = H->Data[0];
	Last = H->Data[H->size--];

	for( Parent = 1; Parent * 2 <= H->size; Parent = Child)
	{
		Child = Parent * 2;
		if( (Child < H->size) && (H->Data[Child+1] > H->Data[Child]))
			Child = Child + 1;
		if( H->Data[Child] <= Last )
			break;
		else
			H->Data[Parent] = H->Data[Child];
	}
	H->Data[Parent] = Last;

	return MaxItem;
}

void PercDown( Heap H, int p )
{
	int Parent, Child;
	int X;

	X = H->Data[p];
	for( Parent = p; Parent * 2 <= H->size; Parent = Child )
	{
		Child = Parent * 2;
		if( Child < H->size && H->Data[Child+1] > H->Data[Child] )
			Child = Child + 1;
		if( H->Data[Child] <= X )
			break;
		else
			H->Data[Parent] = H->Data[Child];
	}
	H->Data[Parent] = X;
}

void BuildHeap( Heap H )
{
	int i;
	for( i = H->size / 2; i > 0; i-- )
		PercDown( H, i );
}

int main()
{
	int i;
	Heap H;
	H = CreateHeap(5);
	for( i = 1; i <= 5; i++ )
	{
		// Insert(H, i);
		H->Data[++H->size] = i;
	}
	BuildHeap(H);
	// Delete(H);
	for( i = 1; i <= H->size; i++ )
		printf("%d ", H->Data[i]);
}