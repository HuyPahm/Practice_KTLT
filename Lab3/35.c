#include <stdio.h>
#define MAX 50

// Nguyên mẫu hàm
int docFile(float a[], int *n);
void inDaySo(float a[], int n);
float timMinFor(float a[], int n);
float timMinDQ(float a[], int n);
float tongDQDau(float a[], int n);
float tongDQDuoi(float a[], int n, float acc);

// Đọc file
int docFile(float a[], int *n) {
    FILE *f = fopen("DaySo35.inp", "r");
    if (f != NULL) {
        fscanf(f, "%d", n);

        if (*n < 2 || *n >= MAX) {
            printf("So luong phan tu khong hop le!\n");
            fclose(f);
            return 0;
        }

        for (int i = 0; i < *n; i++)
            fscanf(f, "%f", &a[i]);

        fclose(f);
        return 1;
    } else {
        printf("Khong the mo file 'DaySo35.inp'\n");
        return 0;
    }
}

// In dãy số
void inDaySo(float a[], int n) {
    printf("Day so: ");
    for (int i = 0; i < n; i++)
        printf("%.2f ", a[i]);
    printf("\n");
}

// Tìm min bằng vòng lặp
float timMinFor(float a[], int n) {
    float min = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

// Tìm min bằng đệ quy
float timMinDQ(float a[], int n) {
    if (n == 1)
        return a[0];
    float m = timMinDQ(a, n - 1);
    return (a[n - 1] < m) ? a[n - 1] : m;
}

// Tổng đệ quy đầu
float tongDQDau(float a[], int n) {
    if (n == 0)
        return 0;
    return a[n - 1] + tongDQDau(a, n - 1);
}

// Tổng đệ quy đuôi
float tongDQDuoi(float a[], int n, float acc) {
    if (n == 0)
        return acc;
    return tongDQDuoi(a, n - 1, acc + a[n - 1]);
}

// main
int main() {
    float a[MAX];
    int n;

    if (docFile(a, &n)) {
        inDaySo(a, n);

        printf("Min (for): %.2f\n", timMinFor(a, n));
        printf("Min (de quy): %.2f\n", timMinDQ(a, n));

        printf("Tong (dq dau): %.2f\n", tongDQDau(a, n));
        printf("Tong (dq duoi): %.2f\n", tongDQDuoi(a, n, 0));
    }

    return 0;
}
