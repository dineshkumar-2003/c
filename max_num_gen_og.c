#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int count_digits(int num)
{
    int count = 0;
    while (num > 0)
    {
        count++;
        num /= 10;
    }
    return count;
}

void sort_desc(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (arr[i] < arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

int pow10a(int count)
{
    int num = 1;
    while (count > 0)
    {
        num *= 10;
        count--;
    }
    return num;
}

int main()
{
    int arr[] = {99, 9, 998, 7};
    int size = sizeof(arr) / sizeof(int);
    int dig = 6;
    int max = 0;

    sort_desc(arr, size);

    for (int i = 0; i < size; i++)
    {
        int num = arr[i];
        printf("%d\n", num);

        if (count_digits(num) <= dig && num > max)
        {
            max = num;
        }

        for (int j = 0; j < size; j++)
        {
            if (i == j) continue;

            int k = count_digits(arr[j]);
            int temp = num * pow10a(k) + arr[j];

            printf("%d\n", temp);

            if (count_digits(temp) <= dig)
            {
                if (temp > max)
                {
                    max = temp;
                }

                num = temp;
            }
            else
            {
                continue;
            }
        }
    }

    printf("%d ", max);
    return 0;
}
