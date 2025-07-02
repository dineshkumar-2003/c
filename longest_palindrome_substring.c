#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool check(char* s, int i, int j) {
    int left = i;
    int right = j - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int string_length(char* s) {
    int length = 0;
    while(s[length] != '\0') {
        length++;
    }
    return length;
}

char* longestPalindrome(char* s) {
    int length = string_length(s);
    char* result = (char*)malloc(1);

    for(int len = length; len > 0;len--) {
        for(int start = 0; start <= length - len; start++) {
            if(check(s, start, start + len)) {
                free(result);

                result = (char*)malloc(sizeof(char) * (len + 1));

                for(int k = 0; k < len; k++) {
                    result[k] = s[start + k];
                }
                
                result[len] = '\0';

                return result;
            }
        }
    }
    return result;
}

int main() {
    char* s = "bababac";
    char* result = longestPalindrome(s);

    printf("Longest palindrome: %s\n", result);
    free(result);
    return 0;
}
