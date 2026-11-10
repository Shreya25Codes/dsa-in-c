#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} n;
n *create1(int data1);
void display(n *head);
n* merge(n*head1,n* head2);

int main()
{
    n *head1 = NULL ,*head2=NULL,*head3=NULL;

    head1 = create1(10);
    head1->next = create1(20);
    head1->next->next = create1(30);

    head2 = create1(40);
    head2->next = create1(50);
    head2->next->next = create1(60);

    printf("Original list1: ");
    display(head1);
    printf("\nOriginal list2: ");
    display(head2);
    head3=merge(head1,head2);
    printf("Updated List:");
    display(head3);
    return 0;
}

n *create1(int data)
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

n* merge(n*head1,n* head2)
{
    n *ptr1=head1;
    if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }
    while(ptr1->next!=NULL)
    {
        ptr1=ptr1->next;
    }
    ptr1->next=head2;
    return head1;
}
