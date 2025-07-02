#include <stdio.h>

int main()
{
    int num;

    scanf("%d", &num);


    for(int i = 1; i <= num; i++)
    {
        int binary;
        if (i % 2 == 0)
        {
            binary = 0;
        }
        else{
            binary = 1;
        }

        for (int j = 1; j <= i; j++)
        {
            printf("%d ", binary);
            binary = binary == 1 ? 0 : 1;
        }
        printf("\n");
    }
    return 0;
}
