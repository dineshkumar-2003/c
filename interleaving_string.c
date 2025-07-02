#include <stdio.h>

void get_string(char* str)
{
    scanf("%s", str);
}

int main()
{
    char* string1[1000];
    char* string2[1000];
    char* main_str[1000];

    get_string(string1);
    get_string(string2);
    get_string(main_str);

    int s1_ptr = 0;
    int s2_ptr = 0;
    int main_ptr = 0;

    

    return 0;
}
