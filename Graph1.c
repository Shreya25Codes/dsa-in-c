#include <stdio.h>
#include <stdlib.h>
#define maxNode 4

typedef struct node
{
    int v;
    struct node *next;
} n;

typedef struct list
{
    n *head;
} l;

l *adjlist[maxNode];

void addNode(int s, int d)
{
    n *src = NULL, *temp = NULL, *dest = NULL;
    if (adjlist[s]->head == NULL)
    {
        src = (n *)malloc(sizeof(n));
        src->v = s;
        src->next = NULL;
        adjlist[s]->head = src;
    }
    dest = (n *)malloc(sizeof(n));
    dest->v = d;
    dest->next = NULL;
    temp = adjlist[s]->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = dest;
}

void Display()
{
    int i;
    n *p = NULL;
    for (i = 0; i < maxNode; i++)
    {
        p = adjlist[i]->head;
        printf("\n List %d ->", i);
        while (p != NULL)
        {
            printf("%d ", p->v);
            p = p->next;
        }
    }
}
int main()
{
    int i;
    for (i = 0; i < maxNode; i++)
    {
        adjlist[i] = (l *)malloc(sizeof(l));
        adjlist[i]->head = NULL;
    }
    addNode(0, 1);
    addNode(0, 2);
    addNode(0, 3);
    addNode(1, 3);
    addNode(1, 2);
    addNode(2, 3);
    Display();
    return 0;
}
