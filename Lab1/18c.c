#include <stdio.h>
#define Square(x) (x) * (x)
int main()
{
    int a = 2;
    printf("%d", Square(a + 3));
}
// lần này có ngoặc nên biểu thức khi gán a vào hàm marco sẽ là 
// (2+3)*(2+3) = 25