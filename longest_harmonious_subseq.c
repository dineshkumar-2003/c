#include <stdio.h>

void sort(int* arr, int size)
{
    for ( int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }

        arr[j + 1] = key;
    } 
}

void print_array(int* arr, int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%d \t", arr[i]);
    }

    printf("\n");
}

void longest_harmonious_subsequence(int* arr, int size)
{
    int left = 0;
    int max_freq = 0;

    for (int right = 0; right < size; right++)
    {
        while (left < right && arr[right] - arr[left] > 1)
        {
            left++;
        }

        if (arr[right] - arr[left] == 1)
        {
            int curr_freq = right - left + 1;
            if (curr_freq > max_freq)
                max_freq = curr_freq;
        }
    }

    printf("%d\n", max_freq);
}


int main()
{
    int arr[] = {1, 3, 2, 2, 5, 2, 3, 7};
    int size = sizeof(arr) / sizeof(int);

    sort(arr, size);

    print_array(arr, size);

    longest_harmonious_subsequence(arr, size);
    return 0;
}
