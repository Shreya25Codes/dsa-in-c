#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} n;
n *create(int data);
void display(n *head);
n *swap(n *head, int x, int y);
int main()
{
    int x, y, i, j;
    n *head = NULL;
    head = create(10);
    head->next = create(15);
    head->next->next = create(20);
    head->next->next->next = create(30);
    head->next->next->next->next = create(40);
    head->next->next->next->next->next = create(50);
    head->next->next->next->next->next->next = create(60);
    display(head);

    printf("Enter the two node values to swap"); // swapping
    scanf("%d%d", &x, &y);
    head = swap(head, x, y);
    display(head);


    return 0;
}
n *create(int data)
{
    n *newNode = (n *)malloc(sizeof(n));
    if(newNode == NULL)
    {
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(n *head)
{
    n *ptr = head;
    printf("\n");
    while (ptr != NULL)
    {
        printf(" %d ->", ptr->data);
        ptr = ptr->next;
    }
    printf(" NULL\n");
}

n *swap(n *head, int x, int y)
{
    n *currX = head, *prevX = NULL,*temp;
    n *currY = head, *prevY = NULL;
    if (x == y) // both index are same
    {
        return head;
    }

    // find index x
    while (currX != NULL&& currX->data != x )
    {
        prevX = currX;
        currX = currX->next;
    }

    // find node y
    while (currY != NULL&& currY->data != y)
    {
        prevY = currY;
        currY = currY->next;
    }

    // if any value not found
    if (currX == NULL || currY == NULL)
    {
        printf("Node not found");
        return head; 
    }
    //if nodes are adjacent
    if(currX->next==currY)
    {
        if(prevX!=NULL)
        {
            prevX->next=currY;
        }
        else
        {
            head=currY;
        }

        currX->next=currY->next;
        currY->next=currX;
        return head;
    }

    //if y is immediately before x
    if(currY->next==currX)
    {
        if(prevY!=NULL)
        {
            prevY->next=currX;
        }
        else
        {
            head=currX;
        }
        currY->next=currX->next;
        currX->next=currY;
        return head;
    }

    //connect node of x to y
    if(prevX!=NULL)
    {
        prevX->next=currY;
    }
    else
    {
        head=currY;
    }

    //connect node y to x
    if(prevY!=NULL)
    {
        prevY->next=currX;
    }
    else{
        head=currX;
    }

    //Actual swapping
    temp=currX->next;
    currX->next=currY->next;
    currY->next=temp;
    return head;
}
