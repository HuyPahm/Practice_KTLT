#include <stdio.h>
inline int lonnhat(int a, int b, int c)
{
    int ln = a;
    if (b > ln)
        ln = b;
    if (c > ln)
        ln = c;
    return ln;
}

int main()
{
    int a, b, c;
    printf("Nhap : ");
    scanf("%d %d %d", &a, &b, &c);

    int max = lonnhat(a, b, c);
    printf("So lon nhat la: %d", max);

    return 0;
}
