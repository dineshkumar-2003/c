#include <stdio.h>

void main()
{
    int num;
    int pascal[10][10];
    int space = num;

    printf("Enter the number");
    scanf("%d",&num);

    for(int i = 0; i < num; i++)
    {
        printf("%*c", num - i, ' ');
    for(int j = 0; j <= i; j++)
    {
        if(j == 0 || j == i)
        {
            pascal[i][j] = 1;
        }
        else
        {
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }

        printf("%4d", pascal[i][j]);
    } 
        printf("\n");
    }
}