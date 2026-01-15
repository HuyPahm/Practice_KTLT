#include<stdio.h>
#define N 35
#define INF 99999999 // biến vô cực


int n;
int C[N][N];       // ma trận chi phí 
int x[N];          // Luu hanh trinh dang thu: x[1], x[2]...
int visited[N];    // đánh dấu tp đã đi qua
int bestRoute[N];  // lưu hành trình tốt nhất đã tìm được 
int minCost = INF; // chi phí tốt nhất 
int currentCost = 0; // chi phí hiện tại 

void DocFile(char* filename);
void GhiFile(char* filename);
void CapNhatBest();
void TSP(int i);

int main(){

    for(int k=1; k<=N; k++) visited[k] = 0;
    
    DocFile("Dulichin.txt");

    x[1] = 1;
    visited[1] = 1;

    // đệ quy
    TSP(2);

    GhiFile("Dulichout.out");
    return 0;
}

void DocFile(char* filename){
    FILE* f = fopen(filename, "r");
    if(f == NULL){
        printf("Loi doc file input!");
        return;
    }
    fscanf(f, "%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            fscanf(f, "%d", &C[i][j]);
        }
    }
    fclose(f);
}

// cập nhật nghiệm
void CapNhatBest(){
    // tính chi phí từ tp cuối cùng về lại 1
    int chiPhiVe = C[x[n]][1];
    if(currentCost + chiPhiVe < minCost){
        minCost = currentCost + chiPhiVe;
        for(int i = 1; i <= n; i++)
            bestRoute[i] = x[i];
    }
}

// quay lui
void TSP(int i){
    // Duyet cac thanh pho j co the la diem tiep theo
    for(int j = 2; j <= n; j++){
        // j chua di qua VA co duong di tu x[i-1] den j
        if(visited[j] == 0 && C[x[i-1]][j] > 0){
            
            x[i] = j;
            visited[j] = 1;
            currentCost += C[x[i-1]][j]; 

            // NHANH CAN: //chi phí hiện tại lớn hơn chi phí trước đó tìm đc
            if(currentCost < minCost){
                if(i == n){
                    // đến điểm cuối rr
                    if(C[x[n]][1] > 0)
                        CapNhatBest();
                }
                else{// nếu chưa đến thì gọi đệ quy lại
                    TSP(i+1);
                }
            }

            currentCost -= C[x[i-1]][j];
            visited[j] = 0;
        }
    }
}

void GhiFile(char* filename){
    FILE* f = fopen(filename, "w");
    if(f == NULL){
        printf("Loi !");
        return;
    }
    
    if(minCost == INF){
        fprintf(f, "-1"); // 0 có đường đi
        printf("Khong tim thay duong di!\n");
    }
    else{
        fprintf(f, "Chi phi thap nhat: %d\n", minCost);
        fprintf(f, "Hanh trinh: ");
        for(int i = 1; i <= n; i++)
            fprintf(f, "%d -> ", bestRoute[i]);
        fprintf(f, "1\n");
        
        printf("Tong chi phi: %d\n", minCost);
    }
    fclose(f);
}