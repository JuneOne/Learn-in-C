#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct node *Tree;
struct node{
	int data;
	Tree left;
	Tree right;
};


Tree Find( Tree T, int x )
{
//	if( T == NULL )
//		return NULL;
//	else{
//		if( x < T->data )
//			return Find( T->left, x );
//		else if( x > T->data )
//			return Find( T->right, x );
//		else
//			return T;
//	}
	while(T){
		if( x < T->data )
			T = T->left;
		else if( x > T->data)
			T = T->right;
		else
			return T;
	}
	return T;
}

Tree FindLCA( Tree T, Tree p, Tree q )
{
	while( (T->data-p->data)*(T->data-q->data) > 0 )
		T = T->data-p->data > 0 ? T->left:T->right;
	return T;
}

Tree Insert( Tree T, int x )
{
	if( T == NULL ){
		T = (Tree)malloc(sizeof(struct node));
		T->data = x;
		T->left = T->right = NULL;
	}
	else if( x < T->data )
		T->left = Insert(T->left, x);
	else
		T->right = Insert(T->right, x);
	
	return T;
}

int main()
{
	Tree T = NULL;
	int M, N, value;
	int u, v;
	scanf("%d%d", &M, &N);
	while( N-- ){
		scanf("%d", &value);
		T = Insert(T, value);
	}
	while( M-- ){
		scanf("%d%d", &u, &v);
		Tree uu = Find(T, u);
		Tree vv = Find(T, v);
		if( uu == NULL && vv == NULL )
			printf("ERROR: %d and %d are not found.\n", u, v);
		else if( uu == NULL && vv != NULL )
			printf("ERROR: %d is not found.\n", u);
		else if( uu != NULL && vv == NULL )
			printf("ERROR: %d is not found.\n", v);
		else{
			Tree parent = FindLCA(T, uu, vv);
			if( parent == uu )
				printf("%d is an ancestor of %d.\n", u, v);
			else if( parent == vv )
				printf("%d is an ancestor of %d.\n", v, u);
			else
				printf("LCA of %d and %d is %d.\n", u, v, parent->data);				
		}
	}
}
