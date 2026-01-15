#include <stdio.h>

long long giaithua(int n) {
    if (n == 1) return 1;
    return n * giaithua(n - 1);
}

void toBinary(int n) {
    if (n == 0) return;
    toBinary(n / 2);
    printf("%d", n % 2);
}

long long pell(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return 2 * pell(n - 1) + pell(n - 2);
}

double tongNghichDao(int n) {
    if (n == 2) return 1.0 / 2;
    return tongNghichDao(n - 1) + 1.0 / n;
}

long long luythua(int a, int b) {
    if (b == 0) return 1;
    return a * luythua(a, b - 1);
}

long long tongLuyThua(int n) {
    if (n == 1) return luythua(1, 2);
    return tongLuyThua(n - 1) + luythua(n, n + 1);
}

int UCLN(int a, int b) {
    if (b == 0) return a;
    return UCLN(b, a % b);
}

long long tongGiaiThua(int n) {
    if (n == 1) return 1;
    return tongGiaiThua(n - 1) + giaithua(n);
}

long long fibo(int n) {
    if (n <= 2) return 1;
    return fibo(n - 1) + fibo(n - 2);
}

long long tongFibo(int n) {
    if (n == 1) return 1;
    return tongFibo(n - 1) + fibo(n);
}

double tongPhanSo(int n) {
    if (n == 1) return 1.0 / 2;
    return tongPhanSo(n - 1) + (double)n / (n + 1);
}

long long tongNhan(int n) {
    if (n == 1) return 1 * 2;
    return tongNhan(n - 1) + (long long)n * (n + 1);
}

int main() {
    printf("a) %lld\n", giaithua(5));
    printf("b) "); toBinary(10); printf("\n");
    printf("c) %lld\n", pell(6));
    printf("d) %lf\n", tongNghichDao(5));
    printf("e) %lld\n", tongLuyThua(4));
    printf("f) %d\n", UCLN(48, 18));
    printf("g) %lld\n", tongGiaiThua(5));
    printf("h) %lld\n", tongFibo(6));
    printf("i) %lf\n", tongPhanSo(5));
    printf("j) %lld\n", tongNhan(5));
    return 0;
}
