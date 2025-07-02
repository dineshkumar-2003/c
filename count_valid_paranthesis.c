#include <stdio.h>

void count_valid_paranthesis(char* string, int len)
{
    int count = 0;
    char stack[len];
    int top = -1;

    for(int i = 0; i < len; i++)
    {
        if(string[i] == '(')
        {
            stack[top++] = string[i];
        }
        else if (string[i] == ')' && top != -1)
        {
            count++;
            top--;
        }
    }
    printf("Valid paranthesis : %d\n", count);
}

void main()
{
    char string[] = "()())))";
    int len = 6;
    count_valid_paranthesis(string, len);
}