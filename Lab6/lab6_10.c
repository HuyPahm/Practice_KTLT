#include <stdio.h>
#define MAX 50 

// 1. Hàm xuất dãy số (Cơ bản)
void XuatMang(int a[], int n) {
    printf("Day so: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// 2. Hàm đếm số phần tử lớn hơn x (Chia để trị)
// Logic gộp: Số lượng bên trái + Số lượng bên phải
int demLonHonX(int a[], int l, int r, int x) {
    // [Neo] Nếu chỉ còn 1 phần tử
    if (l == r) {
        if (a[l] > x) return 1; // Tìm thấy 1 số thỏa mãn -> Đếm là 1
        else return 0;          // Không thỏa mãn -> Đếm là 0
    }

    // [Chia]
    int m = (l + r) / 2;

    // [Trị]
    int demTrai = demLonHonX(a, l, m, x);
    int demPhai = demLonHonX(a, m + 1, r, x);

    // [Kết hợp] Cộng dồn số lượng tìm thấy ở 2 bên
    return demTrai + demPhai;
}

// 3. Hàm tính tổng các phần tử ở vị trí chẵn (Chia để trị)
// Logic gộp: Tổng bên trái + Tổng bên phải
int tongViTriChan(int a[], int l, int r) {
    // [Neo] Nếu chỉ còn 1 phần tử
    if (l == r) {
        // Kiểm tra xem CHỈ SỐ (l) có chẵn hay không?
        if (l % 2 == 0) return a[l]; // Chỉ số chẵn -> Lấy giá trị cộng vào
        else return 0;               // Chỉ số lẻ -> Bỏ qua (cộng 0)
    }

    // [Chia]
    int m = (l + r) / 2;

    // [Trị]
    int tongTrai = tongViTriChan(a, l, m);
    int tongPhai = tongViTriChan(a, m + 1, r);

    // [Kết hợp]
    return tongTrai + tongPhai;
}

int main() { 
    // Dữ liệu mẫu
    int a[] = {5, 12, 9, 11, 24, 10, 3, 8}; 
    int n = sizeof(a)/sizeof(a[0]); 
    int x = 10; // Giá trị x cần so sánh

    // Gọi hàm in dãy số ra màn hình 
    XuatMang(a, n);

    // Gọi hàm đếm phần tử > x
    int ketQuaDem = demLonHonX(a, 0, n - 1, x);
    printf("So phan tu lon hon %d la: %d\n", x, ketQuaDem);

    // Gọi hàm tính tổng vị trí chẵn
    // Các vị trí chẵn là index: 0 (số 5), 2 (số 9), 4 (số 24), 6 (số 3) -> Tổng = 41
    int ketQuaTong = tongViTriChan(a, 0, n - 1);
    printf("Tong cac phan tu o vi tri chan (index 0, 2...): %d\n", ketQuaTong);
 
    return 0; 
}