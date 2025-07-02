#include <stdio.h>

void number_diamond(int number)
{
    int k = 1;
    for (int i = 1; i <= number; i++)
    {
        for (int j = 1; j <= number - i; j++)
        {
            printf("  ");
        }

        int temp = k + i - 1;

        for (int j = 1; j <= i; j++)
        {
            printf(" %d ", temp--);
        }
        k += i;
        printf("\n");
    }

    k -= number;

    for(int i = number; i >= 1; i--)
    {

        for (int j = 1; j <= number - i; j++)
        {
            printf("  ");
        }

        int temp = k + i - 1;

        for (int j = 1; j <= i; j++)
        {
            printf(" %d ", temp--);
        }
        k = k - i + 1;
        printf("\n");
    }
}

void main()
{
    int number;

    printf("Enter the number : ");
    scanf("%d", &number);

    number_diamond(number);
}