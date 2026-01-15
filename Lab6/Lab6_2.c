#include<stdio.h>
#define N 100 // Tăng kích thước mảng dự phòng

int x[N]; // Lưu trạng thái chọn (1) hay không chọn (0)
int a[N]; // Lưu giá trị các số nhập vào (Mảng dữ liệu)
int n, S; // n là số phần tử, S là tổng cần tìm

// Hàm này đóng vai trò "Kiểm tra và In"
void Print(){
    int sum = 0;
    
    // Bước 1: Tính tổng dựa trên cấu hình x hiện tại
    for(int i = 1; i <= n; i++){
        if(x[i] == 1){
            sum = sum + a[i]; // Nếu x[i]=1 thì cộng số a[i] vào tổng
        }
    }
    
    // Bước 2: Kiểm tra điều kiện nghiệm (Tổng phải bằng S)
    if(sum == S){
        // In các phần tử được chọn ra
        printf("Tap con: { ");
        for(int i = 1; i <= n; i++){
            if(x[i] == 1){
                printf("%d ", a[i]);
            }
        }
        printf("}\n");
    }
}

// Hàm quay lui (Giữ nguyên y hệt bài trước)
// Nhiệm vụ: Sinh ra chuỗi nhị phân đại diện cho việc chọn/không chọn
void Try(int i){
    for(int j = 0; j <= 1; j++){
        x[i] = j;       // Thử gán 0 hoặc 1
        if(i == n)      // Nếu đã quyết định xong cho phần tử cuối cùng
            Print();    // -> Chuyển sang kiểm tra tổng
        else
            Try(i+1);   // -> Sang quyết định cho phần tử tiếp theo
    }
}

int main(){
    printf("Nhap so phan tu n va tong S: ");
    scanf("%d %d", &n, &S);
    
    printf("Nhap %d so nguyen:\n", n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]); // Nhập mảng bắt đầu từ 1 cho khớp với thuật toán
    }
    
    printf("Cac phuong an thoa man:\n");
    Try(1);
    
    return 0;
}