//Bai 5.1
#include<stdio.h>
#define N 100

//a. Tinh tong
int TinhTong(int a[], int l, int r) {
    if (l == r) return a[l]; // chi con 1 phan tu
    int m = (l + r) / 2; 
    int trai = TinhTong(a, l, m);
    int phai = TinhTong(a, m + 1, r);
    return trai + phai; //tong hop nghiem
//viet gop:     return TinhTong(a, l, m) + TinhTong(a, m + 1, r);
}
//b.Dem so lan xuat hien phan tu x
int DemX(int a[], int l, int r, int x) {
    if (l == r) return (a[l] == x) ? 1 : 0;
    int m = (l + r) / 2;
    int trai = DemX(a, l, m, x);
    int phai = DemX(a, m + 1, r, x);
    return trai + phai;
}
//c.tim vi tri phan tu nho nhat
int TimNN(int a[], int l, int r) {
    if (l == r) return l; // tra ve vi tri
    int m = (l + r) / 2;
    int trai = TimNN(a, l, m);
    int phai = TimNN(a, m + 1, r);
    return (a[trai] <= a[phai]) ? trai : phai;
}

int main(){
	int a[] = {2, 6, 1, 23, 55, 18, 2};
	int n = sizeof(a)/sizeof(a[0]);
	printf("Tong: %d\n", TinhTong(a,0,n-1));
	
	printf("Nhap gia tri x can dem:");
	int x;
	scanf("%d",&x);
	printf("So phan tu %d la %d\n",x,DemX(a,0,n-1,x));
	
	printf("Vi tri phan tu nho nhat la %d",TimNN(a,0,n-1));
}

