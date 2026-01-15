#include <stdio.h>
#define MAX 50

int docFile(float a[], int &n);
void inDaySo(float a[], int n);
float tongViTriLe(float a[], int n);
float tichDaySo(float a[], int n);
int demLonHonX(float a[], int n, float x);
int kiemTraToanDuong(float a[], int n);

int docFile(float a[], int &n) {
    FILE *f = fopen("Lab3_1.inp", "r");
    if (f != NULL) {
        fscanf(f, "%d", &n);
        if (n < 2 || n >= MAX) {
            fclose(f);
            return 0;
        }
        for (int i = 0; i < n; i++)
            fscanf(f, "%f", &a[i]);
        fclose(f);
        return 1;
    }
    return 0;
}

void inDaySo(float a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%.2f ", a[i]);
    printf("\n");
}

float tongViTriLe(float a[], int n) {
    float s = 0;
    for (int i = 1; i < n; i += 2)
        s += a[i];
    return s;
}

float tichDaySo(float a[], int n) {
    float t = 1;
    for (int i = 0; i < n; i++)
        t *= a[i];
    return t;
}

int demLonHonX(float a[], int n, float x) {
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > x) dem++;
    return dem;
}

int kiemTraToanDuong(float a[], int n) {
    for (int i = 0; i < n; i++)
        if (a[i] <= 0) return 0;
    return 1;
}

int main() {
    float a[MAX];
    int n;
    float x;

    if (docFile(a, n)) {
        inDaySo(a, n);

        printf("Tong vi tri le: %.2f\n", tongViTriLe(a, n));
        printf("Tich day so: %.2f\n", tichDaySo(a, n));

        printf("Nhap x: ");
        scanf("%f", &x);

        printf("So phan tu > x: %d\n", demLonHonX(a, n, x));
        printf("Day so %s toan duong\n", kiemTraToanDuong(a, n) ? "la" : "khong la");
    }

    return 0;
}
