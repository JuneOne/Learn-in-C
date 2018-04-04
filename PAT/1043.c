#include <stdio.h>
#include <stdlib.h>

typedef struct node *Tree;
struct node{
	int data;
	Tree left;
	Tree right;
};

int pre[1000];
int len, space = 0;
 
Tree Insert( Tree T, int X )
{
	if( T == NULL ){
		T = (Tree)malloc(sizeof(struct node));
		T->data = X;
		T->left = NULL;
		T->right = NULL;
	} else {
		if( X < T->data )
			T->left = Insert( T->left, X);
		else if( X >= T->data )
			T->right = Insert( T->right, X);
	}
	
	return T;
}

void PreOrder( Tree T )
{
	if( T != NULL ){
		pre[len++] = T->data;
//		printf("%d ", T->data);
		PreOrder( T->left );
		PreOrder( T->right );
	}
}

void PostOrder( Tree T )
{
	if( T != NULL ){
		PostOrder( T->left );
		PostOrder( T->right );
		if( space == 0 ){
			printf("%d", T->data);
			space = 1;
		} else 
			printf(" %d", T->data);
	}
}

void Exchange( Tree T )
{
	if( T != NULL  ){
		Tree temp = T->left;
		T->left = T->right;
		T->right = temp;
		Exchange(T->left);
		Exchange(T->right);
	}
}

int main()
{
	int i, N, number, flag = 0;
	int arr[1000];
	Tree T = NULL;
	scanf("%d", &N);
	for( i = 0; i < N; i++ ){
		scanf("%d", &number);
		arr[i] = number;
		T = Insert(T, number);
	}
	PreOrder(T);
	for( i = 0; i < N; i++ )
		if( arr[i] != pre[i] )
			break;
	if( i == N ){
		printf("YES\n");
		PostOrder(T); printf("\n");
		flag = 1;
	} else {
		len = 0;
		Exchange(T);
		PreOrder(T);
		for( i = 0; i < N; i++ )
			if( arr[i] != pre[i] )
				break;
		if( i == N ){
			printf("YES\n");
			PostOrder(T); printf("\n");
			flag = 1;
		}
	}
	if( flag == 0 )
		printf("NO\n");

}
