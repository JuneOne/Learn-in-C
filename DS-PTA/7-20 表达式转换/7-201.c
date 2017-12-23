#include <stdio.h>
#include <stdlib.h>

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
	S->operation[++S->top] = c;
}

char Pop( Stack S )
{
	return S->operation[S->top--];
}

char GetTop( Stack S )
{
	return S->operation[S->top];
}

int Priority( char c )
{
	if( c == '(' )
		return 0;
	if( c == '+' || c == '-' )
		return 1;
	else
		return 2;
}

void RPN( char str[] )
{
	int i;
	int len1 = 0, len2 = 0;
	int Nospace = 1;

	Stack S;
	while( str[len1] != '\0' )
		len1++;

	S = CreatStack(len1);

	for( i = 0; i < len1; i++ )
	{
		if( str[i] == ' ' )
			continue;
		else if( str[i] >= '0' && str[i] <= '9' ){
			if( Nospace ){
				putchar(str[i]);
				Nospace = 0;
			}else{
				putchar(' ');
				putchar(str[i]);
			}
			i++;
			while( i < len1 && (str[i] >= '0' && str[i] <= '9' || str[i] == '.' )){
				putchar(str[i]);
				i++;
			}
			i--;
		}else if( str[i] == '(' ){
			Push(S, str[i]);
			if( str[i+1] == '+' || str[i+1] == '-'){
				putchar(' ');
				if( str[i+1] == '-')
					putchar('-');
				i+=2;
				while( i < len1 && (str[i] >= '0' && str[i] <= '9' || str[i] == '.' )){
					putchar(str[i]);
					i++;
				}
				i--;					
			}			
		}else if( str[i] == ')' ){
			while( GetTop(S) != '(' ){
				if( Nospace ){
					putchar(Pop(S));
					Nospace = 0;
				}else{
					putchar(' ');
					putchar(Pop(S));
				}				
			}
			Pop(S);
		}else{
			if( S->top == -1 && Nospace == 1 && str[i] == '-' )
			{
				putchar('-');

			}else if( S->top == -1 ){
				Push(S, str[i]);
				if( str[i+1] == '+' || str[i+1] == '-'){
					putchar(' ');
					if( str[i+1] == '-')
						putchar('-');
					i+=2;
					while( i < len1 && (str[i] >= '0' && str[i] <= '9' || str[i] == '.' )){
						putchar(str[i]);
						i++;
					}
					i--;					
				}				
			}else{
				if( Priority(str[i]) > Priority(GetTop(S)) )
					Push(S, str[i]);
				else{
					while( S->top != -1 && Priority(str[i]) <= Priority(GetTop(S)) ){
						if( Nospace ){
							putchar(Pop(S));
							Nospace = 0;
						}else{
							putchar(' ');
							putchar(Pop(S));
						}	
					}
					Push(S, str[i]);
				}
				if( str[i+1] == '+' || str[i+1] == '-'){
					putchar(' ');
					if( str[i+1] == '-')
						putchar('-');
					i+=2;
					while( i < len1 && (str[i] >= '0' && str[i] <= '9' || str[i] == '.' )){
						putchar(str[i]);
						i++;
					}
					i--;					
				}
			}
		}
	}
	while( S->top != -1 )
	{
		if( Nospace ){
			putchar(Pop(S));
			Nospace = 0;
		}else{
			putchar(' ');
			putchar(Pop(S));
		}	
	}
}

int main()
{
	int i = 0;
	char c;
	char str[21];
	// scanf("%s", &str);
	while( (c = getchar()) != '\n')
		str[i++] = c;
	str[i] = '\0';
	RPN(str);
	return 0;
}

/* 猜测的测试点
5个测试点都有小数
第4个测试点是括号开头有负数
*/