#include <stdio.h>

void subset_sum(int* arr, int size, int* subset, int subset_size, int target, int index, int current_sum)
{
    if (current_sum == target)
    {
        for (int i = 0; i < subset_size; i++)
            printf("%d ", subset[i]);

        printf("\n");
        return;
    }

    if (index == size || current_sum > target)
    {
        return;
    }

    subset[subset_size] = arr[index];
    subset_sum(arr, size, subset, subset_size + 1, target, index + 1, current_sum + arr[index]);

    subset_sum(arr, size, subset, subset_size, target, index + 1, current_sum);
}

void main()
{
    int arr[] = {8, 2, 3, 10, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int subset[100];

    subset_sum(arr, size, subset, 0, target, 0, 0);
}