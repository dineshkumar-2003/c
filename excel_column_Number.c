#include <stdio.h>

int titleToNumber(char* columnTitle) {
    int len = strlen(columnTitle);
    int ans = 26;
    if (len < 2)
    {
        ans = columnTitle[len - 1] - 'A';
    }
    for ( int i = 0; i < len; i++)
    {
        if ( i == len - 1 )
        {
            ans += columnTitle[i] - 'A' + 1;
            break;
        }
        ans *= columnTitle[i] - 'A' + 1;
    }
    return ans;
}

int main()
{
    char string[] = "FXSHR";
    return 0;
}
