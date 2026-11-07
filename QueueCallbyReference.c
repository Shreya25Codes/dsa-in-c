
#include <stdio.h>
#define max 10

void enqueue(int queue[], int *front, int *rear);
void dequeue(int queue[], int *front, int *rear);
void peek(int queue[], int front, int rear);
void display(int queue[], int front, int rear);

int main()
{
    int ch, queue[max];
    int front = -1, rear = -1;

    do
    {
        printf("\n\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                enqueue(queue, &front, &rear);
                break;

            case 2:
                dequeue(queue, &front, &rear);
                break;

            case 3:
                peek(queue, front, rear);
                break;

            case 4:
                display(queue, front, rear);
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

void enqueue(int queue[], int *front, int *rear)
{
    int x;

    if(*rear == max - 1)
    {
        printf("Queue is full.");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &x);

    if(*front == -1)
        *front = 0;

    (*rear)++;
    queue[*rear] = x;

    printf("Element inserted.");
}

void dequeue(int queue[], int *front, int *rear)
{
    if(*front == -1)
    {
        printf("Queue is empty.");
        return;
    }

    printf("Deleted element: %d", queue[*front]);

    if(*front == *rear)
    {
        *front = -1;
        *rear = -1;
    }
    else
    {
        (*front)++;
    }
}

void peek(int queue[], int front, int rear)
{
    if(front == -1)
    {
        printf("Queue is empty.");
        return;
    }

    printf("Front element: %d", queue[front]);
}

void display(int queue[], int front, int rear)
{
    int i;

    if(front == -1)
    {
        printf("Queue is empty.");
        return;
    }

    for(i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
}
