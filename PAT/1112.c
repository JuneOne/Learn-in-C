#include <stdio.h>

typedef struct key Key;
struct key{
	char ch;
	int repeat;
};

Key c[37];
int cnt = 0;

int Find( char a )
{
	int i;
	for( i = 0; i < cnt; i++ )
	{
		if( c[i].ch == a )
			return i;
	}

	return -1;
}

int main()
{
	int i, j, k = 0, N;
	int index;
	char s[1001];
	scanf("%d", &N);
	scanf("%s", s);

	for( i = 0; s[i] != '\0'; i++ )
	{
		index = Find(s[i]);
		for( j = i+1; j <= i+N-1; j++){
			if( s[j] != s[i] )
				break;
		}
		if( j == i+N )
		{
			if( index == -1 )
			{
				c[cnt].ch = s[i];
				c[cnt].repeat = 1;
				cnt++;
			}
			i += N-1;
		} else {
			if( index != -1 )
			{
				c[index].repeat = 0;
			}
		}
	}

	for( i = 0; i < cnt; i++ )
	{
		if( c[i].repeat == 1 )
			putchar(c[i].ch);
	}
	putchar('\n');
	for( i = 0; s[i] != '\0'; i++ )
	{
		index = Find(s[i]);
		if( index != -1 && c[index].repeat == 1 ){
			putchar(s[i]);
			i += N-1;
		} else {
			putchar(s[i]);
		}
	}

	return 0;

}