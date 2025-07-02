#include <stdio.h>
#include <string.h>

void lookAndSay(char *current, char *next)
{
    int len = strlen(current);
    int count = 1, j = 0;

    for (int i = 1; i <= len; i++)
    {
        if (i < len && current[i] == current[i - 1])
        {
            count++;
        }
        else
        {
            next[j++] = count + '0';
            next[j++] = current[i - 1];
            count = 1;
        }
    }
    next[j] = '\0';
}

int main()
{
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    char current[1000] = "1";
    char next[1000];

    printf("%s\n", current);
    for (int i = 1; i < n; i++)
    {
        lookAndSay(current, next);
        printf("%s\n", next);
        strcpy(current, next);
    }

    return 0;
}
