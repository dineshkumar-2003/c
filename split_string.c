#include <stdio.h>

void split_string(char *str, char delimiter)
{
    int i = 0;
    int start = 0;

    while (str[i] != '\0')
    {

        if (str[i] == delimiter || str[i + 1] == '\0')
        {
            int end = (str[i + 1] == '\0') ? i + 1 : i;
            for (int j = start; j < end; j++)
            {
                putchar(str[j]);
            }
            putchar('\n');

            start = i + 1;
        }
        i++;
    }
}

int main()
{
    char str[] = "Hello world this is C programming";
    char delimiter = ' ';

    split_string(str, delimiter);

    return 0;
}
