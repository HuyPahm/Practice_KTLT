#include <stdio.h>
#define MAX 50
#define SWAP(a,b,c){c=a;a=b;b=c;}

float v[]={4,7,10,2};//gia tri cua tung mon hang
float w[]={5,3,6,4};//trong luong tung mon hang
int n=sizeof(v)/sizeof(v[0]);
float p[MAX];//tri gia cua cac vat tren 1 don vi trong luong
int x[MAX];//nghiem cua bai toan
float T,M=9; //trong luong cai tui

void init(){
	T=M;
	//tinh don gia: tri gia tren 1 don vi trong luong
	for(int i=0;i<n;i++)
		p[i]=v[i]/w[i];		
		
	//sap xep theo chieu giam dan 
	float temp;
	for(int i=0;i<n;i++)
	for(int j=i+1;j<n;j++)
		if(p[i]<p[j]){
			SWAP(p[i],p[j],temp);
			SWAP(v[i],v[j],temp);
			SWAP(w[i],w[j],temp);
		}	
}
//in nghiem
void Print(){	
	printf("Trong luong tui dung do vat:%.1f\n",M-T);
	T=0;
	float k=0;
	for(int i=0;i<n;i++)
		if(x[i]!=0){
			printf("x:%d v:%.2f| w:%.2f\t",x[i],v[i],w[i]);
			T = T + x[i]*v[i];
			k = k+x[i]*w[i];
		}
	printf("\ngia tri lon nhat la %.1f voi tong trong luong la %.1f\n",T,k);			
} 
//tim phan tu nghiem thu i
void Greedy(){
	int i = 0; //vat thu i
	while (T > 0 && i < n){	 	
	   //chon ung vien tot nhat
	   if (T >= w[i]){		
			x[i]++; //neu moi vat chi lay dung 1 lan thi x[i]=1
			T -= w[i];			
	    } else     //neu moi vat chi lay dung 1: bo else
			i++;
	}	
}
//
int main(){
	init();
	Greedy();
	Print();
	return 0;
}
