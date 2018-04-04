#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

struct Node{
	char res[110];
	int exp;
};

int N;

Node Function( char s[] )
{
	Node ans;
	int Value = -1, Dot = -1;
	int index  = 0;
	for( int i = 0; s[i] != '\0'; i++ )
	{
		if( s[i] == '0' && Value == -1 )
			continue;
		if( s[i] == '.' ){
			Dot = i;
			continue;
		}
		if( Value == -1 )
			Value = i;
		if( index < N )
			ans.res[index++] = s[i];
//		else     // ���ܻ�ʹ��'.'û���� 
//			break;
	}
//	printf(" Value = %d, Dot = %d\n", Value, Dot);
	if( Dot == -1 )
		Dot = strlen(s);
	while( index < N ){
		ans.res[index++] = '0';
	}
	ans.res[index] = '\0';
	if( N == 0 || Value == -1 ) // ������0��Ŀ����û���ǣ�ȫ0
		ans.exp = 0;
	else{
		if( Value < Dot ){
			ans.exp = Dot - Value;
		} else {
			ans.exp = Dot - Value + 1; // ָ��Ӧ���Ǹ��� 
		}
	}
	
	return ans;
}

int main()
{
	char A[110], B[110];
	scanf("%d%s%s", &N, A, B);
	Node a = Function(A);
	Node b = Function(B);
	if( strcmp(a.res, b.res) == 0 && a.exp == b.exp )
		printf("YES 0.%s*10^%d\n", a.res, a.exp);
	else
		printf("NO 0.%s*10^%d 0.%s*10^%d\n", a.res, a.exp, b.res, b.exp);

	return 0;
}
