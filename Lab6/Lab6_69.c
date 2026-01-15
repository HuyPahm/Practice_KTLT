#include <stdio.h>
#define MAX 50 

// 1. Hàm in dãy số ra màn hình
void xuatMang(float a[], int n) {
    printf("Day so: ");
    for (int i = 0; i < n; i++) {
        printf("%.1f  ", a[i]); // In lấy 1 số sau dấu phẩy
    }
    printf("\n");
}

// 2. Hàm tìm Max theo Chia để trị
// Tư duy: Max của cả dãy = Max(Max nửa trái, Max nửa phải)
float timMax(float a[], int l, int r) {
    // [Neo] Nếu chỉ còn 1 phần tử -> Nó chính là max
    if (l == r) {
        return a[l];
    }

    // [Chia]
    int m = (l + r) / 2;

    // [Trị] Tìm max bên trái và max bên phải
    float maxTrai = timMax(a, l, m);
    float maxPhai = timMax(a, m + 1, r);

    // [Kết hợp] So sánh 2 bên để lấy số lớn nhất
    if (maxTrai > maxPhai) return maxTrai;
    else return maxPhai;
}

// 3. Hàm tính tổng dương theo Chia để trị
// Tư duy: Tổng cả dãy = Tổng nửa trái + Tổng nửa phải
// (Chỉ cộng khi số đó > 0)
float tongDuong(float a[], int l, int r) {
    // [Neo] Nếu chỉ còn 1 phần tử
    if (l == r) {
        if (a[l] > 0) return a[l]; // Nếu dương thì lấy
        else return 0;             // Nếu âm thì trả về 0 (không cộng)
    }

    // [Chia]
    int m = (l + r) / 2;

    // [Trị] Tính tổng bên trái và tổng bên phải
    float tongTrai = tongDuong(a, l, m);
    float tongPhai = tongDuong(a, m + 1, r);

    // [Kết hợp] Cộng 2 kết quả lại
    return tongTrai + tongPhai;
}

int main() { 
    // Đổi int thành float để giữ được phần thập phân như đề bài
    float a[] = {3.5, 7.1, 9.5, 1.1, 2.4}; 
    int n = sizeof(a)/sizeof(a[0]); 
    
    // Gọi hàm in dãy số ra màn hình 
    xuatMang(a, n);

    // Gọi các hàm thực hiện chia để trị
    float maxVal = timMax(a, 0, n - 1);
    float sumPos = tongDuong(a, 0, n - 1);

    printf("Phan tu lon nhat (Max): %.1f\n", maxVal);
    printf("Tong cac phan tu duong: %.1f\n", sumPos);
 
    return 0; 
}