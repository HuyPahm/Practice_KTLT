#include <stdio.h>

float tinhHocBong(float heSo, float mucCoBan) {
    return heSo * 600000;
}

int main() {
    float diemTB;
    printf("Nhap: ");
    scanf("%f", &diemTB);

    float heSo = 1.0;
    float mucCoBan = 600000;
    float hocBong;

    if (diemTB >= 7 && diemTB < 8)
        heSo = 1.0;
    else if (diemTB >= 8 && diemTB < 9)
        heSo = 1.3;
    else if (diemTB >= 9 && diemTB <= 10)
        heSo = 1.5;
    else {
        printf("Sai");
        return 0;
    }

    hocBong = tinhHocBong(heSo, mucCoBan);
    printf("Hoc bong cua sinh vien la: %.0f VND\n", hocBong);

    return 0;
}
