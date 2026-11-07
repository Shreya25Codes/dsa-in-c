#include <stdio.h>
#define max 10

void push(int stack[], int *top);
void pop(int stack[], int *top);
void peek(int stack[], int top);
void display(int stack[], int top);

int main()
{
    int ch, stack[max], top = -1;

    do
    {
        printf("\n\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                push(stack, &top);
                break;

            case 2:
                pop(stack, &top);
                break;

            case 3:
                peek(stack, top);
                break;

            case 4:
                display(stack, top);
                break;

            case 5:
                printf("Exiting program.");
                break;

            default:
                printf("Invalid choice.");
        }

    } while(ch != 5);

    return 0;
}

void push(int stack[], int *top)
{
    int x;

    if(*top == max - 1)
    {
        printf("Stack is full.");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &x);

    (*top)++;
    stack[*top] = x;

    printf("Element pushed.");
}

void pop(int stack[], int *top)
{
    if(*top == -1)
    {
        printf("Stack is empty.");
        return;
    }

    printf("Deleted element: %d", stack[*top]);
    (*top)--;
}

void peek(int stack[], int top)
{
    if(top == -1)
    {
        printf("Stack is empty.");
        return;
    }

    printf("Top element: %d", stack[top]);
}

void display(int stack[], int top)
{
    int i;

    if(top == -1)
    {
        printf("Stack is empty.");
        return;
    }

    for(i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
}
