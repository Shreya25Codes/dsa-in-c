#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} n;

n *create(int data);
void display(n *head);
int countPrime(n *head);

int main()
{
    n *head = NULL;
    head = create(1);
    head->next = create(20);
    head->next->next = create(7);
    head->next->next->next = create(17);
    head->next->next->next->next = create(50);

    printf("Original list: ");
    display(head);
    printf("No. of Prime no.:%d",countPrime(head));
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

int countPrime(n *head)
{
    n *ptr=head;
    int i,count=0,flag;
    while(ptr!=NULL)
    {
        if(ptr->data<2)
        {
        ptr=ptr->next;
        continue;
        }
    flag=0;
    for(i=2;i<ptr->data;i++)
    {
        if(ptr->data%i==0)
        {
        flag=1;
        break;
        }
    }
    if(flag==0)
    {
        count++;
    }
    ptr=ptr->next;
    }
    return count;
} 
