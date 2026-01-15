
#include <stdio.h>
#define N 30
#define INF 999999

int C[N][N]; // Ma tran chi phi
int n;       // So thanh pho
int tour[N]; // Luu lo trinh
int visited[N]; // Danh dau da di qua
long tongChiPhi = 0;

int DocFile() {
    FILE *f = fopen("dulich", "r");
    if (f == NULL) {
        printf("Loi mo file dulich!\n");
        return 0;
    }
    fscanf(f, "%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fscanf(f, "%d", &C[i][j]);
        }
    }
    fclose(f);
    return 1;
}

void GreedyTSP() {
    int current = 1; // Bat dau tu thanh pho 1
    visited[current] = 1;
    tour[1] = 1; // Luu diem xuat phat

    for (int i = 2; i <= n; i++) {
        int nearest = -1;
        int min_dist = INF;
        // Tim thanh pho gan nhat chua di qua
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && C[current][j] > 0 && C[current][j] < min_dist) {
                min_dist = C[current][j];
                nearest = j;
            }
        }

        if (nearest != -1) {
            visited[nearest] = 1;
            tour[i] = nearest;
            tongChiPhi += min_dist;
            current = nearest;
        } else {
            printf("Khong tim thay duong di!\n");
            return;
        }
    }
    tongChiPhi += C[current][1];
}

void GhiFile() {
    FILE *f = fopen("dulich_out", "w");
    if (f == NULL) {
        printf("Loi tao file dulich_out!\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        fprintf(f, "TP%d -> ", tour[i]);
    }
    fprintf(f, "TP1\n"); 
    fprintf(f, "Tong chi phi la: %ld", tongChiPhi);
    fclose(f);
    printf("Da ghi ket qua ra file dulich_out\n");
}

void XuatManHinh() {
    printf("Lo trinh: ");
    for (int i = 1; i <= n; i++) {
        printf("TP%d -> ", tour[i]);
    }
    printf("TP1\n");
    printf("Tong chi phi: %ld\n", tongChiPhi);
}

int main() {
    for (int i = 0; i < N; i++) visited[i] = 0;
    
    if (DocFile()) {
        GreedyTSP();
        XuatManHinh();
        GhiFile();
    }
    return 0;
}