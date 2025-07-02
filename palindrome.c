# include <stdio.h>

void palindrome(char* s, int length) {
    int left = 0;
    int right = length - 1;
    int flag = 0;

    while (left <= right) {
        if (s[left] == s[right]) {
            left++;
            right--;
        }
        else {
            flag = 1;
            break;
        }
    }

    if(flag == 0) {
        printf("It is a palindrome \n");
    }
    else {
        printf("It is not a palindrome \n");
    }
}

int string_length(char* s) {
    int length = 0;
    while(s[length] != '\0') {
        length++;
    }
    return length;
}

void main() {
    char string[] = "momo";
    int length = string_length(string);
    palindrome(string, length);
}