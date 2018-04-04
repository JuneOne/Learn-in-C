#include <stdio.h>  
#include <stdlib.h>  
#include <math.h>  
// #include <string.h>  
 
int cmp1(const void * a,const void * b)  
{  
    return (*(int*)a-*(int*)b);//a>b 返回正值  
}  

int cmp2(const void * a,const void *b)  
{  
    return(*(char*)a-*(char*)b);  
}  

int cmp3(const void * a,const void * b)  
{  
    if(fabs(*(double*)a-*(double *)b)<1*exp(-20))  
        return 0;  
    else  
        return(((*(double*)a-*(double*)b)>0)?1:-1);  
}  

int main(void)  
{  
    int i;  
    int a[10]={0,1,2,66,4,5,6,17,8,9};  
    char b[10]={'a','b','c','z','e','f','g','h','i','j'};  
    double c[10]={0.1,0.2,0.9,0.5,0.3,0.6,0.7,0.8,1.1,1.2};  

    qsort(&a[3],5,sizeof(int),&cmp1);//对于函数指针（指向函数的指针），直接传入函数名和函数名进行&  
                                  //运算都是可以的，因为在调用函数时也是取的函数的地址  
    qsort(b,10,sizeof(char),cmp2);  
    qsort(c,10,sizeof(double),cmp3);  
    for(i=0;i<10;i++)  
        printf("%d ",a[i]);
    putchar('\n');  
    for(i=0;i<10;i++)  
        printf("%04c ",b[i]);  
    putchar('\n'); 
    for(i=0;i<10;i++)  
        printf("%05.2f ",c[i]);  
    putchar('\n'); 
}  