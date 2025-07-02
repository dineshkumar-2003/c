#include <stdio.h>

int count_digits(long num)
{
    int count = 0;
    while (num > 0)
    {
        count++;
        num /= 10;
    }
    return count;
}

int kaprekar(int n)
{
     if (n == 1) return 1;

    long long sq = (long long)n * n;
    int num_digits = 0;
    long long temp = sq;

    while (temp) {
        num_digits++;
        temp /= 10;
    }

    long long pow10 = 1;
    for (int i = 1; i < num_digits; i++) {
        pow10 *= 10;
        long long right = sq % pow10;
        long long left = sq / pow10;

        if (right > 0 && (left + right == n))
            return 1;
    }

    return 0;
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Kaprekar numbers less than %d:\n", num);
    for (int i = 1; i < num; i++)
    {
        if (kaprekar(i))
        {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
