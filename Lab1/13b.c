#include<stdio.h>
#include<stdlib.h>
int main(int c, char *v[])
{
    if (c >= 4 && c <= 21)
    {
        float s = 0;
        for (int i = 1; i < c; i++)
        {

            s += atof(v[i]);
        }
        // setup cho n để tính tbc
        int n = c - 1; 
        printf("TBC : %.2f ", s / n);
    }
    else
    {
        printf("sai");
    }
}