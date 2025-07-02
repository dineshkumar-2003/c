#include <stdio.h>

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int* arr, int size) {
    int i,j;
    for (i = 0; i < size; i++) {
        for (j = i; j < size; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void print_array(int* arr, int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%d \t", arr[i]);
    }
    printf("\n");
}

int* alternative_sort(int* arr, int size) {
    int left = 0, right = size - 1;
    int* res = (int*)malloc(sizeof(int)*size);
    int current_index = 0;
    while(left <= right) {
        if (current_index < size) {
            res[current_index++] = arr[right--];
        }
        if (current_index < size) {
            res[current_index++] = arr[left++];
        }
    }
    return res;
}

void main() {
    int arr[] = {1, 334, 34, 45, 56};
    int size = sizeof(arr) / sizeof(int);
    int* res = (int*)malloc(sizeof(int) * size);
    sort(arr, size);
    print_array(arr, size);
    res = alternative_sort(arr, size);
    print_array(res, size);
}