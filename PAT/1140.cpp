#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int D, N;
	vector<int> V1, V2;
	cin >> D >> N;
	V1.push_back(D);
	N--;
	while( N-- )
	{	
		for( int i = 0; i < V1.size(); i++ ){
			int number = V1[i];
			int cnt = 1;
			V2.push_back(number);
			for( int j = i+1; j < V1.size() ; j++ ){
				if( V1[i] != V1[j] ){
					break;
				} else {
					cnt++;
					i++;
				}
			}
			V2.push_back(cnt);
		}
		V1.clear();
		V1 = V2;
		V2.clear();	
	}
	for( int i = 0; i < V1.size(); i++ )
		cout << V1[i];
	cout << endl;		

	return 0;
}
