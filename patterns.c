#include <stdio.h>

void print_inverted_right(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void print_right_triangle(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void print_pyramid(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }

        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void print_reverse_pyramid(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf(" ");
        }

        for (int j = i; j <= 2 * n - i; j++) {
            printf("*");
        }

        printf("\n");
    }
}

void main() {
    int n;
    printf("Enter the n :");
    scanf("%d", &n);
    print_reverse_pyramid(n);
}