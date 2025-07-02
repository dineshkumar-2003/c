#include <stdio.h>

void print_2d_array(int arr[][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for( int  j = 0; j < cols; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void set_zeros(int arr[][3], int rows, int cols)
{
    int col0 = 1;

    for (int i = 0; i < rows; i++)
    {
        if (arr[i][0] == 0)
            {
                col0 = 0;
            }

        for (int j = 1; j < cols; j++)
        {
            if (arr[i][j] == 0)
            {
                arr[i][0] = 0;
                arr[0][j] = 0;
            }

        }
    }

        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = cols - 1; j >= 1; j--)
            {
                if(arr[i][0] == 0 || arr[0][j] == 0)
                {
                    arr[i][j] = 0;
                }
                if(col0 == 0)
                {
                    arr[i][0] = 0;
                }
            }
        }
    
        print_2d_array(arr, rows, cols);
}

int main()
{
    int arr[][3] = 
    {
        {1, 0, 3},
        {3, 0, 5},
        {7, 8, 9}
    };
    int rows = sizeof(arr) / sizeof(arr[0]);
    int cols = sizeof(arr[0]) / sizeof(int);

    print_2d_array(arr, rows, cols);
    set_zeros(arr, rows, cols);

    return 0;
}
