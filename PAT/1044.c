#include <stdio.h>

struct node{
	int start;
	int end;
}M[1000];

int cnt = 0;

int main()
{
	int i, j, N, Sum, value, flag = 0;
	scanf("%d%d", &N, &Sum);
	int s[N+1];
	s[0] = 0;
	for( i = 1; i <= N; i++ ){
		scanf("%d", &value);
		s[i] = s[i-1]+value;
	}
	int min = s[N]-Sum;
	for( i = 1; i <= N; i++ ){
		for( j = i; j <= N; j++ ){
			if( s[j]-s[i-1] == Sum ){
				printf("%d-%d\n", i, j); 
				min = 0;
			} else if ( s[j]-s[i-1] > Sum ){
				if( s[j]-s[i-1] - Sum < min ){
					cnt = 0;
					M[cnt].start = i;
					M[cnt].end = j;
					cnt++;
					min = s[j] - s[i-1] - Sum;
				} else if ( s[j]-s[i-1] - Sum  == min ){
					M[cnt].start = i;
					M[cnt].end = j;
					cnt++;
				}
			} else if( s[j]-s[i-1] > Sum && flag == 1 )
				break;
		}
	}
	if( flag == 0 ){
		for( i = 0; i < cnt; i++ )
			printf("%d-%d\n", M[i].start, M[i].end);
	}
}
