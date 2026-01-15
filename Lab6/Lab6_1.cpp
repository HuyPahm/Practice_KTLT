//bai6.1
#include <stdio.h>

int n, k, m;
int x[100];   // luu chuoi nhi phan

void quay_lui(int i, int mot, int khong) {
    // Neu du n ky tu
    if (i == n) {
        if (mot == k) {
            for (int i = 0; i < n; i++)
                printf("%d", x[i]);
            printf("\n");
        }
        return;
    }

    // Cat nhanh: khong dat k so 1
    if (mot + (n - i) < k) return;

    // Thu dat 0
    if (khong < m - 1) {
        x[i] = 0;
        quay_lui(i + 1, mot, khong + 1);
    }

    // Thu dat 1
    if (mot < k) {
        x[i] = 1;
        quay_lui(i + 1, mot + 1, 0);
    }
}

int main() {
    printf("Nhap n, k, m: ");
    scanf("%d %d %d", &n, &k, &m);

    quay_lui(0, 0, 0);
    return 0;
}

