#include <stdio.h>
#include <string.h>

char *below_20[] = {
    "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
    "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
    "Sixteen", "Seventeen", "Eighteen", "Nineteen"
};

char *tens[] = {
    "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
};

char *thousands[] = {
    "", "Thousand", "Million", "Billion"
};

void helper(int num, char *result) {
    if (num == 0) return;

    if (num < 20) {
        strcat(result, below_20[num]);
        strcat(result, " ");
    } else if (num < 100) {
        strcat(result, tens[num / 10]);
        strcat(result, " ");
        helper(num % 10, result);
    } else {
        strcat(result, below_20[num / 100]);
        strcat(result, " Hundred ");
        helper(num % 100, result);
    }
}

void numberToWords(int num, char *result) {
    if (num == 0) {
        strcpy(result, "Zero");
        return;
    }

    result[0] = '\0'; // Clear the result string
    int parts[4] = {0};  // Up to billions (max 10^9)
    int i = 0;

    while (num > 0) {
        parts[i++] = num % 1000;
        num /= 1000;
    }

    for (int j = i - 1; j >= 0; j--) {
        if (parts[j] != 0) {
            char temp[256] = "";
            helper(parts[j], temp);
            strcat(result, temp);
            strcat(result, thousands[j]);
            strcat(result, " ");
        }
    }

    // Remove trailing space
    int len = strlen(result);
    if (len > 0 && result[len - 1] == ' ')
        result[len - 1] = '\0';
}

int main() {
    int num;
    char result[1024];

    printf("Enter a number: ");
    scanf("%d", &num);

    numberToWords(num, result);

    printf("Output: \"%s\"\n", result);

    return 0;
}
