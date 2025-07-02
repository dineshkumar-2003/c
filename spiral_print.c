#include <stdio.h>

void printSpiral(int n) {
    int arr[n][n];
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int num = 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            arr[top][i] = num++;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            arr[i][right] = num++;
        }
        right--;

        for (int i = right; i >= left; i--) {
            arr[bottom][i] = num++;
        }
        bottom--;

        for (int i = bottom; i >= top; i--) {
            arr[i][left] = num++;
        }
        left++;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter size of square matrix (n x n): ");
    scanf("%d", &n);

    printSpiral(n);
    return 0;
}




// #include <stdio.h>
// #include <math.h>

// // Function to compute value at position (i, j) in spiral
// int getValueAt(int n, int i, int j) {
//     int layer = (i < j) ? ((i < n - j - 1) ? i : n - j - 1)
//                         : ((j < n - i - 1) ? j : n - i - 1);

//     int maxVal = n * n;
//     int start = 1;

//     for (int l = 0; l < layer; l++) {
//         start += (n - l * 2) * 4 - 4;
//     }

//     int offset = 0;
//     int len = n - layer * 2;

//     if (i == layer)
//         offset = j - layer;
//     else if (j == n - layer - 1)
//         offset = (len - 1) + (i - layer);
//     else if (i == n - layer - 1)
//         offset = (len - 1) * 2 + (n - layer - 1 - j);
//     else
//         offset = (len - 1) * 3 + (n - layer - 1 - i);

//     return start + offset;
// }

// int main() {
//     int n;
//     printf("Enter size of square matrix (n x n): ");
//     scanf("%d", &n);

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             printf("%3d ", getValueAt(n, i, j));
//         }
//         printf("\n");
//     }

//     return 0;
// }
