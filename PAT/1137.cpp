#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct node{
	string name;
	int Gp;
	int Gmid;
	int Gfinal;
	int G;	
};

bool cmp( node a, node b )
{
	if( a.G == b.G )
		return a.name < b.name;
	else
		return a.G > b.G;	
}

int main()
{
	int P, M, N;
	string s;
	int grade; 
	map<string,node> mapStu;
	vector<node> result;
	map<string, node>::iterator it;
	scanf("%d%d%d", &P, &M, &N);
	for( int i = 0; i < P; i++ )
	{
		cin >> s >> grade;
		if( grade >= 200 ){
			node stu;
			stu.name = s;
			stu.Gp = grade;
			stu.Gmid = stu.Gfinal = -1;
			mapStu.insert(pair<string,node>(s, stu));
			// mapStu[s] = stu; 
		}
	}

	for( int i = 0; i < M; i++ ){
		cin >> s >> grade;
		if((it = mapStu.find(s)) != mapStu.end()) {
			it->second.Gmid = grade;
		}
	}
	for( int i = 0; i < N; i++ ){
		cin >> s >> grade;
		if((it = mapStu.find(s)) != mapStu.end()){
			it->second.Gfinal = grade;
		}
	}
	for( it = mapStu.begin(); it != mapStu.end(); it++ )
	{
		if( it->second.Gmid > it->second.Gfinal )
			it->second.G = (int)(0.4*it->second.Gmid + 0.6*it->second.Gfinal + 0.5);
		else
			it->second.G = it->second.Gfinal;
	}
	
	for( it = mapStu.begin(); it != mapStu.end(); it++ ){
		if( it->second.G >= 60 && it->second.G <= 100 ) 
			result.push_back(it->second);	
	} 
	sort(result.begin(), result.end(), cmp);
	for(vector<node>::iterator iit = result.begin(); iit != result.end(); iit++ )
		cout << iit->name << " " << iit->Gp << " " << iit->Gmid << " " << iit->Gfinal << " " << iit->G << endl;
}
