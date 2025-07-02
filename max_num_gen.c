#include <stdio.h>
#include <string.h>

int max_val = 0;
int dig = 5;

int count_digits(int num) {
    int count = 0;
    if (num == 0) return 1;
    while (num > 0) {
        count++;
        num /= 10;
    }
    return count;
}

int pow10a(int exp) {
    int res = 1;
    while (exp--) res *= 10;
    return res;
}

void backtrack(int* arr, int size, int* used, int current, int digits_used) {
    if (digits_used > dig) return;

    if (current > max_val)
        max_val = current;

    for (int i = 0; i < size; i++) {
        if (used[i]) continue;

        int d = count_digits(arr[i]);
        if (digits_used + d <= dig) {
            used[i] = 1;
            int new_current = current * pow10a(d) + arr[i];
            backtrack(arr, size, used, new_current, digits_used + d);
            used[i] = 0;
        }
    }
}

int main() {
    int arr[] = {78, 9, 923, 7};
    int size = sizeof(arr) / sizeof(int);
    int used[10] = {0};

    backtrack(arr, size, used, 0, 0);

    printf("%d\n", max_val);
    return 0;
}
