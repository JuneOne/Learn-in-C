#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct node{
	char name[10];
	int age;
	int worth;
}Peo[100000];

bool cmp( struct node a, struct node b )
{
	if( a.worth == b.worth ){
		if( a.age == b.age )
			return strcmp(a.name, b.name) < 0;
		else
			return a.age < b.age;
	} else 
		return a.worth > b.worth;
}

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	getchar();
	for( int i = 0; i < N; i++ ){
		scanf("%s%d%d", Peo[i].name, &Peo[i].age, &Peo[i].worth);
		getchar();
	}
	sort(Peo, Peo+N, cmp);
	for( int i = 0; i < K; i++ ){
		int cnt, Amin, Amax;
		bool flag = false;
		scanf("%d%d%d", &cnt, &Amin, &Amax);			
		printf("Case #%d:\n", i+1);
		for( int j = 0; j < N && cnt > 0 ; j++ ){
			if( Peo[j].age >= Amin && Peo[j].age <= Amax ){
				printf("%s %d %d\n", Peo[j].name, Peo[j].age, Peo[j].worth);
				cnt--;
				flag = true;
			}
		}
		if( flag == false )
			printf("None\n");
	}
}
