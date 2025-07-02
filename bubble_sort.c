#include <stdio.h>
#include <stdbool.h>

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubble_sort(int arr[], int n)
{
    int i, j;
    bool swapped;

    for(i = 0; i < n - 1; i++){
        swapped = false;
        for(j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }
        if (swapped == false){
            break;
        }
    }
}

void main(){
    int i;
    int arr[] = {12,32,43,53,23};
    int size = sizeof(arr) / sizeof(int);

    bubble_sort(arr,size);

    for (i = 0; i < size; i++)
    {
        printf("%d\t", *(arr + i));
    }
}