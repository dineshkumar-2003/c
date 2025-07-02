#include <stdio.h>

int check(char ch)
{
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
}

int main()
{
    char string[] = "hello : dinesh@ 256";
    int len = 19;
    int left = 0;
    int right = len - 1;

    while(left < right)
    {
        if (!check(string[left]))
        {
            left++;
        }
        else if (!check(string[right]))
        {
            right--;
        }
        else
        {
        char temp = string[left];
        string[left] = string[right];
        string[right] = temp;

        left++;
        right--;
        }
    }

    printf("%s",string);

    return 0;
}
