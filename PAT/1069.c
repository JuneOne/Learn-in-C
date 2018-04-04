#include <stdio.h>

int a[4] = {0};

int Number()
{
	int i;
	int sum = 0;
	for( i = 0; i < 4; i++ )
		sum = 10*sum + a[i];
	return sum;
}

void Calculate()
{
	int max[4], min[4];
	int temp[4] = {0};
	int i, j, tmp;
	for( i = 0; i < 4; i++ ){
		max[i] = a[i];
		min[i] = a[i];
	}
	for( i = 0; i < 4; i++ ){
		for( j = 0; j < 3-i; j++ ){
			if( max[j] < max[j+1] ){
				tmp = max[j];
				max[j] = max[j+1];
				max[j+1] = tmp;
			}
		}
	}
	for( i = 0; i < 4; i++ ){
		for( j = 0; j < 3-i; j++ ){
			if( min[j] > min[j+1] ){
				tmp = min[j];
				min[j] = min[j+1];
				min[j+1] = tmp;
			}
		}
	}

	for( i = 3; i >= 0; i-- ){
		if( max[i] < min[i] ){
			temp[i-1]--;
			temp[i] += max[i] - min[i] + 10;
		} else {
			temp[i] += max[i] - min[i];
		}
		if( temp[i] < 0 ){
			temp[i] += 10;
			temp[i-1]--;
		}
	}
	for( i = 0; i < 4; i++ ){
		a[i] = temp[i];
	}
	for( i = 0; i < 4; i++ )
		printf("%d", max[i]);
	printf(" - ");
	for( i = 0; i < 4; i++ )
		printf("%d", min[i]);
	printf(" = ");
	for( i = 0; i < 4; i++ )
		printf("%d", temp[i]);
	printf("\n");

}

int main()
{
	char c;
	int i = 0;
	int number;
	while( (c = getchar()) != '\n' )
		a[i++] = c-'0';
	if( a[0] == a[1] && a[1] == a[2] && a[2] == a[3] ){
		number = Number();
		printf("%d - %d = 0000\n", number, number);
	} else if ( Number() == 6174 ){
		Calculate();
	} else{
		while( Number() != 6174){
			Calculate();
		}
	}

	return 0;
}