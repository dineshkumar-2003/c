#include <stdio.h>

void main()
{
    int num;
    char sp = ' ';
    int stars = 1;

    scanf("%d", &num);

    int spaces = num;
    int end;

    for(int i = 1; i <= 2 * num - 1; i++)
    {

        if (i < num)
        {
            spaces = num - i + 1;
            end = 2 * i - 1;
        }

        else
        {
            spaces = i - num + 1;
            end = 2 * (2 * num - i) - 1;
        }

        printf("%*c", spaces, ' ');

        for(int j = 1; j <= end; j++)
        {
            if (j == 1 || j == end)
                printf("*");

            else
                printf(" ");
        }
        printf("\n");
    }
}