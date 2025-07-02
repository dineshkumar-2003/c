# include <stdio.h>
# include <stdlib.h>

void daily_temperature(int* temperatures, int size) {
    int* stack = (int*)malloc(sizeof(int) * size);
    int top = -1, i;
    int* ans = (int*)malloc(sizeof(int) * size);

    for (i = size-1; i >= 0; i--) {
        while (top != -1 && temperatures[stack[top]] <= temperatures[i]) {
            top--;
        }
        ans[i] = top == -1 ? 0 : stack[top] - i;
        stack[++top] = i;
    }

    for( i = 0; i < size; i++) {
        printf("%d\t",ans[i]);
    }
}

void main() {
    int temperatures[] = {73,74,75,71,69,72,76,73};
    int size = sizeof(temperatures) / sizeof(temperatures[0]);

    daily_temperature(temperatures, size);
}