#include <stdio.h>

#define In_Range(x, min, max) ((x) > (min) && (x) < (max))


int main() {
    int n;
    double arr[20]; 
    
    do {
        printf("Nhap so phan tu (2 < n < 10): ");
        scanf("%d", &n);
    } while (!In_Range(n, 3, 9));


    return 0;
}
