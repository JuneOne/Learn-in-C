6-1 ��������ת��20 �֣�
����Ҫ��ʵ��һ���������������ĵ�������ת��

�����ӿڶ��壺

List Reverse( List L );
����List�ṹ�������£�

typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* �洢������� */
    PtrToNode   Next; /* ָ����һ������ָ�� */
};
typedef PtrToNode List; /* ���嵥�������� */
L�Ǹ�������������ReverseҪ���ر���ת�������

���в��Գ���������

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* ϸ���ڴ˲��� */
void Print( List L ); /* ϸ���ڴ˲��� */

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

/* ��Ĵ��뽫��Ƕ������ */
����������

5
1 3 4 5 2
���������

1
2 5 4 3 1