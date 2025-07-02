#include <stdio.h>

int helper(int grid[][3], int m, int n)
{
    int dp[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0; 
        }
    }

    if (grid[0][0] == 1)
        return 0;  
    dp[0][0] = 1;

    for (int j = 1; j < n; j++) {
        if (grid[0][j] == 1) {
            dp[0][j] = 0;  
        } else {
            dp[0][j] = dp[0][j - 1];
        }
    }

    for (int i = 1; i < m; i++) {
        if (grid[i][0] == 1) {
            dp[i][0] = 0;  
        } else {
            dp[i][0] = dp[i - 1][0];
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] == 1) {
                dp[i][j] = 0;  
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[m - 1][n - 1];
}


int uniquePathsWithObstacles(int obstacleGrid[][3], int obstacleGridSize, int* obstacleGridColSize) {
    int m = obstacleGridSize;
    int n = obstacleGridColSize[0];
    
    return helper(obstacleGrid, m, n);
}

int main()
{
    int grid[][3] = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    int col[] = {3, 3, 3};

    printf("%d", uniquePathsWithObstacles(grid, 3, col));
    return 0;
}
