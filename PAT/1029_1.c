#include "stdio.h"

int a[100000];
int b[100000];

void find( int start, int end, int start2, int end2 ){
    int num = end  - start;
    int num2 = end2 - start2;
    int mid = start + num/2;
    int mid2 = start2 + num2/2;
    if( num == 0 ) {
        printf("%d", a[start] < b[start2] ? a[start] : b[start2]);
        return ;
    }
    if( a[mid] < b[mid2] ) {
        if(num%2==1)
            find(mid + 1, end, start2, mid2);
        else
            find(mid , end , start2 , mid2 ) ;

    }
    else if(a[mid] > b[mid2]) {
        if(num%2 == 1 )
            find(start, mid, mid2 + 1, end2);
        else
            find(start,mid , mid2 , end2 ) ;
    }
}

int main() {
    int i, N, M;
    scanf("%d" , &N) ;
    for(i = 0 ; i< N ; i++ )
        scanf("%d" , &a[i]) ;
    scanf("%d", &M);
    for(i = 0 ; i< M ; i++ )
        scanf("%d" , &b[i]) ;
    find( 0, N-1  , 0 , M-1) ;

}
