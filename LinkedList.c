#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void print(struct Node *head)
{
    struct Node* temp = head;

    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

void add_node(struct Node* head)
{
    int data;
    struct Node* new_node = malloc(sizeof(struct Node)); 
    struct Node* temp = head;

    printf("Enter the new node's value: \n");
    scanf("%d",&data);
    new_node->data=data;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
    printf("New Node added successfully\n");

}

void delete_node(struct Node* head,int data)
{
    struct Node* temp = head;

    if(head -> data == data)
    {
        head = head -> next;
    }
    else
    {
        while(temp->next != NULL)
        {
            if (temp->next->data == data)
            {
                temp->next = temp->next->next;
            }
        }
    }
    print(head);
    printf("Node with %d deleted successfully \n",data);
}

int main()
{
    struct Node *head;
    struct Node *one = NULL;
    struct Node *two = NULL;
    struct Node *three = NULL;
    int delete_value;

    one = malloc(sizeof(struct Node));
    two = malloc(sizeof(struct Node));
    three = malloc(sizeof(struct Node));

    one->data = 1;
    two->data = 2;
    three->data = 3;

    one ->next = two;
    two ->next =three;
    three ->next =NULL;
    head=one;
    
    print(head);
    add_node(head);
    print(head);
    printf("Enter the value to delete : ");
    scanf("%d",&delete_value);
    delete_node(head,delete_value);

    return 0;
}