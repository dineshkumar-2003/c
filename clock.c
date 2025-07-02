#include <stdio.h>

void main()
{
    int num = 5;
    int stars = num;
    int spaces = 1;

    for(int i = 0; i < 2 * num - 1; i++)
    {   
        printf("%*c", spaces, ' ');
        for(int j = 0; j < stars; j++)
        {
            printf("* ");
        }


        printf("\n");

        if (i < num - 1)
        {
            spaces++;
            stars--;
        }
        else
        {
            spaces--;
            stars++;
        }

    }
}
