#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

ElementType FindKth( List L, int K );

int main()
{
    int N, K;
    ElementType X;
    List L = Read();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &K);
        X = FindKth(L, K);
        if ( X!= ERROR )
            printf("%d ", X);
        else
            printf("NA ");
    }
    return 0;
}
List Read()
{
	int num;
	PtrToLNode p, temp;
	List L = (List)malloc(sizeof(struct LNode));
	L->Next = NULL;
	scanf("%d", &num);
	if( num != -1 )
		L->Data = num;
	else
		return L;
	p = L;
	while( num != -1 )
	{
		temp = (PtrToLNode)malloc(sizeof(struct LNode));
		temp->Next = NULL;
		scanf("%d", &num);
		temp->Data = num;
		p->Next = temp;
		p = temp;
	}
	return L;
}

ElementType FindKth( List L, int K )
{
	int i = 0;

	if( K <= 0 || L == NULL )
		return ERROR;

	while( L != NULL )
	{
		i++;
		if( i == K )
			break;
		L = L->Next;
		// i++;

	}
	if( L == NULL )
		return ERROR;
	else
		return L->Data;

}

// ElementType FindKth(List L,int K){
//     while(--K)
//     {
//         if( L == NULL )
//         	return ERROR;
//         L = L->Next;
//     }
//     if( L == NULL )
//     	return ERROR;
    
//     return L->Data;
// }