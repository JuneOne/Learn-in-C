#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	char c;
	vector<char> v1;
	while( (c=getchar()) != '\n' )
		v1.push_back(c);
	vector<char> v2(v1);
	reverse(v2.begin(), v2.end());
	int max = 0, temp;
	for( vector<char>::iterator it = v1.begin(); it != v1.end(); it++ ){
		for( vector<char>::iterator itt = v2.begin(); itt != v2.end(); itt++ ){
			if( *it == *itt ){
				temp = 1;
				for( int k = 1; it+k != v1.end() && itt+k != v2.end(); k++ ){
					if( *(it+k) == *(itt+k) ){ // 若用 != 来判断 并且 temp += k-1; 会出现aaaa这种问题 
						temp++;
					} else
						break;
				}
				if( temp > max )
					max = temp;
			}
		}
	}
	cout << max << endl;

}
