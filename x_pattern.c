#include <stdio.h>

void generate_pattern(char* string, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ( i == j || i + j == size - 1) {
                printf("%c", string[i]);
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int string_length(char* string) {
    int length = 0;
    while (string[length] != '\0') {
        length++;
    }
    return length;
}

void main() {
    char string[] = "geeksforgeeks";
    int size = string_length(string);
    generate_pattern(string, size);
}