#include <stdio.h>

int count(int num)
{
    int ans=0;
    while (num > 0 )
    {
        ans++;
        num/=10;
    }
    return ans;
}

void main()
{
    int num;
    printf("Enter the number :");
    scanf("%d",&num);
    printf("The number of digits are %d\n", count(num));
}