int main(int c, char *v[])
{
    if (c >= 4 && c <= 21)
    {
        float s = 0;
        for (int i = 1; i < c; i++)
        {

            s += atoi(v[i]);
        }
        int n = c - 1;
        printf("TBC : %.2f ", s / n);
    }
    else
    {
        printf("sai");
    }
}