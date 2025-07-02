#include <stdio.h>

int main()
{
    int num = 5;
    int spaces = 1;
    int stars = num;

    for(int i = 1; i < 2 * num; i++)
    {
        printf("%*c", spaces, ' ');

        for (int j = 1; j <= stars; j++)
        {
            printf("* ");
        }
        
        if(i < num)
        {
            stars--;
            spaces++;
        }
        else
        {
            stars++;
            spaces--;
        }
        printf("\n");
    }

    return 0;
}
