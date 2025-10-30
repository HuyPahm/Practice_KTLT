#include <stdio.h>
#include <math.h>

int SoNguyenTo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int UCLN(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int laSoArmstrong(int n) {
    int temp = n;
    int tong = 0;
    while (temp > 0) {
        int chuSo = temp % 10;// tách rớt từng số trong nó
        tong += chuSo * chuSo * chuSo; // mũ 3
        temp /= 10;
    }
    return (tong == n);
}

int main() {
    int n, a, b;

    printf("Kiem tra so nguyen to: ");
    scanf("%d", &n);
    if (SoNguyenTo(n))
        printf("%d la so nguyen to", n);
    else
        printf("%d khong phai la so nguyen to", n);

    printf("\nKiem tra UCLN: ");
    scanf("%d %d", &a, &b);
    printf("UCLN(%d, %d) = %d\n", a, b, UCLN(a, b));

    printf("\nKiem tra Armstrong: ");
    scanf("%d", &n);
    if (laSoArmstrong(n))
        printf("%d la so Armstrong.\n", n);
    else
        printf("%d khong phai la so Armstrong.\n", n);

    return 0;
}
