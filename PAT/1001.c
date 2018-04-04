#include <stdio.h>
// #include <stdlib.h>

void f( int x );
int main()
{
	int a, b;
	int c;
	scanf("%d%d", &a, &b);
	c = a + b;
	if( c < 1000 && c > -1000 )
		printf("%d", c);
	else{
		f(c);
	}
}

void f( int x ){
	int toString[10];
	int length = 0;
	int flag = 0;
	int i, j, cnt = 0;
	// int n = x;
	if( x < 0 ){
		flag = 1;
		x = -x;
	}
	while(x){
		toString[length++] = x % 10;
		x /= 10;
	}
	// printf("length = %d\n", length);
	// l = length % 3;
	if( flag == 1 ){
		putchar('-');
	}
	for( i = length % 3, j = length-1 ; i > 0; i-- ){
		printf("%d", toString[j--]);
	}
	if( length % 3 != 0 )
		putchar(',');
	for( ; j >= 0; j-- ){
		printf("%d", toString[j]);
		cnt++;
		if( cnt % 3 == 0 && j != 0 )
			putchar(',');
		// printf("cnt = %d\n", cnt);
	}
}