#include <stdio.h>
#include <stdlib.h>

int main()
{
	int cnt[10001] = {0};
	int* value;
	int i, N;
	int flag = 0;

	scanf("%d", &N);
	value = (int*)malloc(sizeof(int)*N);
	for( i = 0; i < N; i++ ){
		scanf("%d", &value[i]);
		cnt[value[i]]++;
	}
	for( i = 0; i < N; i++ ){
		if( cnt[value[i]] == 1 ){
			flag = 1;
			break;
		}
	}
	if( flag == 0 ){
		printf("None\n");
	} else {
		printf("%d\n", value[i]);
	}

	return 0;
}