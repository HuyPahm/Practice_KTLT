#include <stdio.h>

#define N 30      // So goi hang toi da
#define MAX_W 100 // Trong luong toi da cua tui (gia su)

int n, M;       // n goi hang, tui chua duoc M
int w[N], v[N]; // w: trong luong, v: gia tri
int dp[N][MAX_W]; // Bang phuong an

int DocFile() {
    FILE *f = fopen("Knapsack.txt", "r");
    if (f == NULL) {
        printf("Loi mo file Knapsack.txt!\n");
        return 0;
    }
    fscanf(f, "%d %d", &n, &M);
    for (int i = 1; i <= n; i++) fscanf(f, "%d", &v[i]);
    for (int i = 1; i <= n; i++) fscanf(f, "%d", &w[i]);
    
    fclose(f);
    return 1;
}

int Max(int a, int b) {
    return (a > b) ? a : b;
}

void KnapsackDP() {
    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int j = 0; j <= M; j++) dp[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= M; j++) {
            if (j >= w[i]) {
                dp[i][j] = Max(dp[i-1][j], dp[i-1][j - w[i]] + v[i]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
}

void TruyVetVaGhiFile() {
    FILE *f = fopen("Knapsack_out.txt", "w");
    if (f == NULL) {
        printf("Loi tao file Knapsack_out.txt!\n");
        return;
    }

    printf("Tong gia tri lon nhat: %d\n", dp[n][M]);
    
    int i = n, j = M;
    while (i > 0) {
        if (dp[i][j] != dp[i-1][j]) {
            printf("Vat thu: %d, gia tri: %d, trong luong: %d\n", i, v[i], w[i]);
            fprintf(f, "Vat thu: %d, gia tri: %d, trong luong: %d\n", i, v[i], w[i]);
            j -= w[i]; 
        }
        i--;
    }
    
    fclose(f);
    printf("Da ghi ket qua ra file Knapsack_out.txt\n");
}

void XuatDS() {
    printf("So vat: %d, Trong luong tui: %d\n", n, M);
    printf("Vat:\t");
    for(int i=1; i<=n; i++) printf("%d\t", i);
    printf("\nGia tri:");
    for(int i=1; i<=n; i++) printf("%d\t", v[i]);
    printf("\nTrong luong:");
    for(int i=1; i<=n; i++) printf("%d\t", w[i]);
    printf("\n");
}

int main() {
    if (DocFile()) {
        XuatDS();
        KnapsackDP();
        TruyVetVaGhiFile();
    }
    return 0;
}