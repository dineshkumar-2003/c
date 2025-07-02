#include <stdio.h>

void  move_zeros(int* arr, int len)
{
    int index = 0;

    for ( int i = 0; i < len; i++)
    {
        if (arr[i] != 0)
        {
            arr[index++] = arr[i];
        }
    }

    for(int i = index ; i < len; i++)
    {
        arr[index++] = 0;
    }

    for (int i = 0; i < len; i++ )
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void next_valid(int* arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            arr[i] *= 2;
            arr[i + 1] = 0;
        }
    }

    move_zeros ( arr, len);
}

void main()
{
    int arr[] = {2, 2, 0, 4, 0, 8};
    int size = sizeof(arr) / sizeof(int);

    next_valid(arr, size);
}