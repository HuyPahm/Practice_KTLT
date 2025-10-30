#include <stdio.h>
#define MAX 40

// Khai báo nguyên mẫu hàm
int docFile(int a[], int &n);
void inDaySo(int a[], int n);
int timMaxFor(int a[], int n);
int timMaxDQ(int a[], int n);

// Hàm đọc dữ liệu từ file
int docFile(int a[], int &n) {
    FILE *f = fopen("Lab3_1.inp", "r");
    if (f != NULL) {
        fscanf(f, "%d", &n);

        if (n < 3 || n > MAX) {
            printf("So luong phan tu khong hop le!\n");
            fclose(f);
            return 0;
        }

        for (int i = 0; i < n; i++) {
            fscanf(f, "%d", &a[i]);
        }

        fclose(f);
        return 1;
    } else {
        printf("Khong the mo file 'Lab3_1.inp'\n");
        return 0;
    }
}

// Hàm in dãy số
void inDaySo(int a[], int n) {
    printf("Noi dung day so:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Tìm giá trị lớn nhất bằng vòng lặp for
int timMaxFor(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

// Tìm giá trị lớn nhất bằng đệ quy
int timMaxDQ(int a[], int n) {
    if (n == 1)
        return a[0];
    else {
        int m = timMaxDQ(a, n - 1);
        return (a[n - 1] > m) ? a[n - 1] : m;
    }
}

// Hàm main
int main() {
    int a[MAX];
    int n;

    if (docFile(a, n)) { // n là tham chiếu, không cần dùng &
        inDaySo(a, n);

        int max1 = timMaxFor(a, n);
        int max2 = timMaxDQ(a, n);

        printf("Gia tri lon nhat (for): %d\n", max1);
        printf("Gia tri lon nhat (de quy): %d\n", max2);
    }

    return 0;
}
