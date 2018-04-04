#include "stdio.h"
#include "stdlib.h"
typedef struct Node {
    int value ;
}Nodes;
typedef struct Q{
    int S ;
    int E ;
}QS;

int cmp(const void*a , const void* b )
{
    return ((Node*)a)->value - ((Node*)b)->value ;
}
int find(int start , int end )
{
    if(start ==end)
        return start ;
    int temp = end - start +1 ;
    int total = temp ;
    int jishu =1 ;
    while( temp >= jishu)
    {
        temp -= jishu ;
        jishu *=2 ;
    }

    int mid = (total - temp -1) /2 ;
    int Left;
    if(temp >= jishu/2)
        Left = mid + jishu/2  +start ;
    else
        Left = mid + temp +start ;
    return Left;
}

int main() {
    int num ;
    scanf("%d" , &num) ;
    QS queen[num] ;
    Nodes  data[num] ;
    for(int i = 0 ; i<num; i++)
        scanf("%d" , &data[i].value) ;
    qsort(data , num , sizeof(data[0] ) , cmp) ;
    int i= 0 ;
    int count =1 ;
    queen[0].S = 0 ;
    queen[0].E = num-1  ;
    int flag = 0 ;
    while(i<count)
    {
        int a1 =queen[i].S ;
        int a2 =queen[i].E;
        int mid = find(a1,a2) ;
        if(!flag++)
            printf("%d",data[mid].value) ;
        else
            printf(" %d",data[mid].value);
        if(a1 <= mid-1 )
        {
            queen[count].S = a1 ;
            queen[count++].E = mid-1 ;
        }
        if(mid+1 <=a2 )
        {
            queen[count ].S= mid +1 ;
            queen[count ++].E =a2;
        }
        i++ ;
    }
}
