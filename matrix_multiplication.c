#include <stdio.h>
#define ROW 3
#define COL 3

void get_matrix_input(int mat[][COL])
{
    int row,col;

    for ( row = 0; row < ROW; row++)
    {
        for ( col = 0; col < COL; col++)
        {
            scanf("%d",(*(mat+row)+col));
        }
    }
}

void print_matrix(int mat[ROW][COL])
{
    int row,col;

    for ( row = 0; row < ROW; row++)
    {
        for ( col = 0; col < COL; col++)
        {
            printf("%d \t", *(*(mat+row)+col));
        }
        printf("\n");
    }
}

void multiply_matrix(int mat1[ROW][COL], int mat2[ROW][COL], int res[ROW][COL])
{
    int row, col, i, sum;

    for( row = 0; row < ROW; row++)
    {
        for (col = 0; col < COL; col++ )
        {
            sum=0;
            for ( i = 0; i < COL; i++)
            {
                sum += (*(*(mat1 + row) + i )) * (*(*(mat2 + i) + col ));
            }
        
            *(*(res + row) + col) = sum;
        }
    }
}

void main(){
    int mat1[ROW][COL] = {{10,20,30},{40,50,60},{70,80,90}};
    int mat2[ROW][COL] = {{10,20,30},{40,50,60},{70,80,90}};
    int result[ROW][COL];

    multiply_matrix(mat1,mat2,result);
    print_matrix(result);
}