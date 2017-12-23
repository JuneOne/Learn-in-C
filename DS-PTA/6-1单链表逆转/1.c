#include <stdio.h>

int d = 6;
int *b = &d;
void f( int *a )
{
	a = b;
	// printf("%x\n", a);
	// printf("%x\n", b);
	// printf("%x\n", &a);
	// printf("%x\n", &b);
	*a = 5;
}
int main()  
{
	int a = 10;
	int *p = &a;
	// printf("%x\n", p);
	f(p);
	// printf("%x\n", p);
	printf("%d\n", *p);
	printf("%d\n", *b); 
}

/*
传过去的只是拷贝而已啊
值传递而已啊
你取到了地址而已
拷贝了一下这个指针而已啊
你改变指针本身的指向没关系的啊
额你要改变L的话应该传入L的地址啊，指向L的指针，这里是二级指针啊
你就把L的值拷贝了一下传给函数而已啊
*/