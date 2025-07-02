#include <stdio.h>

void print_num(int number)
{
    int temp = number;
    while (temp > 0)
    {
        printf("%d \n",temp % 10);
        temp/=10;
    }
}

void swap_num(int number) {
    
}

void add_number(int number) {
    int temp = number;
    int sum = temp % 10;
    int a;
    while(temp > 0)
    {
        a = temp % 10;
        temp/=10;
    }

    printf("The sum of first and last digits are : %d\n", a + sum);
}
void main() {
    int number;
    printf("Enter the number : ");
    scanf("%d",&number);
    print_num(number);
    add_number(number);
}