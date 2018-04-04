#include <cstdio>
#include <map>

using namespace std;

map<int, bool> mp;

int main()
{
	int N, a;
	scanf("%d", &N);
	for( int i = 0; i < N; i++ ){
		scanf("%d", &a);
		if( a > 0 )
			mp[a] = true;
	}
	int i;
	for( i = 1; i <= N; i++ ){
		if( mp[i] == false )
			break;
	}
	printf("%d\n", i);
	
	return 0;
}
