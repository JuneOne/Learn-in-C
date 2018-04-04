#include <stdio.h>

typedef struct ration Ration;
struct ration{
	long int numerator;
	long int denominator;
};

long int gcd( long int x, long int y )
{
	// long int i;
	if( x < 0 )
		x = -x;
	// if( x == 0 )
	// 	return 1;
	// for( i = x < y ? x : y; i >= 1; i-- )
	// 	if( x % i == 0 && y % i == 0 )
	// 		return i;
	return y == 0 ? x : gcd(y, x % y);
}

void Print( Ration a )
{
	int flag = 0;
	long int integer;
	if( a.numerator < 0 ){
		flag = 1;
		a.numerator = -a.numerator;
	}
	if( a.numerator >= a.denominator ){
		integer = a.numerator / a.denominator;
		a.numerator -= integer * a.denominator;
		if( flag == 1 ){
			if( a.numerator == 0 )
				printf("(-%ld)", integer);
			else
				printf("(-%ld %ld/%ld)", integer, a.numerator, a.denominator);
		} else {
			if( a.numerator == 0 )
				printf("%ld", integer);
			else
				printf("%ld %ld/%ld", integer, a.numerator, a.denominator);
		}
	} else {
		if( a.numerator == 0 )
			printf("%ld", a.numerator);
		else {
			if( flag == 1 )
				printf("(-%ld/%ld)", a.numerator, a.denominator);
			else
				printf("%ld/%ld", a.numerator, a.denominator);
		}
	}
}

void Add( Ration a, Ration b )
{
	long int g;
	Ration res;
	Print(a);
	printf(" + ");
	Print(b);
	printf(" = ");
	res.numerator = a.numerator*b.denominator + a.denominator*b.numerator;
	res.denominator = a.denominator * b.denominator;
	g = gcd(res.numerator, res.denominator);
	res.numerator /= g;
	res.denominator /= g;
	Print(res);
	putchar('\n');
}

void Difference( Ration a, Ration b )
{
	long int g;
	Ration res;
	Print(a);
	printf(" - ");
	Print(b);
	printf(" = ");
	res.numerator = a.numerator*b.denominator - a.denominator*b.numerator;
	res.denominator = a.denominator * b.denominator;
	g = gcd(res.numerator, res.denominator);
	res.numerator /= g;
	res.denominator /= g;
	Print(res);
	putchar('\n');
}

void Product( Ration a, Ration b )
{
	long int g;
	Ration res;
	Print(a);
	printf(" * ");
	Print(b);
	printf(" = ");
	res.numerator = a.numerator * b.numerator;
	res.denominator = a.denominator * b.denominator;
	g = gcd(res.numerator, res.denominator);
	res.numerator /= g;
	res.denominator /= g;
	Print(res);
	putchar('\n');
}

void Quotient( Ration a, Ration b )
{
	long int g;
	Ration res;
	Print(a);
	printf(" / ");
	Print(b);
	printf(" = ");
	if( b.numerator == 0 )
		printf("Inf\n");
	else{
		res.numerator = a.numerator * b.denominator;
		res.denominator = a.denominator * b.numerator;
		if( res.denominator < 0 ){
			res.numerator = -res.numerator;
			res.denominator = -res.denominator;
		}
		g = gcd(res.numerator, res.denominator);
		res.numerator /= g;
		res.denominator /= g;
		Print(res);
		putchar('\n');	
	}
}

int main()
{
	Ration a, b;
	long int g;
	scanf("%ld/%ld", &a.numerator, &a.denominator);
	scanf("%ld/%ld", &b.numerator, &b.denominator);
	g = gcd(a.numerator, a.denominator);
	a.numerator /= g;
	a.denominator /= g;
	g = gcd(b.numerator, b.denominator);
	b.numerator /= g;
	b.denominator /= g;	
	Add(a, b);
	Difference(a, b);
	Product(a, b);
	Quotient(a, b);

	return 0;
}