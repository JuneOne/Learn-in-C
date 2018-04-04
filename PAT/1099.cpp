#include <cstdio>
#include <algorithm>

using namespace std;

struct node{
	int data;
	int left;
	int right;
}Tree[100];

int V[100];
int N;
int cnt = 0;

void CreatTree()
{
	scanf("%d", &N);
	for( int i = 0; i < N; i++ )
		scanf("%d %d", &Tree[i].left, &Tree[i].right);
	for( int i = 0; i < N; i++ )
		scanf("%d", &V[i]);
}

void Insert( int root )
{
	if( root != -1 ){
		Insert(Tree[root].left);
		Tree[root].data = V[cnt++];
		Insert(Tree[root].right);
	}
}

void PreOrder( int root )
{
	if( root != -1 ){
		printf("%d ", Tree[root].data);
		PreOrder(Tree[root].left);
		PreOrder(Tree[root].right);
	}	
}
//void LevelTraversal( int root )
//{
//	if( root == -1 )
//		return;
//	int Queue[100];
//	int front = 0, rear = 0;
//	printf("%d", Tree[root].data);
//	if( Tree[root].left != -1 )
//		Queue[++rear] = Tree[root].left;
//	if( Tree[root].right != -1 )
//		Queue[++rear] = Tree[root].right;
//	while( front != rear )
//	{
//		int temp = Queue[++front];
//		printf(" %d", Tree[temp].data);
//		if( Tree[temp].left != -1 )
//			Queue[++rear] = Tree[temp].left;
//		if( Tree[temp].right != -1 )
//			Queue[++rear] = Tree[temp].right;
//	}
//	
//}

void LevelTraversal( int root )
{
	if( root == -1 )
		return;
	int Queue[100];
	int front = 0, rear = 0;
	Queue[++rear] = root;
	bool space = false;
//	printf("%d", Tree[root].data);
//	if( Tree[root].left != -1 )
//		Queue[++rear] = Tree[root].left;
//	if( Tree[root].right != -1 )
//		Queue[++rear] = Tree[root].right;
	while( front != rear )
	{
		int temp = Queue[++front];
		if( space == false ){
			printf("%d", Tree[temp].data);
			space = true;
		} else
			printf(" %d", Tree[temp].data);
		if( Tree[temp].left != -1 )
			Queue[++rear] = Tree[temp].left;
		if( Tree[temp].right != -1 )
			Queue[++rear] = Tree[temp].right;
	}
	
}

int main()
{
	CreatTree();
	sort(V, V+N);
	Insert(0);
//	PreOrder(0);
	LevelTraversal(0);
}
