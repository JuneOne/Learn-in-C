#include <stdio.h>

int main()
{
	int i, j, index;
	int move = 0;
	char number[10000];
	scanf("%s", number);
	if( number[0] == '-' )
		putchar('-');
	for( index = 0; number[index] != 'E'; index++ );
	for( i = index+2; number[i] != '\0'; i++ ){
		move *= 10;
		move += number[i] - '0';
	}
	// printf("%d\n", move);
	if( number[index+1] == '-'){
		printf("0.");
		for( i = 1; i < move; i++ )
			printf("0");
		putchar(number[1]);
		for( i = 3; i < index; i++ )
			putchar(number[i]);
	} else {
		putchar(number[1]);
		for( i = 3; i < index && i - 2 <= move; i++ ){
			putchar(number[i]);
		}
		if( i == index ){
			for( j = 0; j <= move - i + 2; j++ )
				putchar('0');
		} else {
			putchar('.');
			for(; i < index; i++ )
				putchar(number[i]);
		}
	}
	printf("\n");

	return 0;
	
}