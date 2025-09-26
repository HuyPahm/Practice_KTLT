#include <stdio.h>
#define Square(x) (x) * (x)
int main()
{
    int a = 2;
    printf("%d", Square(a));
    // thế a vào tham số x của hàm macro Square
    //  2 * 2 = 4  
}