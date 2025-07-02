#include <stdio.h>

void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b =temp;
}

void permute(char* string, int start, int end)
{
    int i;

    if (start == end)
    {
        printf("%s\n", string);
    }
    else
    {
        for(i = start; i <= end; i++)
        {
            swap((string + start), (string + i));
            permute(string, start + 1, end);
            swap((string + start), (string + i));
        }
    }
}

int main()
{
    char string[] = "abc";
    int length = 3;
    permute(string, 0, length - 1);
    return 0;
}