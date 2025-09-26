#include<stdio.h>
#define Print_arr(a,n) printf("day so la: "); for (int i=0; i<n;i++) {printf("%d",a[i]);}

#define Min(x,y) (x)<(y) ?(x):(y)
int main()
{
    int arr[] = {10,12,3,24,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    Print_arr(arr,n);
    printf("\n");

    int min =arr[0];
    for (int i =1;i<n;i++)
        min = Min(min,arr[i]);
        
    printf("phan tu nho nhat la: %d",min);
}