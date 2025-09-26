#include <stdio.h>
#define Square(x) x *x
int main()
{
    int a = 2;
    printf("%d", Square(a + 3));
    // cái này trong hàm marco nó ko có ngoặc "(x)" nên biểu thức khi thế vào sẽ trở thành 2+3*2+3 
    // vậy nên cho ra 11
}