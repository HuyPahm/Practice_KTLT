//bai 4.2
#include<stdio.h>
#define N 50

void DocFile(char* st, int t[], int &n, int &s);//doc file
void Xuat(int t[], int n, int s);
void ATM_1(int i, int t[], int x[], int n, int s);
void XuatNghiem(int t[], int x[], int n, int s);
void ATM_2(int i, int t[], int x[], int n, int s, int tong);
void GhiFile(int t[], int x[], int n, int s);
void ATM_21(int i, int t[], int x[], int n, int S);

FILE* fout = fopen("ATM_out.out","w");
int s1 = 0;

int main(){
	int t[N], n, s;
	int x[N];//luu cac thanh phan nghiem
	DocFile("ATM.inp",t,n,s);
	Xuat(t,n,s);
	//cach 1	
//	ATM_1(0,t,x,n,s);
//cach 21
	ATM_21(0,t,x,n,s);
	//ghi ket qua vao file
	if (fout==NULL){
		printf("Err!"); return 0;
	}		
	else
		ATM_2(0,t, x, n, s, 0);
}
//Doc dl tu file vao chuong trinh
void DocFile(char* st, int t[], int &n, int &s){
	FILE* f=fopen(st,"r");
	if(f==NULL)
		printf("Err!");
	else{
		int i;
		fscanf(f,"%d",&n);//so n
		fscanf(f,"%d",&s);//tong tien 
		for(i=0;i<n;i++)
			fscanf(f,"%d",&t[i]);
		fclose(f);
	}
}
//xuat day so
void Xuat(int a[], int n, int s){
	int i;
	printf("Tong tien can rut s: %d\nCac to tien co trong atm:",s);
	for(i=0;i<n;i++)
		printf("%8d",a[i]);
	printf("\n");
}
//in bo nghiem ra man hinh
void XuatNghiem(int t[], int x[], int n, int s){
	//kiem tra dieu kiem nghiem
	int sum=0,i;
	for(i=0;i<n;i++)
		sum +=x[i]*t[i];
	if(sum==s){  //dk nghiem thoa man => xuat nghiem
		for(i=0;i<n;i++)
			if(x[i]==1)
				printf("%d: %d\t",i,t[i]);
		printf("\n");
	}	
}
//Quay lui c1
void ATM_1(int i, int t[], int x[], int n, int s){
	for(int j=0;j<=1;j++){
		x[i]=j;
		if(i == n-1)
			XuatNghiem(t,x,n,s);
		else
			ATM_1(i+1,t,x,n,s);
	}
}
//c2:
void ATM_2(int i, int t[], int x[], int n, int s, int tong) {
    if (tong > s) return; // vuot qua S
    if (i == n) {       
        GhiFile(t,x,n,s);//XuatNghiem(t,x,n,s);        
        return;
    }
    // Khong chon to thu i
    x[i] = 0;
    ATM_2(i + 1, t, x, n, s, tong);
    // Chon to thu i
    x[i] = 1;
    ATM_2(i + 1, t, x, n, s, tong + t[i]);
}
//ghi file
void GhiFile(int t[], int x[], int n, int s){
	int sum=0,i;
	for(i=0;i<n;i++)
		sum +=x[i]*t[i];
	if(sum==s){
		for(i=0;i<n;i++)
			if(x[i]==1)
				fprintf(fout,"%d: %d\t",i,t[i]);
		fprintf(fout,"\n");
	}	
}
//
//in bo nghiem ra man hinh
void XuatNghiem12(int t[], int x[], int n) {
    for (int i = 0; i < n; i++) {
        if (x[i] == 1)
            printf("%d: %d\t", i,t[i]);
    }
    printf("\n");
}

// Hàm quay lui 
void ATM_21(int i, int t[], int x[], int n, int S) {
    if (s1 > S) return; // Neu tong > S thi dung
    if (i == n) {        
     	if (s1 == S)
            XuatNghiem12(t, x, n);        
        return;
    }
    
    x[i] = 1;    s1 += t[i];    ATM_21(i + 1, t, x, n, S);
    s1 -= t[i]; // backtrack
    
    x[i] = 0;    ATM_21(i + 1,t, x, n, S);
}
