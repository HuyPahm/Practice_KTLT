#include <stdio.h>
int main()
{
    int d;
    scanf("%d", &d);
    if (d >= 0)
    {
        if (d < 50)
            printf("Truot");
        else
        {
            if (d < 65)
                printf("Trung binh");
            else
            {
                if (d < 80)
                    printf("Kha");
                else
                {
                    printf("Gioi");
                }
            }
        }
    }
    return 0;
}