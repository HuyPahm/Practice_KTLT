//bai 5.2
#include <stdio.h>
#define N 50
//doc file du lieu
int DocFile(int t[], int &n, int &s);
void XuatDS(int t[], int n, int s);
void SapXep(int t[], int n);
void ATM(int t[],int n,int x[],int s,int c);
void XuatNghiem(int t[],int n, int x[],int s,int c);
int GhiFile(int t[], int n,int x[], int c);

int kq = 0; //gia su kg co cach tra nghiem
//
int main(){
	int t[N], n, s;
	int x[N];//luu cac thanh phan nghiem	
	if (DocFile(t,n,s)==1){
		XuatDS(t,n,s);
		for(int i=0;i<n;i++)
			x[i] = 0;
		SapXep(t,n);
		ATM(t,n,x,s,0);
	}		
}
//Doc dl tu file vao chuong trinh
int DocFile(int t[], int &n, int &s){
	FILE* f=fopen("ATM.inp","r");
	if(f==NULL){
		printf("Err!"); return 0;
	}		
	else{
		int i;
		fscanf(f,"%d",&n);//so n
		fscanf(f,"%d",&s);//tong tien 
		for(i=0;i<n;i++)
			fscanf(f,"%d",&t[i]);
		fclose(f);
		return 1;
	}
}
//xuat day so
void XuatDS(int t[], int n, int s){
	int i;
	printf("Tong tien can rut s: %d\nCac to tien co trong atm:",s);
	for(i=0;i<n;i++)
		printf("%8d",t[i]);
	printf("\n");
}
// Sap xep giam dan
void SapXep(int t[], int n) {
	int tmp;
    for (int i = 0; i < n - 1; i++) 
        for (int j = i+1; j < n ; j++) 
            if (t[i] < t[j]) {               
                tmp = t[i];
                t[i] = t[j];
                t[j] = tmp;
            }    
}
// Tham lam tim nghiem, so to cac menh gia han che
void ATM(int t[],int n,int x[],int s,int c){
	int i=0; 
	int s1=s; //s1 so tien con lai
	while(i<n && s1>0){
		if(s1>=t[i]){  //chon menh gia lon nhat
			x[i] = 1;
			s1 -= t[i];
			c++; //so to
		}
		i++;
	}
	if(s1==0){
		XuatNghiem(t,n,x,s,c);
		kq = 1;	
		GhiFile(t,n,x,c);	
	}		
	else
		printf("khong rut duoc");
}
//xuat ra màn hình
void XuatNghiem(int t[],int n, int x[],int s,int c){
	printf("Ban can rut %d \n",s);
	printf("Cach tra tien cua ATM gom %d to:\n",c);
	for(int i=0;i<n;i++)
		if(x[i]!=0)
			printf("%d:%d\t",i,t[i]);	
}
//ghi file
int GhiFile(int t[], int n,int x[], int c){
	FILE* f=fopen("ATM_out.out","w");
	if(f==NULL){
		printf("Err!"); return 0;
	}		
	else{
		if (kq == 0)
			fprintf(f,"-1");
		else{
			for(int i=0;i<n;i++)
				if(x[i]!=0)
					fprintf(f,"%d\t",t[i]);
			fprintf(f,"\nTong so to la %d",c);
		}		
	}
}
