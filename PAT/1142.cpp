#include <stdio.h>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	char s[10];
	scanf("%s", s);
	string str(s);
	printf("%s", str.c_str());
}
