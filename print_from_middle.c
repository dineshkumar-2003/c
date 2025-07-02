#include <stdio.h>

void main()
{
    int size;
    char string[100];
    

    printf("Enter a string of odd length : ");
    scanf("%s%n", string, &size);

    int space = 4 * size;
    char sp = ' ';

    printf("%d\n", size);

    int mid = size / 2;

    for (int i = 0; i < size; i++)
    {

        printf("%*c", space, sp);

        space -= 4;

        int m = 0;
        for(int k = 0; k <= i; k++)
        {
            if(mid + k >= size)
            {    
                printf("%c", string[m++]);
                //printf("%d", m);
            }
            printf("%c", string[mid + k]);
        }
        printf("\n");
    }

}