#include <stdio.h>
#define MAX 1000

int string_length(char* string) {
    int length = 0;
    while (string[length] != '\0') {
        length++;
    }
    return length;
}

void main() {
    char string[] ="a10b2";
    int i;
    int length = string_length(string);
    char letter = '\0';
    int number;
    char result[MAX];
    int result_index = 0;

    for (i = 0; i < length; i++) {
        if (string[i] >= 'a' && string[i] <= 'z' ) {
            letter = string[i];
            number = 0;
        }
        else if (string[i] >= '0' && string[i] <= '9') {
            number = number * 10 + (string[i] - '0');  
            if (i == length - 1 || !(string[i + 1] >= '0' && string[i + 1] <= '9')) {
                for (int j = 0; j < number; j++) {
                    result[result_index++] = letter;
                }
            }
        
        }
    }
    for (i = 0; i < result_index; i++) {
        printf("%c", result[i]);
    }
}