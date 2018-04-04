#include <stdio.h>

int main()
{
	char Mars[13] = {'0','1','2','3','4','5','6','7','8','9','A','B','C'};
	int Red, Green, Blue;
	scanf("%d%d%d", &Red, &Green, &Blue);
	putchar('#');
	putchar(Mars[Red/13]);
	putchar(Mars[Red%13]);
	putchar(Mars[Green/13]);
	putchar(Mars[Green%13]);
	putchar(Mars[Blue/13]);
	putchar(Mars[Blue%13]);

	return 0;
}