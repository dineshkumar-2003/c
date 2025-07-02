#include <stdio.h>

void next_greatest(int* arr, int size) 
{
    int result[size];
    int next_great = -1;

    for( int i = size - 1; i >= 0; i--) 
    {
        result[i] = next_great;
        if(arr[i] > next_great) 
        {
            next_great = arr[i];
        }
    }

    for(int i = 0; i < size; i++) 
    {
        printf("%d\t", result[i]);
    }
    printf("\n");
}

void main()
{
    int arr[] = {16, 17, 4, 3, 5, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    next_greatest(arr,size);
}