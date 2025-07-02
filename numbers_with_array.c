#include <stdio.h>

void print_num(int *arr, int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d \n", arr[i]);
    }
}

void swap_num(int *arr, int size)
{   
    int rev = 0;
    
    int temp = arr[0];
    arr[0] = arr[size - 1];
    arr[size - 1] = temp;

    for(int i = size - 1; i > -1; i--)
    {
        rev = (rev * 10) + arr[i];
    }

    printf("The number after reversing is : %d\n",rev );
    print_num(arr, size);
}

void add(int *arr, int size)
{
    printf("The sum of first and last digits are : %d\n", arr[0] + arr[size - 1]);
}

void split_num(int number)
{
    int arr[10];
    int size = 0;

    while (number > 0)
    {
        arr[size++] = number % 10;
        number /= 10;
    }

    print_num(arr, size);
    swap_num(arr, size);
    add(arr, size);
}

void main()
{
    int number;

    printf("Enter the number : ");
    scanf("%d", &number);
    split_num(number);
}