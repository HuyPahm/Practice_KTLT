#include <stdio.h>
#define MAX 100000
int main()
{
    int n, sum = 0;
    do
    {
        printf("nhap 1 <= n <= %d: ", MAX);
        scanf("%d", &n);
    } while (n < 1 || n > MAX);
    // Phiên bản chưa tối ưu: lặp qua tất cả các số
    for (int i = 1; i <= n; 2)
        if (i % 2 == 0)
            sum += i;
    printf("Tong cac so chan tu 1 den %d la: %d\n", n, sum);
    return 0;
}