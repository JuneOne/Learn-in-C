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
	// L2 = Reverse(L1);
	Print(L1);
	Print(L1);
	return 0;
}

List Read()
{
	int length, data;
	PtrToNode p, head;
	List L;

	L = (List)malloc(sizeof(struct Node));
	L->Next = NULL;
	head = L;
	scanf("%d", &length);
	while( length-- )
	{
		p = (PtrToNode)malloc(sizeof(struct Node));
		scanf("%d", &data);
		p->Data = data;
		p->Next = NULL;
		head->Next = p;
		head = p;
	}
	return L;	
}

void Print( List L )
{
	if( L == NULL || L->Next == NULL ){
		printf("Empty List!\n");
		return;
	}
	
	L = L->Next;
	while( L != NULL ){
		printf("%d ", L->Data);
		L = L->Next;
	}
	printf("\n");
}

List Reverse( List L )
{
	PtrToNode p, temp, last = NULL;
	List head = (List)malloc(sizeof(struct Node));
	head->Next = NULL;
	if( L == NULL || L->Next == NULL )
		return L;
	p = L->Next;
	while( p->Next != NULL )
	{
		temp = p->Next;
		p->Next = last;
		last = p;
		p = temp;
	}
	p->Next = last;
	head->Next = p;
	return head;
}