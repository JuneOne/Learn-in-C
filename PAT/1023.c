#include <stdio.h>

int main()
{
	char number[20];
	int newnumber[21] = {0};
	int cnt[10] = {0};
	char c;
	int len = 0, len2;
	int i, j = 0;

	while( ( c = getchar() ) != '\n' )
		number[len++] = c;
	for( i = 0; i < len; i++ )
		cnt[number[i]-'0']++;
	// for( i = 0; i < 10; i++ )
	// 	printf("%d:%d\n", i, cnt[i]);
	for( i = len-1; i >= 0; i--, j++ ){
		if( 2*(number[i]-'0') > 9 ){
			newnumber[j] += 2 * (number[i]-'0') - 10;
			newnumber[j+1]++;
		} else {
			newnumber[j] += 2 * (number[i]-'0');
		}
		if( newnumber[j] > 9 ){
			newnumber[j] -= 10;
			newnumber[j+1]++;
		}
	}
	if( newnumber[j] != 0 )
		len2 = j+1;
	else
		len2 = j;

	for( i = 0; i < len2; i++ )
		cnt[newnumber[i]]--;
	for( i = 0; i < 10; i++ ){
		if( cnt[i] != 0 )
			break;
	}
	if( i == 10 ){
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	for( i = len2-1; i >= 0; i-- )
		printf("%d", newnumber[i]);

	return 0;
}