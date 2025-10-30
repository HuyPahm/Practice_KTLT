#include <stdio.h>
#define MAX 40

// Khai báo nguyên mẫu hàm
int docFile(float a[], int &n);
void inDaySo(float a[], int n);
int demX(float a[], int n, float x);

// Hàm đọc dữ liệu từ file
int docFile(float a[], int &n) {
    FILE *f = fopen("Dayso2_4.txt", "r");
    if (f == NULL) {
        printf("Khong the mo file 'Dayso2_4.txt'\n");
        return 0;
    }

    fscanf(f, "%d", &n);  // đọc số phần tử

    if (n < 3 || n > MAX) {
        printf("So phan tu khong hop le (3 ≤ n ≤ %d)\n", MAX);
        fclose(f);
        return 0;
    }

    for (int i = 0; i < n; i++) {
        fscanf(f, "%f", &a[i]);
    }

    fclose(f);
    return 1;
}

// Hàm in dãy số
void inDaySo(float a[], int n) {
    printf("Noi dung day so:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }
    printf("\n");
}

// Hàm đếm phần tử nhỏ hơn x
int demX(float a[], int n, float x) {
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < x) {
            c++;
        }
    }
    return c;
}

// Hàm main
int main() {
    float a[MAX];
    int n;

    if (docFile(a, n)) {   // ✅ không cần & vì n là tham chiếu
        inDaySo(a, n);

        float x;
        printf("Nhap gia tri x: ");
        scanf("%f", &x);

        int count = demX(a, n, x);
        printf("So phan tu nho hon %.2f la: %d\n", x, count);
    }

    return 0;
}
