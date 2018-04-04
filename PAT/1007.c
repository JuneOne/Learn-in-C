#include <stdio.h>

int main()
{
	int i, N;
	int a[10000];
	scanf("%d", &N);
	int flag = 0;

	for( i = 0; i < N; i++ ){
		scanf("%d", &a[i]);
		if( a[i] >= 0 )
			flag = 1;
	}
	if( flag == 0 ){
		printf("0 %d %d\n", a[0], a[N-1]);
		return 0;
	}

	int sum = 0, max = -1;
	int left, right, nowleft = 0;

	for( i = 0; i < N; i++ )
	{
		sum += a[i];
		if ( sum > max ){
			max = sum;
			left = nowleft;
			right = i;
		} 
		if ( sum < 0 ) {
			sum = 0;
			nowleft = i + 1;
		}
		// printf("left = %d, right = %d, nowleft = %d\n", left, right, nowleft);
	}

	printf("%d %d %d\n", max, a[left], a[right]);

	return 0;
}
