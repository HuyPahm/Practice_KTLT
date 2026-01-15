#include <stdio.h>
#define MAX 50

// 1. Hàm in dãy số ra màn hình (Phần còn thiếu)
void XuatMang(int a[], int n) {
    printf("Day so: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// 2. Hàm Kiểm tra dãy số có tăng dần hay không (Code của bạn)
// Input: Mảng a, chỉ số trái l, chỉ số phải r
// Output: 1 nếu tăng dần, 0 nếu không tăng
int tangDan(int a[], int l, int r) {
    // [Neo] Nếu chỉ có 1 phần tử => Mặc nhiên là tăng dần
    if (l == r) return 1;

    // [Chia] Chia đôi bài toán
    int m = (l + r) / 2;  
    
    // [Trị] Gọi đệ quy cho 2 nửa
    int trai = tangDan(a, l, m);
    int phai = tangDan(a, m + 1, r);

    // [Kết hợp] 
    // Điều kiện 1: Cả 2 nửa con đều phải tăng dần
    if (!trai || !phai) return 0;
    
    // Điều kiện 2: Mối hàn giữa 2 nửa phải khớp
    // Phần tử cuối của nửa trái (a[m]) phải <= Phần tử đầu của nửa phải (a[m+1])
    if (a[m] > a[m + 1]) return 0;

    return 1;
}

// 3. Hàm main hoàn chỉnh
int main() {
    // Dữ liệu mẫu (Có số 24 rồi xuống 10 -> Không tăng dần)
    int a[] = {5, 7, 9, 11, 24, 10}; 
    int n = sizeof(a) / sizeof(a[0]);

    // Gọi hàm in dãy số
    XuatMang(a, n);

    // Gọi hàm kiểm tra và in kết quả
    if (tangDan(a, 0, n - 1)) {
        printf("Ket qua: Day so tang dan.\n");
    } else {
        printf("Ket qua: Day so KHONG tang dan.\n");
    }

    return 0;
}