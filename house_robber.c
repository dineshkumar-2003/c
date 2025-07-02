#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int max_money(int* arr, int size)
{
    int* dp = (int*)calloc(sizeof(int), size);

    if(size == 1)
    {
        return arr[0];
    }

    dp[0] = arr[0];
    dp[1] = MAX(arr[0], arr[1]);

    for( int i = 2; i < size; i++)
    {
        dp[i] = MAX(dp[i - 1], dp[i - 2] + arr[i] );
    }
    return dp[size - 1];
}

int main()
{
    int arr[] = {2, 7, 9, 3, 1};
    int size = sizeof(arr) / sizeof(int);

    int result = max_money(arr,size);

    printf("%d\n", result);
    return 0;
}
