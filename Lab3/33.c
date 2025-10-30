#include <stdio.h>
#include <math.h>
#define MAX 50

// a) Hàm nhập đệ quy
void nhapMang(int a[], int n, int i = 0) {
    if (i == n) 
        return;
    printf("Nhap a[%d]: ", i);
    scanf("%d", &a[i]);
    nhapMang(a, n, i + 1);
}

// b) Hàm đếm phần tử chẵn bằng đệ quy
int demChan(int a[], int n) {
    if (n == 0) 
        return 0;
    if (a[n - 1] % 2 == 0)
        return 1 + demChan(a, n - 1);
    else
        return demChan(a, n - 1);
}

// Hàm kiểm tra số nguyên tố (đệ quy phụ)
int laNguyenTo(int n, int i = 2) {
    if (n < 2) 
        return 0;
    if (i > sqrt(n)) 
        return 1;
    if (n % i == 0) 
        return 0;
    return laNguyenTo(n, i + 1);
}

// c) Kiểm tra dãy có chứa số nguyên tố hay không (đệ quy)
int coNguyenTo(int a[], int n) {
    if (n == 0) 
        return 0;
    if (laNguyenTo(a[n - 1])) 
        return 1;
    return coNguyenTo(a, n - 1);
}

// d) Tìm vị trí đầu tiên của phần tử x trong dãy số
int timViTriDauTien(int a[], int n, int x, int i = 0) {
    if (i == n) 
        return -1;  // không tìm thấy
    if (a[i] == x) 
        return i;
    return timViTriDauTien(a, n, x, i + 1);
}


int main() {
    int a[MAX], n, x;

    // Nhập dãy số
    do {
        printf("Nhap so phan tu n (2 ≤ n < 50): ");
        scanf("%d", &n);
    } while (n < 2 || n >= 50);

    printf("\n=== NHAP DAY SO ===\n");
    nhapMang(a, n);

    // In kết quả
    printf("\n=== KET QUA ===\n");
    printf("So phan tu chan: %d\n", demChan(a, n));

    if (coNguyenTo(a, n))
        printf("Day co chua so nguyen to.\n");
    else
        printf("Day KHONG co so nguyen to.\n");

    if (n > 3 && n < 20) {
        printf("\nNhap x can tim: ");
        scanf("%d", &x);
        int vt = timViTriDauTien(a, n, x);
        if (vt == -1)
            printf("Khong tim thay %d trong day.\n", x);
        else
            printf("Phan tu %d xuat hien dau tien o vi tri %d.\n", x, vt);
    }

    return 0;
}
