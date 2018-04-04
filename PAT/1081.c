#include <stdio.h>

typedef struct ration Ration;
struct ration{
	long int numerator;
	long int denominator;
};

long int gcd( long int a, long int b )
{
	long int i;
	if( a < 0 )
		a = -a;
	if( a == 0 )
		return 1;
	for( i = a < b ? a : b; i >= 1; i-- )
		if( a % i == 0 && b % i == 0 )
			return i;
}

int main()
{
	int N;
	long int g;
	long int integer;
	Ration temp;
	Ration sum;
	sum.numerator = 0;
	sum.denominator = 1;
	scanf("%d", &N);
	while( N-- )
	{
		scanf("%ld/%ld", &temp.numerator, &temp.denominator);
		sum.numerator = sum.numerator*temp.denominator + sum.denominator*temp.numerator;
		sum.denominator = sum.denominator * temp.denominator;
		g = gcd(sum.numerator, sum.denominator);
		sum.numerator /= g;
		sum.denominator /= g;
	}
	if( sum.numerator >= sum.denominator ){
		integer = sum.numerator / sum.denominator;
		sum.numerator -= integer * sum.denominator;
		if( sum.numerator == 0 )
			printf("%ld\n", integer);
		else
			printf("%ld %ld/%ld\n", integer, sum.numerator, sum.denominator);
	} else {
		if( sum.numerator == 0 )
			printf("%ld\n", sum.numerator);
		else
			printf("%ld/%ld\n", sum.numerator, sum.denominator);
	}
	// printf("numerator = %ld, denominator = %ld", sum.numerator, sum.denominator);

	return 0;
}