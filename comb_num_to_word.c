#include <stdio.h>
#include <stdlib.h>

void num_to_word(int* arr, int size, int* curr, int curr_len, int index)
{
    if (index >= size)
    {
        for(int i = 0; i < curr_len; i++)
        {
            printf("%c", curr[i] + 64);
        }
        printf("\n");
        return;
    }

    curr[curr_len] = arr[index];
    num_to_word(arr, size, curr, curr_len + 1, index + 1);

    if(index + 1 < size && arr[index] * 10 + arr[index + 1] <= 26)
    {
        curr[curr_len] = arr[index] * 10 + arr[index + 1];
        num_to_word(arr, size, curr, curr_len + 1, index + 2);
    }

}

int main()
{
    int num;
    
    printf("Enter the number : ");
    scanf("%d", &num);

    int* arr = (int*)malloc(sizeof(int) * num);
    int* curr = (int*)malloc(sizeof(int) * num);
    int curr_len = 0;

    printf("Enter %d numbers", num);

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }

    num_to_word(arr, num, curr, curr_len, 0);
    return 0;
}
