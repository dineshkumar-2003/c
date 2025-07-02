#include <stdio.h>

int max (int a, int b)
{
    return a > b ? a : b;
}

int dp (int* nums, int n, int start, int end)
{
    int len = end - start + 1;

    if (len == 1)
    {
        return nums[start];
    }

    int dp_[len];

    dp_[0] = nums[start];
    dp_[1] = max(nums[start], nums[start + 1]);

    for (int i = 2; i < len; i++)
    {
        dp_[i] = max(dp_[i - 1], dp_[i - 2] + nums[i + start]);
    }
    return dp_[len - 1];
}

int rob(int* nums, int numsSize) {

    if (numsSize == 1)
    {
       return nums[0];
    }

    if (numsSize  == 2)
    {
        return max(nums[0], nums[1]);
    }

    int dp1 = dp(nums, numsSize, 0 , numsSize - 2);

    int dp2 = dp(nums, numsSize, 1, numsSize - 1);

    return max(dp1, dp2);

}

int main()
{
    int arr[] = {2, 7, 9, 3, 12, 8 ,};
    int size = sizeof(arr) / sizeof(int);

    int result = rob(arr,size);

    printf("%d\n", result);
    return 0;
}
