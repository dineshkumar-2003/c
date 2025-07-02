#include <stdio.h>

void insertion_sort(int*arr, int size)
{
    for(int i =1; i< size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void main()
{
    int arr[] = {3, 5, 6 ,8,2,4};
    int size = sizeof(arr) / sizeof(int);

    insertion_sort(arr, size);

    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}