#include <stdio.h>
#include <stdlib.h>

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

void desc_sort(int* arr, int size) {
    int i,j;
    for (i = 0; i < size; i++) {
        for (j = i; j < size; j++) {
            if (arr[i] < arr[j]) {
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

void odd_even_place_sort(int* arr, int size) {
    int* odd_arr = (int*)malloc(sizeof(int) * (size / 2));
    int* even_arr = (int*)malloc(sizeof(int) * (size / 2));
    int odd_index = 0;
    int even_index = 0;

    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            even_arr[even_index++] = arr[i];
        }
        else {
            odd_arr[odd_index++] = arr[i];
        }
    }

    desc_sort(odd_arr, odd_index);
    print_array(odd_arr, odd_index);
    asc_sort(even_arr, even_index);
    print_array(even_arr, even_index);

    int* result = (int*)malloc(sizeof(int) * size);
    int result_index = 0;
    int odd_ind = 0;
    int even_ind = 0;

    for(int i = 0; i < size ; i++) {
        if (result_index <= size && odd_ind < odd_index) {
            // printf("odd : %d", odd_arr[odd_ind]);
            result[result_index++] = odd_arr[odd_ind++];    
        }
        if (result_index <= size && even_ind < even_index) {
            // printf("even : %d", even_arr[even_ind]);
            result[result_index++] = even_arr[even_ind++];
        }
    }
    
    print_array(result, size);

}

void main() {
    int arr[] = {22, 3, 44, 5, 87, 97, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    print_array(arr, size);
    odd_even_place_sort(arr, size);
}

