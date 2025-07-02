#include <stdio.h>

int main()
{
    int num = 5;
    int spaces = num;
    int stars = 1;
    char ch = 'A';

    for (int i = 1; i <= num; i++)
    {   
        printf("%*c", spaces, ' ');
        for(int j = 1; j <= 2 * i - 1; j++)
        {
            if (  j == 1 || j == 2 * i - 1 || i == num)
            {
                printf("%c", ch);
            }
            else
            {
                printf(" ");
            }
        }
        spaces--;
        ch++;
        printf("\n");
    }
    return 0;
}
