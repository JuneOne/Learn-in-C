#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
 
using namespace std;

struct node{
	string sname;
	int A;
	int B;
	int T;
	int tws;
	int cnt;
	int rank;	
};

bool cmp( node a, node b )
{
	if( a.tws != b.tws )
		return a.tws > b.tws;
	else if( a.cnt != b.cnt )
		return a.cnt < b.cnt;
	else
		return a.sname < b.sname;		
}

int main()
{
	int N;
	string stu, sch;
	int grade;
	map<string,int> M;
	vector<node> V;
	map<string,int>::iterator it;
	cin >> N;
	while( N-- ){
		cin >> stu >> grade >> sch;
		for( int i = 0; i < sch.size(); i++ ){
			if( sch[i] >= 'A' && sch[i] <= 'Z' )
				sch[i] += 'a' - 'A';
		}
		if( (it = M.find(sch)) == M.end() ){
			M.insert(pair<string,int>(sch, V.size()));
			node t;
			t.sname = sch;
			t.A = 0; t.B = 0; t.T = 0;
			if( stu[0] == 'A' ) t.A = grade;
			if( stu[0] == 'B' ) t.B = grade;
			if( stu[0] == 'T' ) t.T = grade;
			t.tws = 0;
			t.cnt = 1;
			V.push_back(t);
		} else {
			if( stu[0] == 'A' ) V[it->second].A += grade;
			if( stu[0] == 'B' ) V[it->second].B += grade;
			if( stu[0] == 'T' ) V[it->second].T += grade;
			V[it->second].cnt++;
		}
	}
	for( int i = 0; i < V.size(); i++ )
		V[i].tws = (int)(V[i].B*1.0/1.5 + V[i].A + V[i].T*1.5);
	sort(V.begin(), V.end(), cmp);
	V[0].rank = 1;
	for( int i = 1; i < V.size(); i++ ){
		if( V[i].tws == V[i-1].tws )
			V[i].rank = V[i-1].rank;
		else
			V[i].rank = i+1;
	}
	printf("%d\n", V.size());
	for( int i = 0; i < V.size(); i++ )
		printf("%d %s %d %d\n", V[i].rank, V[i].sname.c_str(), V[i].tws, V[i].cnt);
		
	return 0;
}
