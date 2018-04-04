#include <cstdio>
#include <algorithm> 
#include <iostream>
#include <vector> 

using namespace std;
struct node{
	vector<int> Course;
}List[200000];

int CharToNum( char s[] )
{
	int i, hash = 0;
	for( i = 0; i < 3; i++ ){
		hash = 26*hash + (s[i]-'A');
	}
	hash = 10*hash + (s[3]-'0');
	return hash;
}


int main()
{
	int i, j, N, K;
	int index, number, stu;
	char str[5];
	scanf("%d%d", &N, &K);
	for( i = 0; i < K; i++ )
	{
		scanf("%d%d", &index, &number);
		getchar();
		for( j = 0; j < number; j++ ){
			scanf("%s", str);
			stu = CharToNum(str);
			List[stu].Course.push_back(index);
		}	
	}
	for( i = 0; i < N; i++ )
	{
		scanf("%s", str);
		stu = CharToNum(str);
		sort(List[stu].Course.begin(), List[stu].Course.end());
		printf("%s %d", str, List[stu].Course.size());
		for( j = 0; j < List[stu].Course.size(); j++ )
			printf(" %d", List[stu].Course[j]);
		printf("\n");
	}
}

