#include <stdio.h>
// #define Null -1
#define MAX 10

typedef struct TNode Tree;
struct TNode{
	char data;
	int left;
	int right;
}T1[MAX], T2[MAX];

int CreateTree(Tree T[])
{
	int i, N;
	char cl, cr;
	int check[MAX];
	int root = -1;
	scanf("%d", &N);
	getchar();
	for( i = 0; i < N; i++ )
		check[i] = 0;
	for( i = 0; i < N; i++ )
	{
		scanf("%c %c %c", &T[i].data, &cl, &cr);
		getchar();
		// printf("%c%c%c\n", T[i].data, cl, cr);
		if( cl != '-' ){
			T[i].left = cl - '0';
			check[T[i].left] = 1;
		}else{
			T[i].left = -1;
		}
		if( cr != '-' ){
			T[i].right = cr - '0';
			check[T[i].right] = 1;
		}else{
			T[i].right = -1;
		}
	}
	for( i = 0; i < N; i++ )
		if(check[i] == 0){
			root = i;
			break;
		}
	return root;
}

int IsSame( int R1, int R2 )
{
	if( R1 == -1 && R2 == -1 )
		return 1;
	if( R1 == -1 && R2 != -1 || R1 != -1 && R2 == -1 )
		return 0;
	if( T1[R1].data != T2[R2].data )
		return 0;
	// if( T1[R1].left == -1 && T2[R2].left == -1 )
	// 	return IsSame(T1[R1].right, T2[R2].right);
	if( T1[R1].left != -1 && T2[R2].left != -1 && T1[T1[R1].left].data == T2[T2[R2].left].data )
		return IsSame(T1[R1].left, T2[R2].left) && IsSame(T1[R1].right, T2[R2].right);
	else
		return IsSame(T1[R1].left, T2[R2].right) && IsSame(T1[R1].right, T2[R2].left);
}

int main()
{
	int Root1, Root2;
	Root1 = CreateTree(T1);
	Root2 = CreateTree(T2);
	// printf("%c\n%c\n", T1[Root1].data, T2[Root2].data);
	if( IsSame(Root1, Root2) )
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}