#include <cstdio>

int main()
{
	long int N;
	scanf("%ld", &N);
	bool prim[N];
	for( long int i = 2; i < N; i++ ){
		if( prim[i] == true ){
			for( long int j = 2; i*j < N; j++ )
				prim[i*j] = false;
		}
	}
	bool flag = false;
	int len = N;
	printf("aaa");
	for( long int i = 2; i < len; i++ ){
		if( prim[i] == true ){
			int cnt = 0;
			while( N % i == 0 ){
				cnt++;
				N /= i;
			}
			if( cnt == 0 )
				continue;
			else if( cnt == 1 ){
				if( flag == false ){
					printf("%d", i);
					flag == true;
				} else {
					printf("*%d", i);
				}
			} else {
				if( flag == false ){
					printf("%d^%d", i, cnt);
					flag == true;
				} else {
					printf("*%d^%d", i, cnt);
				}
			}
		}
	}
	
}
