#include <stdio.h>

#define MAX 1000

void lookAndSay(int current[], int length, int next[], int *nextLength)
{
    int count = 1, j = 0;
    for (int i = 1; i <= length; i++)
    {
        if (i < length && current[i] == current[i - 1])
        {
            count++;
        }
        else
        {
            next[j++] = count;
            next[j++] = current[i - 1];
            count = 1;
        }
    }
    *nextLength = j;
}

void printTerm(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    int current[MAX];
    int next[MAX];
    int currentLength = 1;
    int nextLength = 0;

    current[0] = 1;

    printTerm(current, currentLength);

    for (int i = 1; i < n; i++)
    {
        lookAndSay(current, currentLength, next, &nextLength);

        printTerm(next, nextLength);

        for (int j = 0; j < nextLength; j++)
        {
            current[j] = next[j];
        }
        currentLength = nextLength;
    }

    return 0;
}
