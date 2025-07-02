#include <stdio.h>
#include <stdlib.h>

void find_missing(int* arr, int len)
{
    int* count = (int*)calloc(sizeof(int), (len + 1));

    for( int i = 0; i < len; i++)
    {
        count[arr[i]]++;
        printf("%d : %d\n", arr[i], count[arr[i]]);
    }    

    for(int i = 0; i < len + 1; i++)
    {   
        printf("count: %d \n", count[arr[i]]);
        if(count[i] == 0)
        {
            printf("%d\n", i);
        }
    }
    free(count);

}

void main()
{
    int arr[] = {1, 2, 2, 3, 4, 5, 5, 6, 7, 9};
    int len = 10;

    find_missing(arr, len);
}