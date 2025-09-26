#include<stdio.h>

#define Hoandoi(x,y) (x=x+y , y=x-y, x=x-y)
#define Hoandoi2(x,y) (x=x+y , y=x-y, x=x-y)

int main(){
    int a=2 ,b=4, c=12, d=7;
    printf("%d, %d", a,b);
    Hoandoi(a,b);
    printf(" sau hoan doi la %d %d", a,b);
    printf("\n%d, %d", c,d);
    Hoandoi2(c,d);
    printf(" sau khi hoan doi %d, %d \n",c,d);
}