#include <stdio.h>
#include <math.h>

int main()
{
	int i, j, K, N;
	int Queen[1000];
	scanf("%d", &K);
	int flag;
	while( K-- )
	{
		scanf("%d", &N);
		for( i = 0; i < N; i++ )
			scanf("%d", &Queen[i]);
		flag = 1;
		for( i = 0; i < N; i++ )
		{
			for( j = 0; j < N; j++ )
				if( Queen[j] == Queen[i] && i != j ){
					flag = 0;
					break;
				}
			if( flag == 0 )
				break;
			for( j = i+1; j < N; j++ )
				if( abs(Queen[j]-Queen[i]) == j-i ){
					flag = 0;
					break;
				}
			if( flag == 0 )
				break;
		}
		if( flag == 0 )
			printf("NO\n");
		else
			printf("YES\n");
	}

	return 0;
	
}