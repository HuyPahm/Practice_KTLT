//sinh chuoi nhi phan n ky tu, k so 1, khong có m so 0 lien tiep
#include<stdio.h>
#define N 10
int x[N];//luu ket qua
int n,k,m;

void Print(){
	int mot = 0;
	int khong = 0;
	int kq = 1;
	for(int i=1;i<=n;i++){
		if(khong == m){
			kq = 0;	break;
		}
		else	
		if(x[i]==1){
			mot++;
			khong = 0;
		}
		else	
			khong++;
	}
	//thoa dieu kien thi in
	if(kq == 1 && mot == k && khong < m){
		for(int i=1;i<=n;i++)
			printf("%d", x[i]);
		printf("\n");
	}		
}
//quay lui
void Try(int i){
	for(int j=0;j<=1;j++)
	{
		x[i] = j;
		if(i == n)
			Print();
		else
			Try(i+1);
	}
}
//
int main(){
	printf("Nhap vao do dai chuoi nhi phan n, k, m:");
	scanf("%d %d %d",&n,&k,&m);	
	Try(1);
}
