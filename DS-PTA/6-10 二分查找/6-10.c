#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List Tbl, ElementType K );
void Print(List L);
int main()
{
    List Tbl;
    ElementType K;
    Position P;

    Tbl = ReadInput();
    scanf("%d", &K);
    P = BinarySearch( Tbl, K );
    printf("%d\n", P);
    Print(Tbl);
    return 0;
}

/* 你的代码将被嵌在这里 */
List ReadInput()
{
    int length;
    List L = (List)malloc(sizeof(struct LNode));
    scanf("%d", &length);
    // L->Data = (ElementType*)malloc(length * sizeof(ElementType));
    L->Last = 0;
    while( length-- )
        scanf("%d", &L->Data[++L->Last]);
    return L;
}

void Print( List L )
{
    // printf("%d\n", L->Last);
    int i;
    if( L->Last == 0 )
    {
        printf("Empty!\n");
        return;
    }
    for( i = 1; i <= L->Last; i++ )
        printf("%d ", L->Data[i]);
}

Position BinarySearch( List Tbl, ElementType K )
{
    int left = 1, right = Tbl->Last;
    int mid;
    while( left <= right )
    {
        mid = (left + right) / 2;
        if( Tbl->Data[mid] < K )
        {
            left = mid + 1;
        }
        if( Tbl->Data[mid] > K )
        {
            right = mid - 1;
        }
        if( Tbl->Data[mid] == K )
            return mid;
    }
    return NotFound;
}