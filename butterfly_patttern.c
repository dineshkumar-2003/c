#include <stdio.h>

void print_butterfly(int n) {
    int spaces = 2 * n - 1;
    int stars = 0;

    for(int i = 1; i <= 2 * n - 1; i++) {
        if(i <= n) {
            spaces -= 2;
            stars++;
        }
        else {
            spaces += 2;
            stars--;
        }

        for(int j = 0; j < stars; j++) {
            printf("*");
        }

        for(int j = 0; j < spaces; j++) {
            printf(" ");
        }

        for(int j = 0; j < stars; j++) {
            if(j != n - 1)
            printf("*");
        }
        printf("\n");
    }
}

void main() {
    int n = 5;

    print_butterfly(n);
}