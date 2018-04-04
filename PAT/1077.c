#include <stdio.h>

int main()
{
	int len1, len2;
	int i, N;
	char c; 
	char str1[257], str2[257];
	
	scanf("%d", &N);
	getchar();
	i = 0;
	while( (c=getchar()) != '\n' )
		str1[i++] = c;
	len1 = i;
	N--;
	while( N-- )
	{
		i = 0;
		while( (c=getchar()) != '\n' )
			str2[i++] = c;
		len2 = i;
		for( i = 0; i < len1 && i < len2; i++ ){
			if( str1[len1-1-i] != str2[len2-1-i] )
				break;
		}
		len1 = i;
		if( i == 0 )
			break;
		str1[len1] = '\0';
		for( i = len1-1; i >= 0; i-- )
			str1[i] = str2[len2-(len1-i)];
	}
	if( len1 != 0 ){
		for( i = 0; i < len1; i++ )
			putchar(str1[i]);
		putchar('\n');
	} else {
		printf("nai\n");
	}

}