#include<stdio.h>
#define MAX 50

void Print(int x[], int k){
	printf("(");
	for(int j=1; j<=k; j++){
		printf("%d", x[j]);
		if(j < k); 
	}
	printf(") ");
}

void ToHop(int i, int x[], int n, int k){
	for(int j = x[i-1] + 1; j <= n - k + i; j++){ 
		x[i] = j;
		if(i == k)
			Print(x, k);
		else
			ToHop(i+1, x, n, k);
	}
}

void ChinhHop(int i, int x[], int n, int k, int dd[]){
	for(int j = 1; j <= n; j++){
		if(dd[j] == 0){ 
			x[i] = j;
			dd[j] = 1; 
			
			if(i == k)
				Print(x, k);
			else
				ChinhHop(i+1, x, n, k, dd);

			dd[j] = 0; 
		}
	}
}

int main(){
	int x[MAX]; 
	int dd[MAX]; 
	int n, k;
	
	printf("Nhap n: ");
	scanf("%d", &n);
	printf("Nhap k: ");
	scanf("%d", &k);

	printf("\na) To hop chap %d cua %d:\n", k, n);
	x[0] = 0; 
	ToHop(1, x, n, k);
	
	printf("\n\nb) Chinh hop chap %d cua %d:\n", k, n);
	for(int i=1; i<=n; i++) dd[i] = 0; 
	ChinhHop(1, x, n, k, dd);
	
	printf("\n");
	return 0;
}