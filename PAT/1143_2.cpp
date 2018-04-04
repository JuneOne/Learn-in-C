#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

typedef struct node *Tree;
struct node{
	int data;
	Tree left;
	Tree right;
};

map<int,bool> Map;
int u, v;

Tree FindLCA( Tree T )
{
	while( (T->data-u)*(T->data-v) > 0 )
		T = T->data-u > 0 ? T->left:T->right;
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
	scanf("%d%d", &M, &N);
	while( N-- ){
		scanf("%d", &value);
		T = Insert(T, value);
		Map[value] = true;
	}
	while( M-- ){
		scanf("%d%d", &u, &v);
		bool uu = Map[u];
		bool vv = Map[v];
		if( !uu && !vv )
			printf("ERROR: %d and %d are not found.\n", u, v);
		else if( !uu && vv || uu && !vv )
			printf("ERROR: %d is not found.\n", uu == false?u:v);
		else{
			Tree parent = FindLCA(T);
			if( parent->data == u )
				printf("%d is an ancestor of %d.\n", u, v);
			else if( parent->data == v )
				printf("%d is an ancestor of %d.\n", v, u);
			else
				printf("LCA of %d and %d is %d.\n", u, v, parent->data);				
		}
	}
}
