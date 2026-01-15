//sinh chuoi nhi phan do dai n
#include<stdio.h>
#define N 10

void Print(int x[], int n){
	for(int j=1;j<=n;j++)
		printf("%d ",x[j]);
	printf("\n");
}
//c1
void Try_1(int i, int x[], int n){
	for(int j=0;j<=1;j++)
	{
		x[i]=j;
		if(i==n)
			Print(x, n);//in ra nghiem
		else
			Try_1(i+1, x, n);
	}
}
//c2
void Try_2(int i, int x[], int n)
{
   if (i == n+1) { Print(x,n); return;}
   
   x[i]= 0; Try_2(i+1,x,n);
   x[i]= 1; Try_2(i+1,x,n); 
}

//
int main(){
	int x[N];//luu ket qua
	int n;
	printf("Nhap vao do dai chuoi nhi phan:");
	scanf("%d",&n);	
	printf("Cach 1:\n");
	Try_1(1, x, n);
	printf("Cach 2:\n");
	Try_2(1, x, n);
}
