#include <stdio.h>

int main()
{
    int arr[] = {1,1,2,2,4,5,5};
    int size = sizeof(arr) / sizeof(int);

    for(int i = 0; i < size; i++)
    {
        int flag = 0;
        for (int j = 0; j < size; j++)
        {
            if ((arr[i] ^ arr[j]) == 0 && i != j)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("%d\n", arr[i]);
        }
    }
    return 0;
}
