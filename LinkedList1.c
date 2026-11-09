#include<stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void display(struct node *ptr);
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;

//allocate memory for node in linked list
head=(struct node *)malloc(sizeof(struct node));
second=(struct node *)malloc(sizeof(struct node));
third=(struct node *)malloc(sizeof(struct node));

//link 1st and 2nd node

head->data=7;
head->next=second;

//link 2nd and 3rd node

second->data=8;
second->next=third;

//terminate

third->data=9;
third->next=NULL;
display(head);
return 0;
}

void display(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
} 
