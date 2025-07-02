#include <stdio.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

bool is_safe(int arr[ROW][COL], bool visited[ROW][COL], int i, int j) {
    return i >= 0 && i < ROW && j >= 0 && j < COL && arr[i][j] == 1 && !visited[i][j];
}

bool can_reach(int arr[ROW][COL], bool visited[ROW][COL], int i, int j) 
{   
    if ((ROW - 1) == i && (COL - 1) == j)
    {
        arr[i][j] = -1;
        return true;
    }

    if(!is_safe(arr, visited, i, j))
    {
        return false;
    }

    visited[i][j] = true;


    if (can_reach(arr, visited, i, j + 1)) {
        arr[i][j] = -1;
        return true;
    }


    if (can_reach(arr, visited, i + 1, j)) {
        arr[i][j] = -1;
        return true;
    }

    return false;
}

void main()
{
    int arr[][5] = {
    {1, 0, 1, 0, 0},
	{1, 1, 1, 1, 1},
	{0, 0, 0, 1, 0},
	{1, 0, 1, 1, 1},
	{0, 1, 1, 0, 1}
    };
    bool visited[ROW][COL] = {false};


    bool result = can_reach(arr, visited, 0, 0);

    if(result == 1)
    {
        printf("True\n");
    }
    else{
        printf("False\n");
    }

    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}