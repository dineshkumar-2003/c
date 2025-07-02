#include <stdio.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b =temp;
}

void permute(int* arr, int start, int end)
{
    int i;
    if(start == end)
    {
        for(int j = 0 ; j < 3; j++)
        {
            printf("%d", arr[j]);
        }
        printf("\n");
    }
    else
    {
        for(i = start; i <= end; i++)
        {
            swap((arr + start), (arr + i));
            permute(arr, start + 1, end);
            swap((arr + start), (arr + i));
        }
    }
}

int main()
{
    int arr[] = {1,2,3};
    int length = 3;

    permute(arr, 0, length - 1);

    return 0;
}