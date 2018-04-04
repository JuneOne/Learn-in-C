#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

typedef struct node *Tree;
struct node{
	int data;
	Tree left;
	Tree right;
};

vector<int> V1, V2;

int Find( Tree T, int x, int flag )
{
	if( T == NULL )
		return 0;
	else{
		if( flag == 1 )
			V1.push_back(T->data);
		if( flag == 2 )
			V2.push_back(T->data);
		if( x < T->data )
			return Find( T->left, x, flag );
		else if( x > T->data )
			return Find( T->right, x, flag );
		else
			return 1;
	}
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
	int uu, vv;
	scanf("%d%d", &M, &N);
	while( N-- ){
		scanf("%d", &value);
		T = Insert(T, value);
	}
	while( M-- ){
		scanf("%d%d", &u, &v);
		uu = Find(T, u, 1);
		vv = Find(T, v, 2);
		if( uu == 0 && vv == 0 )
			printf("ERROR: %d and %d are not found.\n", u, v);
		else if( uu == 0 && vv != 0 )
			printf("ERROR: %d is not found.\n", u);
		else if( uu != 0 && vv == 0 )
			printf("ERROR: %d is not found.\n", v);
		else{
			int i, parent;
			for( i = 0; i < V1.size() && i < V2.size(); i++ ){
				if( V1[i] == V2[i] )
					parent = V1[i];
				else
					break;
			}
			if( parent == u )
				printf("%d is an ancestor of %d.\n", u, v);
			else if( parent == v )
				printf("%d is an ancestor of %d.\n", v, u);
			else
				printf("LCA of %d and %d is %d.\n", u, v, parent);				
		}
		V1.clear();
		V2.clear();
	}
}
