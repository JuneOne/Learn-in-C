#include <iostream>
#include <algorithm>
#include <string>
using namespace std ;
int cmp( string a , string b )
{
    return  (a+b) < (b+a);
}
int main() {
    int N ;
    cin>>N;
    string data[N] ;
    string s;
    for(int i = 0 ; i< N ; i++)
        cin>> data[i] ;
    sort(data , data+N , cmp);
    int count = 0 ;
    for(int i = 0 ; i< N ; i++){
        s += data[i] ;
    }

    while(s.size()!= 0 &&  s[0]=='0')
    {
        s.erase(s.begin()) ;
    }
    if(s.size() == 0 )
    {
        cout << 0<<endl ;
        return 0 ;
    }
    else cout<<s <<endl ;
    return 0 ;


}