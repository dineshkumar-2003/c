#include <stdio.h>

void main()
{
    char string[] = "hi hello";
    char result[40][40];
    int len = 8;
    int index = 0;
    int internal_index = 0;

    for (int i = 0; i < len; i++)
    {

        if (string[i] == ' ')
        {
            result[index][internal_index] = '\0'; 
            index++;
            internal_index = 0;
        }
        else
        {
            result[index][internal_index++] = string[i];
        }

        }
        result[index][internal_index] = '\0';
        index++;

    for(int i = 0; i < index; i++)
    {
        printf("%s\n", result[i]);
    }
}
