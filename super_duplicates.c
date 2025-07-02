#include <stdio.h>

int length(char *string)
{
    int len = 0;

    while (string[len] != '\0')
        len++;

    return len;
}

void super_duplicates(char *string, int len)
{
    int characters[26] = {0};
    int digits[10] = {0};

    for (int i = 0; i < len; i++)
    {
        char ch = string[i];

        if (ch >= 'a' && ch <= 'z')
        {
            int index = ch - 'a';

            if (characters[index] > 0)
            {
                int new_index = (index + 1) % 26;

                while (characters[new_index] > 0)
                {
                    new_index = (new_index + 1) % 26;
                }
                ch = 'a' + new_index;

                string[i] = ch;

                characters[new_index]++;
            }
            else
            {
                characters[index]++;
            }
        }
        else if (ch >= '0' && ch <= '9')
        {
            int index = ch - '0';

            if (digits[index] > 0)
            {
                int new_index = (index + 1) % 10;

                while (digits[new_index] > 0)
                {
                    new_index = (new_index + 1) % 10;
                }

                ch = '0' + new_index;
                string[i] = ch;
                digits[new_index]++;
            }
            else
            {
                digits[index]++;
            }
        }
    }

    printf("After changing the duplicates : %s\n", string);
}

void main()
{
    char string[100];

    printf(" Original string : %s", string);
    scanf("%s", string);

    int len = length(string);

    super_duplicates(string, len);
}