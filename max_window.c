
#include <stdio.h>

void main()
{
    int arr[] = {1, 10, 7, 5, 6, 8, 3};
    int size = sizeof(arr) / sizeof(int);
    int k = 3;
    
    for(int i = 0; i <= size - k; i++)
    {   
        int max = arr[i];
        for(int j = i; j < i + k; j++)
        {
            if(arr[j] > max)
            max = arr[j];
        }
        printf("%d\t", max);
    }
    printf("\n");
}







// #include <stdio.h>

// #define MAX 1000

// typedef struct
// {
//     int data[MAX];
//     int front, rear;
// } Deque;

// void initDeque(Deque *dq)
// {
//     dq->front = 0;
//     dq->rear = -1;
// }

// int isEmpty(Deque *dq)
// {
//     return dq->front > dq->rear;
// }

// void pushBack(Deque *dq, int value)
// {
//     dq->rear++;
//     dq->data[dq->rear] = value;
// }

// void popFront(Deque *dq)
// {
//     dq->front++;
// }

// void popBack(Deque *dq)
// {
//     dq->rear--;
// }


// int front(Deque *dq)
// {
//     return dq->data[dq->front];
// }

// int back(Deque *dq)
// {
//     return dq->data[dq->rear];
// }

// int main()
// {
//     int n, k, arr[MAX];

//     printf("Enter the array size  : ");
//     scanf("%d", &n);

//     printf("Enter the elements    : ");
//     for (int i = 0; i < n; i++)
//         scanf("%d", &arr[i]);

//     printf("Enter the window size : ");
//     scanf("%d", &k);

//     Deque dq;
//     initDeque(&dq);

//     for (int i = 0; i < n; i++)
//     {

//         if (!isEmpty(&dq) && front(&dq) <= i - k)
//             popFront(&dq);

        
//         while (!isEmpty(&dq) && arr[back(&dq)] < arr[i])
//             popBack(&dq);

//         pushBack(&dq, i);

    
//         if (i >= k - 1)
//             printf("%d ", arr[front(&dq)]);
//     }

//     printf("\n");
//     return 0;
// }