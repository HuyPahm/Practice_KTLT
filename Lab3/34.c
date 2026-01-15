#include <stdio.h>
#include <ctype.h>
#include <string.h>

int demKyTu(char s[]) {
    if (s[0] == '\0')
        return 0;
    return 1 + demKyTu(s + 1);
}

int demThuong(char s[]) {
    if (s[0] == '\0')
        return 0;
    int dem = (s[0] >= 'a' && s[0] <= 'z') ? 1 : 0;
    return dem + demThuong(s + 1);
}

int tongChuSo(char s[]) {
    if (s[0] == '\0')
        return 0;
    int tong = isdigit(s[0]) ? s[0] - '0' : 0;
    return tong + tongChuSo(s + 1);
}

int palindrome(char s[], int l, int r) {
    if (l >= r)
        return 1;
    if (s[l] != s[r])
        return 0;
    return palindrome(s, l + 1, r - 1);
}

int main() {
    char s[101];

    printf("Nhap chuoi: ");
    fgets(s, 101, stdin);

    s[strcspn(s, "\n")] = '\0';  // Xóa ký tự newline

    int n = demKyTu(s);
    int soThuong = demThuong(s);
    int tong = tongChuSo(s);
    int doiXung = palindrome(s, 0, n - 1);

    printf("So ky tu trong chuoi: %d\n", n);
    printf("So ky tu thuong: %d\n", soThuong);
    printf("Tong cac chu so trong chuoi: %d\n", tong);
    printf("Chuoi doi xung: %s\n", doiXung ? "Co" : "Khong");

    return 0;
}
