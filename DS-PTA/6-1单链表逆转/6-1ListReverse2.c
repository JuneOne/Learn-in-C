#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

List Reverse( List L );

int main()
{
	List L1, L2;
	L1 = Read();
	L2 = Reverse(L1);
	Print(L1);
	Print(L2);
	return 0;
}

List Read()
{
	int length;
	PtrToNode p, temp;
	List L = (List)malloc(sizeof(struct Node));
	L->Next = NULL;
	scanf("%d", &length);
	scanf("%d", &L->Data);
	length--;
	p = L;
	while( length-- )
	{
		temp = (PtrToNode)malloc(sizeof(struct Node));
		temp->Next = NULL;
		scanf("%d", &temp->Data);
		p->Next = temp;
		p = temp;
	}
	return L;
}

void Print( List L )
{
	// PtrToNode p;
	if( L == NULL ){
		printf("Empty List!\n");
		return;
	}
	// p = L;
	while( L != NULL )
	{
		printf("%d ", L->Data);
		L = L->Next;
	}
	printf("\n");
}

List Reverse( List L )
{
	PtrToNode temp, last = NULL;
	if( L == NULL || L->Next == NULL )
		return L;
	while( L->Next != NULL )
	{
		temp = L->Next;
		L->Next = last;
		last = L;
		L = temp;
	}
	L->Next = last;
	return L;
}