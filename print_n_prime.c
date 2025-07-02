#include <stdio.h>
#include <stdbool.h>

void print_n_prime(int num)
{
    int prime_count = 0, number = 2;
    bool flag = false;

    while (prime_count < num)
    {
        flag = true;

        for (int j = 2; j < number / 2 + 1; j++)
        {
            if (number % j == 0)
            {
                flag = false;
                break;
            }
        }

        if(flag)
        {
            printf("%d\t",number);
            prime_count++;
        }
        number++;
    }
    printf("\n");
    
}

void main()
{
    int number;
    printf("Enter an integer : ");
    scanf("%d", &number);

    print_n_prime(number);
}