#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
	vector<int> Stu;
};
int CharToNum( char s[] )
{
	int hash = 0;
	for( int i = 0; i < 3; i++ )
		hash = 26*hash + (s[i]-'A');
	hash = hash*10 + (s[3]-'0');
	
	return hash;
}

void NumToChar( int N, char s[] )
{
	s[4] = '\0';
	s[3] = N % 10 + '0';
	N /= 10;
	for( int i = 2; i >= 0; i-- ){
		s[i] = N % 26 + 'A';
		N /= 26;
	}
	
}

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	Node Course[K+1];
	for( int i = 0; i < N; i++ ){
		char str[5];
		int number;
		scanf("%s %d", str, &number);
		int hash = CharToNum(str);
		for( int j = 0; j < number; j++ ){
			int index;
			scanf("%d", &index);
			Course[index].Stu.push_back(hash);
		}
		getchar();
	}
	for( int i = 1; i <= K; i++ ){
		sort(Course[i].Stu.begin(), Course[i].Stu.end());
		printf("%d %d\n", i, Course[i].Stu.size());
		for( int j = 0; j < Course[i].Stu.size(); j++ ){
			char s[5];
			NumToChar( Course[i].Stu[j], s );
			printf("%s\n", s); 
		}
	}
}
