//so to tien cua moi menh gia la vo han
#include <stdio.h>
#include <limits.h>
#define INF INT_MAX // Gia tri vo cung lon
#define N 50

int dp[N][N];
int t[]={1, 2, 5, 10}; //menh gia cac to tien
int s; //so tien can rut
int n; //so to tien

void Init(){
	// Khoi tao bang F
    for (int i = 0; i <= n; i++) 
        for (int j = 0; j <= s; j++) {
            if (j == 0)
                dp[i][j] = 0; //F[I,0]=0
            else if (i == 0)
                dp[i][j] = INF; 
            else
                dp[i][j] = INF; // Ban dau gia su khong rut duoc
        }    
}

void ATM() { 
    // Tinh toan gia tri F[i][j] theo công thuc truy hoi
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= s; j++) {
            if (j >= t[i - 1]) {
                // Co the su dung to tien thu i
                dp[i][j] = dp[i - 1][j] < (dp[i][j - t[i - 1]] + 1) 
                          ? dp[i - 1][j] 
                          : (dp[i][j - t[i - 1]] + 1);
            } else 
                // Khong the su dung loai tien thu i
                dp[i][j] = dp[i - 1][j];            
        }
    }
}
//
void Track(){
    // Ket qua
    if (dp[n][s] == INF) 
        printf("Khong the rut duoc so tien %d.\n", s);
    else {
        printf("So luong to tien it nhat de rut %d la: %d\n", s, dp[n][s]);

    // Truy vet de tim cac to tien da rut
    int i = n, j = s;
    printf("Cac to tien duoc rut: ");
    while (j > 0 && i > 0) 
        if (dp[i][j] != dp[i - 1][j]) {
            printf("%d ", t[i - 1]);
            j -= t[i - 1];
        } else 
            i--;           
        
        printf("\n");
    }
}

int main() {   
    n = sizeof(t) / sizeof(t[0]);  
    printf("Nhap vao so tien can rut: ");
    scanf("%d", &s);
	Init();
    ATM();
	Track();
    return 0;
}

