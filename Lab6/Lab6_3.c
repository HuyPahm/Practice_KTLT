#include<stdio.h>
#define N 100

int x[N]; // x[i] = 1 (Tập 1), x[i] = 0 (Tập 2)
int a[N]; // Mảng dữ liệu đầu vào
int n;

// Bộ phận kiểm tra
void Print(){
    int sum1 = 0;
    int sum2 = 0;

    // Bước 1: Tính tổng cho từng tập dựa trên giá trị của x
    for(int i = 1; i <= n; i++){
        if(x[i] == 1){
            sum1 = sum1 + a[i]; // Vào tập 1
        } else {
            sum2 = sum2 + a[i]; // Vào tập 2 (vì x[i] == 0)
        }
    }

    // Bước 2: Kiểm tra điều kiện (2 tổng bằng nhau)
    if(sum1 == sum2){
        printf("Phat hien mot cach chia:\n");
        
        // In Tập 1
        printf("  - Tap 1: { ");
        for(int i = 1; i <= n; i++) 
            if(x[i] == 1) printf("%d ", a[i]);
        printf("}\n");
        
        // In Tập 2
        printf("  - Tap 2: { ");
        for(int i = 1; i <= n; i++) 
            if(x[i] == 0) printf("%d ", a[i]);
        printf("}\n");
        
        printf("------------------------\n");
    }
}

// Hàm quay lui (Giữ nguyên xi)
void Try(int i){
    for(int j = 0; j <= 1; j++){
        x[i] = j;       // Gán ứng viên (0 hoặc 1)
        if(i == n)
            Print();    // Đủ thành phần -> Kiểm tra
        else
            Try(i+1);   // Chưa đủ -> Tìm tiếp
    }
}

int main(){
    printf("Nhap so phan tu n: ");
    scanf("%d", &n);
    
    printf("Nhap %d so nguyen:\n", n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    
    Try(1);
    
    return 0;
}