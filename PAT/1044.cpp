#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct Node{
	int start;
	int end;
};

int main()
{
	vector<int> V;
	vector<Node> V2;
	
	int N, Sum, value;
	int start, end, flag = 0;
	int min = 0;
	scanf("%d%d", &N, &Sum);
	for( int i = 0; i < N; i++){
		scanf("%d", &value);
		min += value;
		V.push_back(value);
	}
	min -= Sum;
	Node t;
	for( int i = 0; i < N; i++ ){
		int s = 0;
		for( int j = i; j < N; j++ ){
			s += V[j];
			if( s == Sum ){
				flag = 1;
				printf("%d-%d\n", i+1, j+1);
			} else if ( s > Sum && flag == 0 ) {
				if( s - Sum < min ){
//					cout << "i=" << i << " j=" << j << " s-sum="<<s-Sum << " clear"<< endl;
					V2.clear();
					t.start = i+1;
					t.end = j+1;
					V2.push_back(t);
					min = s - Sum;
				} else if ( s - Sum == min ){
					t.start = i+1;
					t.end = j+1;
					V2.push_back(t);
				};
			} else if ( s > Sum && flag == 1 )
				break;
		}
	}
	if( flag == 0 ){
		for( int i = 0 ; i < V2.size(); i++ )
			cout << V2[i].start << "-" << V2[i].end << endl;
	}
}
