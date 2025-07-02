// #include <stdio.h>

// int index_ = 0;

// int ispali(char* string, int start, int end)
// {
//     int left = start, right = end;

//     while (left < right)
//     {
//         if (string[left] == string[right])
//         {
//             left++;
//             right--;
//         }
//         else
//         {
//             return 1;
//         }
//     }
//     return 0;
// }

// void ispalindrome(char* string, int start, int end)
// {
//     int flag = ispali(string, start, end);

//     if (flag == 0)
//         return;

//     char result[1000000];

//     for (int i = start; i < end; i++)
//     {
//         result[index_++] = string[i];
//     }
//     result[index_] = ' ';

//     printf("%s", result);

// }

// void main()
// {
//     char string[100];
//     int length;
//     printf("Enter the string : ");
//     scanf("%[^\n]%n", string, &length);
    
//     int i = 0;
//     while (i < length)
//     {
//         int j = i;
//         while (string[j] != ' ' && string[j] != '\0')
//         {
//             j++;
//         }
//         ispalindrome(string, i, j);
//         i = j;
//     }
// }

#include <stdio.h>
#include <string.h>

int index_ = 0;
char result[1000000]; // Make this global to accumulate non-palindromes

int ispali(char* string, int start, int end)
{
    int left = start, right = end;

    while (left < right)
    {
        if (string[left] != string[right])
        {
            return 1; // Not a palindrome
        }
        left++;
        right--;
    }
    return 0; // Is a palindrome
}

void ispalindrome(char* string, int start, int end)
{
    int flag = ispali(string, start, end - 1);

    if (flag == 0)
        return;

    for (int i = start; i < end; i++)
    {
        result[index_++] = string[i];
    }
    result[index_++] = ' ';
}

int main()
{
    char string[100];
    int length;

    printf("Enter the string: ");
    scanf("%[^\n]%n", string, &length);

    int i = 0;
    while (i < length)
    {
        while (i < length && string[i] == ' ') i++; // Skip spaces
        int j = i;

        while (j < length && string[j] != ' ') j++;

        if (i < j)
            ispalindrome(string, i, j);
        
        i = j;
    }

    result[index_] = '\0'; // Null terminate the result string

    printf("Non-palindromic words: %s\n", result);
    return 0;
}
