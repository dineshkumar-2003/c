#include <stdio.h>

int digital_root(int num)
{
    int sum = 0;
    if (num < 10)
    {
        return num;
    }

    while(num > 0)
    {
        sum += num % 10;
        num /= 10;
    }

  return  digital_root(sum);
}

int main()
{
    int num, count;
    scanf("%d%n", &num, &count);
    int sum = 0;
    printf("%d \n", digital_root(num));
    return 0;
}
