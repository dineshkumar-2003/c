#include <stdio.h>

int find (int i, int num)
{
    if ( i == 1 || i == num)
    {
        return 1;
    }

    return find(i - 1, num - 1) + find(i, num - 1);
}

int main()
{
    int num = 7;
    int result[10];

    for (int i = 1; i < num + 1; i++)
    {
        result[i] = find(i, num);
    }

    for(int j = 1; j <= num; j++)
    {
        printf("%d ",result[j]);
    }
    return 0;
}
