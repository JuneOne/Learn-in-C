#include <iostream>  
#include <string.h>  
using namespace std;  
bool isPrime(int x){  
    if (x == 1) return false;  
    if (x == 2 || x == 3) return true;  
    for (int i = 2; i*i <= x; i++){  
        if (x%i == 0)  
            return false;  
    }  
    return true;  
}  
bool mark[10000];  
int main(){  
    int m, n, x, i;  
    cin >> m >> n;  
    memset(mark, false, sizeof(mark));  
    while (isPrime(m) == false) m++;  
    while (n--){  
        cin >> x;  
        for (i = 0; i < m; i++){  
                    	cout << "i=" << i << "\n";
            if (mark[(x + i*i)%m] == false){  

                cout << (x + i*i) % m << (n ? " " : "\n");  
                mark[(x + i*i) % m] = true;  
                break;  
            }  
        }  
        if (i == m)  
            cout << "-" << (n ? " " : "\n");  
    }  
    return 0;  
}  

