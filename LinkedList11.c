
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int coeff;
    int exp;
    struct node *next;
} n;

n* create(int degree);
void display(n *head);
void add(n *p1, n *p2);

int main()
{
    n *p1, *p2;
    int degree;

    printf("Enter degree of polynomial: ");
    scanf("%d", &degree);

    printf("\nEnter first polynomial:\n");
    p1 = create(degree);

    printf("\nEnter second polynomial:\n");
    p2 = create(degree);

    printf("\nFirst Polynomial: ");
    display(p1);

    printf("\nSecond Polynomial: ");
    display(p2);

    add(p1, p2);

    printf("\n\nSum of Polynomials: ");
    display(p1);

    return 0;
}

n* create(int degree)
{
    n *head = NULL, *newnode, *temp;
    int i;

    for(i = degree; i >= 0; i--)
    {
        newnode = (n*)malloc(sizeof(n));

        if(newnode == NULL)
        {
            printf("Memory allocation failed!");
            return head;
        }

        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &newnode->coeff);

        newnode->exp = i;
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
        printf("%dx^%d", temp->coeff, temp->exp);

        if(temp->next != NULL)
        {
            printf(" + ");
        }

        temp = temp->next;
    }
}

void add(n *p1, n *p2)
{
    while(p1 != NULL && p2 != NULL)
    {
        p1->coeff = p1->coeff + p2->coeff;

        p1 = p1->next;
        p2 = p2->next;
    }
}
