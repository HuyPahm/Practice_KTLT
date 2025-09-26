#include <stdio.h>
int main()
{
    // nhập số n
    int n;
    printf("nhap n:");
    scanf("%d", &n);
    long sum = n * (n + 1) / 2;
    printf("Tong = %ld\n", sum);
    return 0;
}

