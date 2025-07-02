#include <stdio.h>

int main()
{
    int num = 5;

    for(int i = 1; i < num + 1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%d", (i + j) % 2);
        }
        printf("\n");
    }
    return 0;
}
