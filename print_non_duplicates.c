#include <stdio.h>

int main()
{
    char string[100];
    int size;
    int count[26] = {0};
    char result[100];
    int index = 0;

    printf("Enter the string : ");
    scanf("%s%n", string, &size);

    for (int i = 0; i < size; i++)
    {
        if (count[string[i] - 'a'] != 0)
            continue;
        count[string[i] - 'a']++;
        result[index++] = string[i];
    }
    result[index] ='\0';

    printf("%s", result);



}
