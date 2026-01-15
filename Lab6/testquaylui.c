#include<stdio.h>
#define N 50
int n,S;
int x [N];
int a [N];

void kiemtra(){
    int sum =0;
    for (int i=1 ;i<=n;i++){
        if (x[i]==1){
            sum = sum + a[i];
        }
    }
    if( sum ==S){
        for (int i=1 ;i<=n;i++){
            if (i==1){
                printf("%d", a[i]);
            }
        }
    }
}

void Try(int i){
    for (int j=0;j<=n;j++){
        x[i]=j;
        if(i==n){
            kiemtra();
        }else
            Try(i+1);
    }
}
int main(){
    printf("nhap n, S: ");
    scanf("%d %d ", &n, &S);
    
    return 0;
}