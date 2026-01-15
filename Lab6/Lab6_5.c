#include <stdio.h>
#define MAX 50 // Khai báo dư ra chút (đề cho n <= 20)

int n, M;
int w[MAX]; // Mảng lưu trọng lượng các quả cân
int x[MAX]; // Mảng nghiệm: 1 là chọn, 0 là không chọn
int dem = 0;      // Biến đếm số cách
int che_do_in = 0; // 0: Chỉ đếm, 1: In chi tiết

// --- BỘ PHẬN KIỂM TRA VÀ IN ---
void KiemTra() {
    int sum = 0;
    
    // 1. Tính tổng các quả cân được chọn
    for(int i = 1; i <= n; i++){
        if(x[i] == 1){
            sum += w[i];
        }
    }
    
    // 2. So sánh với trọng lượng vật M
    if(sum == M){
        if(che_do_in == 0){
            // Chế độ 0: Chỉ đếm số lượng
            dem++;
        } else {
            // Chế độ 1: In ra các quả cân
            for(int i = 1; i <= n; i++){
                if(x[i] == 1){
                    printf("%d ", w[i]);
                }
            }
            printf("\n"); // Xuống dòng cho cách tiếp theo
        }
    }
}

// --- KHUNG QUAY LUI (Giữ nguyên form) ---
void Try(int i){
    for(int j = 0; j <= 1; j++){ // 0: Không chọn, 1: Chọn
        x[i] = j;
        
        if(i == n){
            KiemTra(); // Đủ n quả -> Kiểm tra tổng
        } else {
            Try(i+1);
        }
    }
}

int main(){
    // Nhập dữ liệu
    // printf("Nhap n va M: ");
    scanf("%d %d", &n, &M);
    
    // printf("Nhap trong luong cac qua can: ");
    for(int i = 1; i <= n; i++){
        scanf("%d", &w[i]);
    }
    
    // --- BƯỚC 1: CHẠY NHÁP ĐỂ ĐẾM SỐ CÁCH ---
    che_do_in = 0;
    dem = 0;
    Try(1);
    
    // --- BƯỚC 2: XỬ LÝ KẾT QUẢ ---
    if(dem == 0){
        printf("Khong chon duoc");
    } else {
        printf("%d\n", dem); // In số cách tìm được
        
        // Bật chế độ in chi tiết và chạy lại
        che_do_in = 1;
        Try(1);
    }
    
    return 0;
}