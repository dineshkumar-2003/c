#include <stdio.h>

void swap(int *a , int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_desc(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for( int j = i+1; j < size; j++)
        {
            if(arr[i] < arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

int count_digits(int num)
{
    int count = 0;
    while(num > 0)
    {
        count++;
        num /= 10;
    }
    return count;
}

void main()
{
    int arr[] = {2, 5, 9, 99, 78};
    int size = sizeof(arr) / sizeof(int);
    int dig = 4;
    int max = 0;

    sort_desc(arr, size);

    for (int i = 0; i < size; i++)
    {
        int num = arr[i];
        if (count_digits(num) <= dig && num > max)
            max = num;

        for (int j = i + 1; j < size; j++)
        {
            // Form new number by appending arr[j]
            int temp = num * 10 + arr[j];
            printf(" num : %d, arrj : %d\n", num, arr[j]);
            printf("remmp ; %d\n", temp);

            if (count_digits(temp) <= dig)
            {
                if (temp > max)
                    max = temp;
                num = temp;  // continue building on this
                printf("%d", num);
            }
            else
                break;  // if it exceeds digit limit, stop appending
            printf("\n");
        }
    }

    printf("Max %d-digit number: %d\n", dig, max);
}
