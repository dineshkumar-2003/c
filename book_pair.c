#include <stdio.h>

int min3(int a, int b, int c)
{
    if (a < b && a < c)
        return a;
    else if (b < c)
        return b;
    return c;
}

int solve(int *arr, int left, int right, int pair_cost, int k)
{
    if (left > right)
        return 0;

    int cost1 = arr[left] + solve(arr, left + 1, right, pair_cost, k);

    int cost2 = arr[right] + solve(arr, left, right - 1, pair_cost, k);

    int cost3 = 1e9;
    if (k > 0 && left < right)
    {
        cost3 = pair_cost + solve(arr, left + 1, right - 1, pair_cost, k - 1);
    }

    return min3(cost1, cost2, cost3);
}

void get_cost(int *arr, int size, int left, int right, int pair_cost, int k)
{
    int result = solve(arr, left, right, pair_cost, k);
    printf("Minimum cost: %d\n", result);
}

int main()
{
    int arr[] = {14, 15, 2, 34, 33};
    int size = sizeof(arr) / sizeof(int);
    int k = 1;
    int pair_cost = 6;

    get_cost(arr, size, 0, size - 1, pair_cost, k);

    return 0;
}



// #include <stdio.h>
// #include <string.h>

// #define MAXN 105
// #define INF 1000000000

// int dp[MAXN][MAXN][MAXN];

// int min3(int a, int b, int c)
// {
//     if (a < b && a < c)
//         return a;
//     else if (b < c)
//         return b;
//     return c;
// }

// int solve(int *arr, int left, int right, int pair_cost, int k)
// {
//     if (left > right) return 0;

//     if (dp[left][right][k] != -1)
//         return dp[left][right][k];

//     int cost1 = arr[left] + solve(arr, left + 1, right, pair_cost, k);   // pick left
//     int cost2 = arr[right] + solve(arr, left, right - 1, pair_cost, k);  // pick right
//     int cost3 = INF;

//     if (k > 0 && left < right)
//     {
//         cost3 = pair_cost + solve(arr, left + 1, right - 1, pair_cost, k - 1);
//     }

//     return dp[left][right][k] = min3(cost1, cost2, cost3);
// }

// void get_cost(int *arr, int size, int left, int right, int pair_cost, int k)
// {
//     memset(dp, -1, sizeof(dp));
//     int result = solve(arr, left, right, pair_cost, k);
//     printf("Minimum cost: %d\n", result);
// }

// int main()
// {
//     int arr[] = {14, 15, 2, 34, 33};
//     int size = sizeof(arr) / sizeof(int);
//     int k = 1;
//     int pair_cost = 6;

//     get_cost(arr, size, 0, size - 1, pair_cost, k);

//     return 0;
// }
