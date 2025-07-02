#include <stdio.h>

int length(char* str) 
{
    int len = 0;
    while(str[len] != '\0')
    {
        len++;
    }
    return len;
}

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int* arr, int size) {
    int i,j;
    for (i = 0; i < size; i++) {
        for (j = i; j < size; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void print(char* string, int start, int end)
{
    for(int i = start; i <= end; i++)
    {
        printf("%c",string[i]);
    }
    printf("\n");
}

void first_occurence(char* string, char* target, int len, int target_len)
{
    int index[target_len];
    int indeex = 0;
    for (int i = 0; i < target_len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (target[i] == string[j]) 
            {
                index[indeex++] = j;
                break;
            }
        }
    }
    sort(index, indeex);

    int min = index[0];
    int max = index[indeex - 1];
    printf("Min : %d \nMax : %d\n",min, max);

    print(string, min, max);

}

void main()
{
    char string[] = "ZOHOCORPORATION";
    char target[] = "PORT";
    int len = length(string);
    int target_len = length(target);
    first_occurence(string, target, len, target_len);
}