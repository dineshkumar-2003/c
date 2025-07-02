# include <stdio.h>
# include <string.h>
# include <stdlib.h>

void main() {
    char string[] = "((())())(()((";
    int size = strlen(string);
    int* stack = (int*)malloc(sizeof(int) * size);
    int top = -1;
    int i;

    for(i = 0; i < size; i++) {
        if (string[i] == '(') {
            stack[++top] = i;
        }
        else if (string[i] == ')') {
            if (top != -1) {
                top--;
            }
            else {
                string[i] = '#';
            }
        }
    }

    while (top != -1) {
        string[stack[top--]] = '#'; 
    }

    int result_size = 0;

    for (i = 0; i < size; i++) {
        if (string[i] != '#') {
            result_size++;
        }
    }

    char* result = (char*)malloc(sizeof(char) * (result_size + 1));
    int k = 0;

    for (i = 0; i < size; i++) {
        if (string[i] != '#') {
            result[k++] = string[i];
        }
    }
    result[k] = '\0';

    printf("Valid string  %s", result);
}