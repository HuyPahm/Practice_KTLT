#include <stdio.h>
#define MAX 100

int a[]={12,1,4,7,5,8,7,9,16};//day so
int n;
int l[MAX];//bang luu chieu dai
int t[MAX]; //luu vet vi trí cua phan tu phia truoc
int lmax;

void Init(){	
	n=sizeof(a)/sizeof(a[0]);
	l[0]=0;	
	for(int i=0;i<n;i++)
		t[i]=-1;
}

void Dynamic(){
	for(int i=0;i<n;i++){
		lmax=0; 
		for(int j=0;j<i;j++)
			if (a[j]<a[i] && lmax<l[j]){
				lmax = l[j];
				t[i] = j;//vi tri truoc i
			}
		l[i]=lmax+1;		
	}
}
//truy vet
void Track(){
	int max=l[0], p=-1;
	for(int i=1;i<n;i++)
		if(max<l[i]){
			max=l[i];
			p = i;
		}
	printf("\n Do dai day tang dai nhat la %d ",max);	
	int kq[MAX], i=0; //luu vi tri cac phan tu
	while (p>=0){
		kq[i] = p;
		i++;
		p=t[p];
	}	
	printf("\n Cac phan tu:");
	for(int j=i-1;j>=0;j--)
		printf("%d ",a[kq[j]]);
}
//
int main(){
	Init();
	Dynamic();	
	Track();	
}
