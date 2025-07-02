#include <stdio.h>

void snake_pattern(int number)
{
    int num = 1;
    int x = number;
    for(int i = 0; i < number; i++)
    {
        for(int j = 0; j < number; j++)
        {
            if(i % 2 == 0) {
                printf("%d\t", num++);
            }
            else
            {
                
                printf("%d\t",(num + x - 1 ) );

                if(num == (num + x - 1))
                {
                
                    num += number;
                    x = number + 1;   
                }
                x--;
            }
        }
        printf("\n");
    }
}

void main()
{
    int number;
    printf("Enter the number : ");
    scanf("%d", &number);
    snake_pattern(number);
}