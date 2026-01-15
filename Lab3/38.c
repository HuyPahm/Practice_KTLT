#include <stdio.h>
#define MAX 100

void nhapChuoi(char s[], int i);
int demChuSo(char s[]);
int demHoa(char s[]);
int tangDan(char s[]);

void nhapChuoi(char s[], int i) {
    char c = getchar();
    if (c == '\n' || i == MAX) {
        s[i] = '\0';
        return;
    }
    s[i] = c;
    nhapChuoi(s, i + 1);
}

int demChuSo(char s[]) {
    if (s[0] == '\0')
        return 0;
    return (s[0] >= '0' && s[0] <= '9') + demChuSo(s + 1);
}

int demHoa(char s[]) {
    if (s[0] == '\0')
        return 0;
    return (s[0] >= 'A' && s[0] <= 'Z') + demHoa(s + 1);
}

int tangDan(char s[]) {
    if (s[1] == '\0')
        return 1;
    if (s[0] >= s[1])
        return 0;
    return tangDan(s + 1);
}

int main() {
    char s[MAX + 1];

    printf("Nhap chuoi: ");
    nhapChuoi(s, 0);

    printf("So chu so: %d\n", demChuSo(s));
    printf("So chu hoa: %d\n", demHoa(s));
    printf("Tang dan ASCII: %s\n", tangDan(s) ? "Co" : "Khong");

    return 0;
}
