#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int M, N, K;
	scanf("%d%d%d", &M, &N, &K);
	while( K-- )
	{
		stack<int> S;
		int a = 1;
		bool flag = true;
		for( int i = 0; i < N; i++ )
		{
			int number;
			scanf("%d", &number);
			if( flag ){
				while( S.size() == 0 || S.top() != number )
				{
					S.push(a);
					a++;
					if( S.size() > M || a > N + 1){
						flag = false;
						break;
					}
				}
				if( flag && S.size() > 0 && S.top() == number )
					S.pop();
			}
		}
		if( flag )
			printf("YES\n");
		else
			printf("NO\n");
	}
}
