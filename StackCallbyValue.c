#include <stdio.h>
#include <stdlib.h>
#define max 10
int push(int[], int);
int pop(int[], int);
void peek(int[], int);
void display(int[], int);
int main()
{
    int ch, stack[max], top = -1;

    printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5.Exit Code");
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            top = push(stack, top);
            break;

        case 2:
            top = pop(stack, top);
            break;

        case 3:
            peek(stack, top);
            break;

        case 4:
            display(stack, top);
            break;
        case 5:
            printf("Exit code");
            break;
        default:
            printf("Invalid choice");
        }
    } while (ch != 5);
    return 0;
}

int push(int stack[],int top)
{
    int x;
    if(top==max-1)
    {
        printf("Stack is full");   
        return top; 
    }
    printf("Enter x:");
    scanf("%d",&x);
    top++;
    stack[top]=x;
    return top;
}

int pop(int stack[],int top)
{
    int x;
    if(top==-1)
    {
        printf("stack is empty");
        return top;
    }
    x=stack[top];
    printf("Deleted Element:%d",x);
    top--;
    return top;
}

void peek(int stack[],int top)
{
    if(top==-1)
    {
        printf("Stack is empty");
        return;
    }
    printf("Top Element:%d",stack[top]);
}

void display(int stack[],int top)
{
    if(top==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
    }
}
