#include <stdio.h>
#include <math.h>
int tongChan (int n){
    if(n ==0)
        return 0;
    else
        return tongChan(n-2) +n;
}
int tongChuSo(int n){
    if(n ==0)
        return 0;
    else
        return tongChuSo(n/10) +n%10;
}
double tongHH(int a, int r, int n){
    if(n ==0)
        return a;
    else
        return a*pow(r,n) +tongHH(a,r,n-1);
}
int tongChia3(int n) {
    if (n < 3)
        return 0;
    if (n % 3 == 0)
        return n + tongChia3(n - 1);
    else
        return tongChia3(n - 1);
}

double tongPS(int n){
    if(n ==1)
        return 1.0;
    else
        return 1.0/n +tongPS(n-1);
}
int main() {
    int n = 10;

    printf("Tong chan tu 1..%d = %d\n", n, tongChan(n));
    printf("Tong chu so cua %d = %d\n", 1234, tongChuSo(1234));
    printf("Tong cap so nhan (a=2,r=3,n=4) = %.2f\n", tongHH(2, 3, 4));
    printf("Tong cac so chia het cho 3 tu 1..%d = %d\n", n, tongChia3(n));
    printf("Tong phan so 1 + 1/2 + ... + 1/%d = %.4f\n", n, tongPS(n));

    return 0;
}