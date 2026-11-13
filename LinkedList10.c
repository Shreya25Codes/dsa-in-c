#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} n;

n* create();
void display(n *head);
int findPair(n *head, int target);

int main()
{
    n *head = NULL;
    int target;

    head = create();

    printf("\nLinked List: ");
    display(head);

    printf("\nEnter target value: ");
    scanf("%d", &target);

    if(findPair(head, target))
    {
        printf("\nYes, such two nodes exist.");
    }
    else
    {
        printf("\nNo, such two nodes do not exist.");
    }

    return 0;
}

n* create()
{
    n *head = NULL, *newnode, *temp;
    int num, i;

    printf("Enter number of nodes: ");
    scanf("%d", &num);

    for(i = 0; i < num; i++)
    {
        newnode = (n*)malloc(sizeof(n));

        if(newnode == NULL)
        {
            printf("Memory allocation failed!");
            return head;
        }

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newnode;
        }
    }

    return head;
}

void display(n *head)
{
    n *temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");
}

int findPair(n *head, int target)
{
    n *temp, *curr;

    curr = head;

    while(curr != NULL)
    {
        temp = curr->next;

        while(temp != NULL)
        {
            if(curr->data * temp->data < target)
            {
                return 1;
            }

            temp = temp->next;
        }

        curr = curr->next;
    }
    return 0;
}
