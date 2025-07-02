#include <stdio.h>

void recurse(int arr[][3], int sr, int sc, int val, int num)
{
    if (arr[sr][sc] != val || sr > 2 || sc > 2)
    {
        return;
    }
    arr[sr][sc] = num;
    recurse(arr, sr + 1, sc, val, num);
    recurse(arr, sr, sc + 1, val, num);
    recurse(arr, sr, sc - 1, val, num);
    recurse(arr, sr - 1, sc, val, num);
}

void main()
{
    int arr[][3] = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 0}
    };

    int num = 2;

     int sr = 1, sc = 1;

     recurse(arr, sr, sc, arr[sr][sc], num);

     for(int i = 0 ; i < 3; i++)
     {
        for(int j = 0; j < 3; j++)
        {
            printf("%d", arr[i][j]);
        }
        printf("\n");
     }
}