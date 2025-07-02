#include <stdio.h>

void main()
{
    char string[] = "dineshkumara";
    int length = 12;
    int freq[26];

    for (int i = 0; i < 26; i++)
    {
        freq[i] = 0;
    }

    for(int i = 0; i < length; i++)
    {
        freq[string[i] - 'a']++;
    }

    for(int i = 0; i < 26; i++)
    {
        printf("%d  %d\n",freq[i], i );
    }
}