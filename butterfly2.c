#include <stdio.h>

int main()
{
    int n = 5;
    int start;
    int end;

    for (int i = 1; i < 2 * n; i++)
    {
        for (int j = 1; j < 2 * n; j++)
        {
            if (i < n)
            {
                start = i;
                end = 2 * n - i;
            }
            else
            {
                start = 2 * n - i;
                end = i;
            }

            if(j <= start || j >= end)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    } 

    return 0;
}
