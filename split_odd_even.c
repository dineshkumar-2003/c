#include <stdio.h>

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void asc_sort(int* arr, int size) {
    int i,j;
    for (i = 0; i < size; i++) {
        for (j = i; j < size; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void desc_sort(int* arr,int start, int size) {
    int i,j;
    for (i = start; i < size; i++) {
        for (j = i; j < size; j++) {
            if (arr[i] < arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void split_odd_even(int* arr, int len)
{
    int odd_index = 0;
    for (int i = 0 ; i < len; i++)
    {
        if (arr[i] % 2 != 0)
        {
            int temp = arr[odd_index];
            arr[odd_index] = arr[i];
            arr[i] = temp;
            odd_index++;
        }
    }

    for( int i = 0; i < len; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");

    asc_sort(arr, odd_index - 1);
    desc_sort(arr, odd_index, 9);
}

void main()
{
    int arr[] = { 1,2,3,4,5,6,7,8,9,0};
    split_odd_even(arr, 10);

       for( int i = 0; i < 10; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");

}