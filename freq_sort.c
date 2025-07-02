#include <stdio.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int* freq, int left, int right)
{
    int pivot = arr[right];
    int i = left - 1;

    for ( int j = left; j < right; j++)
    {
        if (freq[arr[j]] > freq[pivot] || (freq[arr[j]] == freq[pivot] && arr[j] < pivot))
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

void quicksort(int* arr, int size, int* freq, int left, int right )
{
    if (left < right)
    {
        int pivot = partition(arr, freq, left, right);
        quicksort(arr, size, freq, left, pivot - 1);
        quicksort(arr, size, freq, pivot  + 1, right);
    }
}

void main()
{
    int arr[] = { 1, 2, 2, 2, 4, 5 ,6, 7, 8, 8, 9, 9, 9, 9, 9};
    int size = sizeof(arr) / sizeof(int);
    int freq[100] = {0};

    for (int  i = 0 ; i < size; i++)
    {
        freq[arr[i]]++;
    }

    quicksort(arr, size, freq, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}