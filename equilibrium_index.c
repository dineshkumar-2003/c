#include <stdio.h>

void find_equilibrium(int* arr, int len)
{
    int prefix_sum = 0, postfix_sum = 0;

    for (int i = 1; i < len; i++)
    {
        postfix_sum += arr[i];
    }

    for( int i = 1; i < len; i++)
    {
        prefix_sum += arr[i - 1];
        postfix_sum -= arr[i];

        printf("prefix : %d\n",prefix_sum);
        printf("postfix : %d\n", postfix_sum);

        if (prefix_sum == postfix_sum)
        {
            printf("The equilibrium index is  : %d\n", i);
            return;
        }
        
    }
    printf("The equilibrium index is  : -1 \n");
}

void find_equilibrium2(int* arr, int len)
{
    if (len < 3)
    {
        printf("The equilibrium index is  : -1 \n");
        return;
    }

    int total_sum = 0;
    for (int i = 0; i < len; i++)
        total_sum += arr[i];

    int left_sum = 0;

    for (int i = 0; i < len; i++)
    {
        int right_sum = total_sum - left_sum - arr[i];

        if (left_sum == right_sum)
        {
            printf("The equilibrium index is  : %d\n", i);
            return;
        }

        left_sum += arr[i];
    }

    printf("The equilibrium index is  : -1 \n");

}

void main()
{
    int arr1[] = {-7, 1, 5, 2, -4, 3, 0};
    int arr[] = {0, -3, 1, 2};
    int len = 4;
    find_equilibrium2(arr, len);
}