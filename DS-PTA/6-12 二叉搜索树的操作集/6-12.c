#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    // MinP = FindMin(BST);
    MaxP = FindMax(BST);
    printf("MAX=%d\n", MaxP->Data);
    // BST = Delete(BST, 3);
    // printf("Preorder:"); PreorderTraversal(BST); printf("\n");    
    // scanf("%d", &N);
    // for( i=0; i<N; i++ ) {
    //     scanf("%d", &X);
    //     Tmp = Find(BST, X);
    //     if (Tmp == NULL) printf("%d is not found\n", X);
    //     else {
    //         printf("%d is found\n", Tmp->Data);
    //         if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
    //         if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
    //     }
    // }
    // scanf("%d", &N);
    // for( i=0; i<N; i++ ) {
    //     scanf("%d", &X);
    //     BST = Delete(BST, X);
    // }
    // printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
/* 你的代码将被嵌在这里 */
void PreorderTraversal( BinTree BT ) /* 先序遍历，由裁判实现，细节不表 */
{
    if( BT )
    {
        printf(" %d", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}

void InorderTraversal( BinTree BT )  /* 中序遍历，由裁判实现，细节不表 */
{
    if( BT )
    {
        InorderTraversal(BT->Left);
        printf(" %d", BT->Data);
        InorderTraversal(BT->Right);
    }
}

BinTree Insert( BinTree BST, ElementType X )
{
    if( !BST )
    {
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = NULL;
        BST->Right = NULL;
        return BST;
    }
    if( X < BST->Data )
    {
        BST->Left = Insert( BST->Left, X );
    }
    if( X > BST->Data )
    {
        BST->Right = Insert( BST->Right, X );
    }
    return BST;
}

BinTree Delete( BinTree BST, ElementType X )
{
    BinTree temp;
    if( !BST )
    {
        printf("Not Found\n");
        return BST;
    }
    if( X < BST->Data )
    {
        BST->Left = Delete( BST->Left, X );
    }
    if( X > BST->Data )
    {
        BST->Right = Delete( BST->Right, X );
    }
    if( X == BST->Data )
    {
        if( BST->Left == NULL && BST->Right == NULL )
        {
            temp = BST;
            free(temp);
            BST = NULL;
            return BST;
        }
        if( BST->Left == NULL && BST->Right != NULL )
        {
            // temp = BST->Right;
            // free(BST);
            // return temp;
            temp = BST;
            BST = BST->Right;
            free(temp);
            return BST;
        }
        if( BST->Right == NULL && BST->Left != NULL )
        {
            temp = BST;
            BST = BST->Left;
            free(temp);
            return BST;
        }
        if( BST->Left != NULL && BST->Right != NULL )
        {
            // temp = FindMax( BST->Left );
            // temp->Left = BST->Left;
            // temp->Right = BST->Right;
            // // free(BST);
            // return temp;
            temp = FindMax( BST->Left );
            BST->Data = temp->Data;
            BST->Left = Delete(BST->Left, BST->Data);
            return BST;
        }
    }
    return BST;
}

Position FindMax( BinTree BST )
{
    if( BST->Right != NULL )
    {
        FindMax( BST->Right ); /* 1 */
    }
    else
        return BST;
}

Position FindMin( BinTree BST )
{
    if( BST->Left != NULL)
    {
        return FindMin( BST->Left );  /* 2 */
    }
    return BST;
}

Position Find( BinTree BST, ElementType X )
{
    // if( X > BST->Data )
    //     BST = Find( BST->Right, X);
    // if( X < BST->Data )
    //     BST = Find( BST->Left, X);
    // if( X == BST->Data )
    //     return BST;
    // return BST;
    if(BST == NULL || BST -> Data == X)
        return BST;
    if( X < BST->Data )
        return Find(BST->Left, X); /* 3 */
    if( X > BST->Data )
        return Find(BST->Right,X);

    // if( BST == NULL)  
    // {   
    //     return NULL;  
    // }  
    // else if (X < BST->Data)  
    // {  
    //      Find(BST->Left, X);  
    // }  
    // else if(X > BST->Data)  
    // {  
    //      Find(BST->Right, X);  
    // }  
    // else  
    // {  
    //     return BST;  
    // }  
}