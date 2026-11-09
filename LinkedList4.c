#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} n;

n *create(int data);
void display(n *head);
void split(n *head, n **head1, n **head2);

int main()
{
    n *head = NULL;
    n *head1 = NULL;
    n *head2 = NULL;

    head = create(10);
    head->next = create(20);
    head->next->next = create(30);
    head->next->next->next = create(40);
    head->next->next->next->next = create(50);

    printf("Original list: ");
    display(head);

    split(head, &head1, &head2);

    printf("Linked List after splitting:");
    printf("\nFirst list: ");
    display(head1);
    printf("\nSecond list: ");
    display(head2);

    return 0;
}

n *create(int data)
{
    n *newNode = (n *)malloc(sizeof(n));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void split(n *head, n **head1, n **head2)
{
    n *fast = head, *slow = head;
    if (head == NULL)
    {
        *head1 = NULL;
        *head2 = NULL;
        printf("Empty List");
        return;
    }
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    *head1 = head;
    *head2 = slow->next;
    slow->next = NULL;
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
