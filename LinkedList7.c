#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} n;

n *create(int data);
void display(n *head);
void split(n *head);

int main()
{
    n *head = NULL;
    head = create(1);
    head->next = create(2);
    head->next->next = create(3);
    head->next->next->next = create(4);
    head->next->next->next->next = create(5);

    printf("Original list: ");
    display(head);
    split(head);
    return 0;
}

n *create(int data)
{
    n *newNode = (n *)malloc(sizeof(n));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void display(n *head)
{
    n *ptr = head;

    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL\n");
}

void split(n *head)
{
    n *ptr=head;
    printf("\nEven Nodes:");
    while(ptr!=NULL)
    {
        if(ptr->data%2==0)
        {
            printf("%d ->",ptr->data);
        }
        ptr=ptr->next;
    }
    printf("NULL\n");

    ptr=head;
    printf("\nOdd Nodes:");
    while(ptr!=NULL)
    {
        if(ptr->data%2!=0)
        {
            printf("%d ->",ptr->data);
        }
        ptr=ptr->next;
    }
    printf("NULL\n");
}
