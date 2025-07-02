#include <stdio.h>
#include <stdlib.h>

#define MAX 1000 

int freq[MAX] = {0};

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int pivotFreq = freq[pivot];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (freq[arr[j]] > pivotFreq ||
            (freq[arr[j]] == pivotFreq && arr[j] < pivot))
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[] = {4, 5, 6, 5, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
