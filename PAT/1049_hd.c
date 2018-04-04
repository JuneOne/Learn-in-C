#include "stdio.h"

int main() {
    int N ;
    scanf("%d" , &N ) ;
    int chushu =1 ;
    int count = 0 ;
    while( N /chushu != 0 )
    {
        count += N/(chushu*10) *chushu ;
        if( N%(chushu*10) >= chushu && N%(chushu*10) < 2*chushu)
            count += N%(chushu*10) - chushu +1 ;
        else if(N%(chushu*10) >= 2*chushu)
            count += chushu ;
        chushu *=10 ;
    }
    printf("%d" , count) ;
}
