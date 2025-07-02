#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void rotate_k_elements(int* arr, int k, int size) {
    int i, left, right;

    for(i = 0; i < size; i+=k) {
        left = i;
        right = (i + k - 1)  >= size ? size - 1 : i + k - 1;

        while (left <= right) {
            swap(&arr[left], &arr[right]);
            left++;
            right--;
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

void main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int k = 5;
    int size = sizeof(arr) / sizeof(arr[0]);

    print_array(arr, size);
    rotate_k_elements(arr, k, size);
    print_array(arr, size);
}