#include <stdio.h>

void swap(int *a , int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_desc(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for( int j = i; j < size; j++)
        {
            if(arr[i] < arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

int count_digits(int num)
{
    int count = 0;
    while(num > 0)
    {
        count++;
        num/=10;
    }
    return count;
}

void main()
{
    int arr[] = {2, 5, 9, 99, 78};
    int size = sizeof(arr) / sizeof(int);
    int dig = 4;
    int max = 0;

    sort_desc(arr, size);

    for(int i = 0; i < size; i++)
    {
        printf("%d " ,arr[i]);
    }

    int counts[size];

    for(int i = 0 ; i < size; i++)
    {
        counts[i] = count_digits(arr[i]);
    }

    for (int i = 0; i < size; i++)
    {
        if (counts[i] > dig){
            i++;
        }
        else if (counts[i] == dig)
        {
            max = max < arr[i] ? arr[i] : max;
            i++;
        }
        int num = 0;
        while (i + 1 < size && count_digits(arr[i] * 10 + arr[i + 1]) <= dig)
        {
            //printf("Entry");
            arr[i + 1] = arr[i] * 10 + arr[i + 1];
            num = arr[i + 1];
            //printf("%d", num );
            i++;
        }

        max = num > max ? num : max;
    }

    printf("%d", max);

}