#include <stdio.h> 
#define MAX 50 
// Hàm in dãy số ra màn hình 
void inday(float a[], int n){
    for (int i=0;i<n;i++){
        printf("%.1f ", a[i]);
    }
}
// Hàm đếm và trả về số lượng phần tử lớn hơn x trong dãy số theo kỹ thuật chia để trị 
int  demlonhonx (float a[], int l, int r, int x){
    if(l==r){
        if(a[l]>x){
            return 1;
        }else return 0;
    }
    int m= (l+r)/2;
    float trai= demlonhonx(a,l,m,x);
    float phai= demlonhonx(a,m+1,r,x);
    return trai +phai;
}
// Hàm tính và về tổng các phần tử ở vị trí chẵn trong dãy số theo kỹ thuật chia để trị 
int main() { 
float a[] = {3.5, 7.1, 9.5, 1.1, 2.4}; 
int n = sizeof(a)/sizeof(a[0]); 
int x = 5.0;
// Gọi hàm in dãy số ra màn hình 
inday(a,n);
// Gọi các hàm     
float lonX = demlonhonx(a,0,n-1,x);
printf("phan tu lon hon X la %.1f",lonX);
 
return 0; 
}