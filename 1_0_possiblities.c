#include <stdio.h>

void count_0_1_possibilities(int number)
{
    int count = 0;
    int eleven = number / 11;

    number = number - 11 * eleven;

    int ten = number / 10;

    number = number - 10 * ten;
    
    int one = number / 1;
    
    count = eleven + ten + one;

    printf("Count : %d\n", count);
}

void main()
{
    int number;
    printf("Enter the number : ");
    scanf("%d", &number);

    count_0_1_possibilities(number);
}