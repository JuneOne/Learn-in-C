#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef struct SNode *Stack;
struct SNode{
	char *operation;
	int top;
	int size;
};

Stack CreatStack( int MaxSize )
{
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->operation = (char*)malloc(sizeof(char) * MaxSize);
	S->top = -1;
	S->size = MaxSize;

	return S;
}

int IsFull( Stack S )
{
	if( S->top == S->size - 1 )
		return 1;
	else
		return 0;
}

int IsEmpty( Stack S )
{
	if( S->top == -1 )
		return 1;
	else
		return 0;
}

void Push( Stack S, char c )
{
	if( IsFull(S) )
	{
		printf("Stack Full!\n");
		return;
	}
	S->operation[++S->top] = c;
}

char Pop( Stack S )
{
	if( IsEmpty(S) )
	{
		printf("Stack Empty!\n");
		return ERROR;
	}
	return S->operation[S->top--];
}

char GetTop( Stack S )
{
	if( IsEmpty(S) )
	{
		printf("Stack Empty!\n");
		return ERROR;
	}
	return S->operation[S->top];
}

int Priority( char c )
{
	if( c == '(' )
		return 0;
	if( c == '+' || c == '-' )
		return 1;
	if( c == '*' || c == '/' )
		return 2;
}

void RPN( char str[] )
{
	int i;
	int len1 = 0, len2 = 0;
	// int Nospace = 1;
	char* res;
	Stack S;
	while( str[len1] != '\0' )
		len1++;
	res = (char*)malloc(sizeof(char) * len1);
	S = CreatStack(len1);

	for( i = 0; i < len1; i++ )
	{
		if( str[i] >= '0' && str[i] <= '9' ){
			
			res[len2++] = str[i];
		}else if( str[i] == '(' ){
			Push(S, str[i]);
		}else if( str[i] == ')' ){
			while( GetTop(S) != '(' )
				res[len2++] = Pop(S);
			Pop(S);
		}else{
			if( S->top == -1 )
				Push(S, str[i]);
			else{
				if( Priority(str[i]) > Priority(GetTop(S)) )
					Push(S, str[i]);
				else{
					while( S->top != -1 && Priority(str[i]) <= Priority(GetTop(S)) )
						res[len2++] = Pop(S);
					Push(S, str[i]);
				}
			}
		}
	}
	while( S->top != -1 )
		res[len2++] = Pop(S);
	if( len2 > 0 ){
		printf("%c", res[0]);
		for( i = 1; i < len2; i++ )
			printf(" %c", res[i]);
	}
}

int main()
{
	char str[21];
	scanf("%s", &str);
	RPN(str);

	return 0;
}