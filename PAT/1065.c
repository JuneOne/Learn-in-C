#include <stdio.h>

int main()
{
	long long a, b, c;
	int i, T;
	long long result;
	scanf("%d", &T);
	for( i = 1; i <= T; i++ )
	{
		scanf("%lld%lld%lld", &a, &b, &c);
		// printf("a = %lld, b = %lld, c = %lld\n", a, b, c);
		result = a + b; 					/* 不大明白，主要就是可能会溢出的问题，还有就是a+b只有赋值后才可以检测是否溢出。
											   溢出只可能发生在两正数相加或者两负数相加时，所以把这两种溢出时的特殊情况拿出来单独考虑就可以了，
											   其他情况是可以直接a+b的
											*/
	
		printf("Case #%d: ", i);
		if( a > 0 && b > 0 && result <= 0 )
			printf("true\n");
		else if ( a < 0 && b < 0 && result >= 0 )
			printf("false\n");
		else if( result > c )
			printf("true\n");
		else 
			printf("false\n");
	}

	return 0;
}