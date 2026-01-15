
#include <stdio.h>
#include <limits.h>

#define N 100

// a) Tim kiem nhi phan (mang da sap xep)
int BinarySearch(int a[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (a[mid] == x) return mid;
        if (a[mid] > x) return BinarySearch(a, l, mid - 1, x);
        return BinarySearch(a, mid + 1, r, x);
    }
    return -1;
}

int DemX(int a[], int l, int r, int x) {
    if (l == r) return (a[l] == x) ? 1 : 0;
    int mid = (l + r) / 2;
    return DemX(a, l, mid, x) + DemX(a, mid + 1, r, x);
}

int TimMaxIndex(int a[], int l, int r) {
    if (l == r) return l;
    int mid = (l + r) / 2;
    int leftMax = TimMaxIndex(a, l, mid);
    int rightMax = TimMaxIndex(a, mid + 1, r);
    return (a[leftMax] >= a[rightMax]) ? leftMax : rightMax;
}

int Max(int a, int b) { return (a > b) ? a : b; }
int Max3(int a, int b, int c) { return Max(Max(a, b), c); }

int MaxCrossingSum(int a[], int l, int mid, int r) {
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = mid; i >= l; i--) {
        sum += a[i];
        if (sum > left_sum) left_sum = sum;
    }
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = mid + 1; i <= r; i++) {
        sum += a[i];
        if (sum > right_sum) right_sum = sum;
    }
    return left_sum + right_sum;
}

int MaxSubArraySum(int a[], int l, int r) {
    if (l == r) return a[l];
    int mid = (l + r) / 2;
    return Max3(MaxSubArraySum(a, l, mid),
                MaxSubArraySum(a, mid + 1, r),
                MaxCrossingSum(a, l, mid, r));
}

int main() {

    int a[] = {-2, -5, 6, -2, -3, 1, 5, -6}; 
    int n = sizeof(a) / sizeof(a[0]);
    int x;

    printf("Mang a: ");
    for(int i=0; i<n; i++) printf("%d ", a[i]);
    printf("\n");

    // a) Tim kiem
    printf("Nhap x can tim: ");
    scanf("%d", &x);

    int pos = BinarySearch(a, 0, n - 1, x);
    if (pos != -1) printf("Tim thay %d tai vi tri %d\n", x, pos);
    else printf("Khong tim thay %d\n", x);

    // b) Dem
    printf("So lan xuat hien cua %d la: %d\n", x, DemX(a, 0, n - 1, x));

    // c) Max
    int idxMax = TimMaxIndex(a, 0, n - 1);
    printf("Phan tu lon nhat la %d tai vi tri %d\n", a[idxMax], idxMax);

    // d) 
    printf("Tong day con lon nhat la: %d\n", MaxSubArraySum(a, 0, n - 1));

    return 0;
}