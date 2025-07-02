#include <stdio.h>
#include <stdlib.h>

int string_length(char* s) {
    int length = 0;
    while(s[length] != '\0') {
        length++;
    }
    return length;
}

int min_insertions(char* s) {
    int length = string_length(s);
    char* stack = (char*)malloc(sizeof(char) * length);
    int top = -1;
    int required = 0;
    int balance_count = 0;

    for(int i = 0; i < length; i++) {
        if (s[i] == '(') {
            stack[++top] = s[i];
        }
        else {
            if(top == -1) {
                if (i != length - 1 &&  s[i + 1] == ')') {
                    required++;
                    i++;
                }
                else {
                    required += 2;
                }
            }
            else {
                if (i != length - 1 && s[i + 1] == ')') {
                    i++;
                    top--;
                }
                else {
                    required += 1;
                    top--;
                }
            }
        }
    }
    printf("%d", top);
    return required + (top == -1 ? 0 : (top + 1) * 2);
}

void main() {
    char string[] = "(()))";
    printf("%d\n", min_insertions(string));
}