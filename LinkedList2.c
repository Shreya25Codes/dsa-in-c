#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void disp(struct node *ptr);
struct node *insBegin(struct node *head, int data);
struct node *insBetw(struct node *head, int data);
struct node *insEnd(struct node *head, int data);
struct node *insAfter(struct node *head, struct node *prevNode, int data);
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    int ch, data, index;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    disp(head);
    do
    {
    printf("\nEnter Choice:\n");
    printf("1.Insertion at beginning.\n2.Insertion between 2 nodes.\n3.Insertion at end.\n4.Insertion after a node.\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("\nInsertion at beginning.\n");
        head = insBegin(head, data);
        break;
    case 2:
        printf("\nInsertion between 2 nodes.\n");
        head = insBetw(head, data);
        break;
    case 3:
        printf("\nInsertion at end.\n");
        head = insEnd(head, data);
        break;
    case 4:
        printf("\nInsertion after a node.\n");
        head = insAfter(head, second, 2007);
        break;
    case 0:
        printf("\nExiting...");
        break;

    default:
        printf("\nInvalid choice.\n");
        break;
    }
    } while (ch!=0);
    printf("\nUpdated list: ");
    disp(head);
    return 0;
}

struct node *insBegin(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &data);
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct node *insBetw(struct node *head, int data)
{
    int index, i = 0;
    struct node *p = head;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    printf("Enter index before insertion:");
    scanf("%d", &index);
    printf("Enter data:");
    scanf("%d", &data);

    newNode->data = data;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    newNode->next = p->next;
    p->next = newNode;
    return head;
}

struct node *insEnd(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    printf("\nEnter data:");
    scanf("%d", &data);
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct node *insAfter(struct node *head, struct node *prevNode, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

void disp(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
