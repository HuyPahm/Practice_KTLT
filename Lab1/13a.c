#include <stdio.h>
#include <stdlib.h>

void Ttoan(int a, int b, char c){
    float dau;
    switch(c){
    case '+': dau = a+b; break;
    case '-': dau = a-b; break;
    case '*': dau = a*b; break;
    case '/': 
    if (b!=0) dau = (float)a/b;
}
    printf("%d %c %d = %.2f", a,c,b,dau);
}
int main(int c , char* v [])
{
    if (c ==4){
        int a = atoi(v[1]);
        char c = *v[2];
        int b = atoi(v[3]);
        Ttoan(a,b,c);
    }else{
        printf("sai");
    }
}