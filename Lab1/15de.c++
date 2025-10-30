#include <iostream>
using namespace std;

double dientich(double dai, double rong)
{
    return dai * rong;
}

double dientich(double banKinh)
{
    return 3.14 * banKinh * banKinh;
}

int main()
{
    double dai, rong, r;

    cout << "Nhap chieu dai va chieu rong hinh chu nhat: ";
    cin >> dai >> rong;
    double SHCN = dientich(dai, rong);
    cout << "Dien tich hinh chu nhat = " << SHCN << endl;

    cout << "\nNhap ban kinh hinh tron: ";
    cin >> r;
    double STron = dientich(r);
    cout << "Dien tich hinh tron = " << STron << endl;

    return 0;
}
