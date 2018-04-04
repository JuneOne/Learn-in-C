#include <stdio.h>

typedef struct card Card;
struct card
{
	char c;
	int value;	
};

Card deck[54];
int order[54];
Card newdeck[54];

void Function()
{
	int i;
	for( i = 0; i < 54; i++ )
		newdeck[order[i]-1] = deck[i];
	for( i = 0; i < 54; i++ )
		deck[i] = newdeck[i];
}

int main()
{
	int i, K;
	for( i = 0; i < 13; i++ ){
		deck[i].c = 'S';
		deck[i+13].c = 'H';
		deck[i+26].c = 'C';
		deck[i+39].c = 'D';
		deck[i].value = deck[i+13].value = deck[i+26].value = deck[i+39].value = i+1;
	}
	deck[52].c = deck[53].c = 'J';
	deck[52].value = 1;
	deck[53].value = 2;

	scanf("%d", &K);
	for( i = 0; i < 54; i++ )
		scanf("%d", &order[i]);
	while( K-- )
		Function();

	printf("%c%d", deck[0].c, deck[0].value);
	for( i = 1; i < 54; i++ )
		printf(" %c%d", deck[i].c, deck[i].value);

	return 0;
}