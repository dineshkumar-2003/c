#include <stdio.h>

void reverse(char* s, int start, int len)
{
    int left = start;
    int right = len - 1;

    while (left < right)
    {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

void reverse_word(char* string, int size)
{
    int start = 0;

    while (start < size)
    {
        int end = start;

        while (end < size && string[start] != ' ')
        {
            end++;
        }
        reverse(string, start, end);
        start = end;
    }
    printf("%s", string);
}

int main() 
{
    char string[100];
    int size;

    scanf("%[^\n]%n", string, &size);

    reverse(string, 0, size);

    printf("%s", string);

    reverse_word(string, size);

    return 0;
}
