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
	int data, length;
	scanf("%d", &length);
	List head, p;
	PtrToNode temp;
	head = (List)malloc(sizeof(struct Node));
	head->Next = NULL;
	p = head;
	while( length-- )
	{
		temp = (PtrToNode)malloc(sizeof(struct Node));
		p->Next = temp;
		scanf("%d", &data);
		temp->Data = data;
		temp->Next = NULL;
		p = temp;
	}

	return head;
}

void Print( List L )
{
	PtrToNode temp;
	temp = L->Next;
	while( temp != NULL )
	{
		printf("%d ", temp->Data);
		temp = temp->Next;
	}
	printf("\n");
}

List Reverse( List L )
{
	PtrToNode p1, p2, last = NULL;
	// List head;
	// head = (List)malloc(sizeof(struct Node));
	if( L == NULL || L->Next == NULL )
		return L;
	p1 = L;
	while( p1->Next != NULL )
	{
		p2 = p1->Next;
		p1->Next = last;
		last = p1;
		p1 = p2;
	}
	p1->Next = last;
	return p1;
}
/* 你的代码将被嵌在这里 */