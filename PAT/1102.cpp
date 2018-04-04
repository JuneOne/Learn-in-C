#include <stdio.h>

struct node{
	int data;
	int left;
	int right;
};

struct node Tree[10];
int N;
int space = false;

int init()
{
	scanf("%d", &N);
	getchar();
	int visit[10] = {0};
	
	for( int i = 0; i < N; i++ ){
		char cl, cr;
		scanf("%c %c", &cl, &cr);
		getchar();
		if( cl == '-' )
			Tree[i].left = -1;	
		else{
			Tree[i].left = cl - '0';
			visit[cl-'0'] = 1;
		}
		if( cr == '-' )
			Tree[i].right = -1;
		else{
			Tree[i].right = cr - '0';
			visit[cr-'0'] = 1;
		}
		Tree[i].data = i;
	}
	
	for( int i = 0; i < N; i++ )
		if( visit[i] == 0 )
			return i;
}

void swap( int root )
{
	if( root != -1 ){
		swap(Tree[root].left);
		swap(Tree[root].right);
		int temp = Tree[root].left;
		Tree[root].left = Tree[root].right;
		Tree[root].right = temp;
	}	
}

void level( int root )
{	
	bool flag = false;
	int Queue[20];
	int front = 0, rear = 0;
	Queue[++rear] = root;
	while( front != rear )
	{
		int temp = Queue[++front];
		if( !flag ){
			printf("%d", Tree[temp].data);
			flag = true;
		} else
			printf(" %d", Tree[temp].data);
		if( Tree[temp].left != -1 )
			Queue[++rear] = Tree[temp].left;
		if( Tree[temp].right != -1 )
			Queue[++rear] = Tree[temp].right;
	}
}

void inorder( int root )
{
	if( root != -1 ){
		inorder( Tree[root].left);
		if( !space ){
			printf("%d", Tree[root].data);
			space = true;
		} else
			printf(" %d", Tree[root].data);
		inorder( Tree[root].right );
	}	
}

int main()
{
	int root = init();
	swap(root);
	level(root);
	printf("\n");
	inorder(root);
}
