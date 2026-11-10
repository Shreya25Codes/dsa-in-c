#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} n;

n *create(int data);
void display(n *head);
n *alternate(n *head);

int main()
{
    n *head = NULL;

    head = create(10);
    head->next = create(20);
    head->next->next = create(30);
    head->next->next->next = create(40);
    head->next->next->next->next = create(50);

    printf("Original list: ");
    display(head);
    printf("Updated List:");
    alternate(head);
    display(head);
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

n *alternate(n *head)
{
    n* ptr=head,*temp;
    if(head==NULL||head->next==NULL)
    {
        printf("not enough nodes");
        return head;
    }
    while(ptr!=NULL && ptr->next!=NULL)
    {
        temp=ptr->next;
        ptr->next=temp->next;
        free(temp);
        ptr=ptr->next;
    }
    return head;
}
