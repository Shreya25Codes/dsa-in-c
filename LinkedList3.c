
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} n;

n *create(int data);
void display(n *head);
n *delBegin(n *head);
n *delEnd(n *head);
n *delBetw(n *head, int index);
n *delVal(n *head, int val);

int main()
{
    int ch;
    n *head = NULL;

    head = create(10);
    head->next = create(20);
    head->next->next = create(30);
    head->next->next->next = create(40);
    head->next->next->next->next = create(50);
    head->next->next->next->next->next = create(60);

    printf("********** MENU **********\n");

    do
    {
        printf("\n1. Delete at beginning.");
        printf("\n2. Delete at end.");
        printf("\n3. Delete between 2 nodes.");
        printf("\n4. Delete a specific value.");
        printf("\n5. Display");
        printf("\n6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            head = delBegin(head);
            break;

        case 2:
            head = delEnd(head);
            break;

        case 3:
        {
            int index;
            printf("Enter index of node to delete: ");
            scanf("%d", &index);
            head = delBetw(head, index);
            break;
        }

        case 4:
        {
            int val;
            printf("Enter value to delete: ");
            scanf("%d", &val);
            head = delVal(head, val);
            break;
        }

        case 5:
            display(head);
            break;

        case 6:
            printf("Exiting...");
            break;

        default:
            printf("Invalid choice.");
        }

    } while (ch != 6);

    return 0;
}

n *create(int data)
{
    n *newNode = (n *)malloc(sizeof(n));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void display(n *head)
{
    n *p = head;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

n *delBegin(n *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    n *p = head;
    head = head->next;

    free(p);

    return head;
}

n *delEnd(n *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    n *p = head;

    while (p->next->next != NULL)
    {
        p = p->next;
    }

    n *q = p->next;

    p->next = NULL;

    free(q);

    return head;
}

n *delBetw(n *head, int index)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    if (index <= 0)
    {
        printf("Invalid index.\n");
        return head;
    }

    if (head->next == NULL)
    {
        printf("No node available at this index.\n");
        return head;
    }

    n *p = head;
    int i = 0;

    while (i < index - 1 && p->next != NULL)
    {
        p = p->next;
        i++;
    }

    if (p->next == NULL)
    {
        printf("Invalid index.\n");
        return head;
    }

    n *q = p->next;

    p->next = q->next;

    free(q);

    return head;
}

n *delVal(n *head, int val)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    if (head->data == val)
    {
        n *p = head;
        head = head->next;

        free(p);

        return head;
    }

    n *q = head;

    while (q->next != NULL && q->next->data != val)
    {
        q = q->next;
    }

    if (q->next == NULL)
    {
        printf("Value not found.\n");
        return head;
    }

    n *p = q->next;

    q->next = p->next;

    free(p);

    return head;
} 
