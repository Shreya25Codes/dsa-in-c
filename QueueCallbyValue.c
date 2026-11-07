#include<stdio.h>
#include<stdlib.h>
#define max 10
int enqueue(int[],int,int);
int dequeue(int[],int,int);
void peek(int[],int,int);
void display(int[],int,int);
int main()
{
    int ch,queue[max],front=-1,rear=-1;
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
                rear = enqueue(queue, front, rear);
                if(front == -1 && rear != -1)
                    front = 0;
                break;

            case 2:
                front = dequeue(queue, front, rear);
                if(front == -1)
                    rear = -1;
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

int enqueue(int queue[],int front,int rear)
{
    int x;
    if(rear==max-1)
    {
        printf("Queue is full.");
        return rear;
    }
    printf("Enter value:");
    scanf("%d",&x);
    rear++;
    queue[rear]=x;
    return rear;
}

int dequeue(int queue[],int front,int rear)
{
    if(front==-1)
    {
        printf("queue is empty");
        return -1;
    }
    printf("Delected element:%d",queue[front]);

    if(rear==front)
    {
        return -1;
    }
    front++;
    return front;
}

void peek(int queue[],int front,int rear)
{
    if(front==-1)
    {
        printf("Queue is empty");
        return;
    }
    printf("Front element:%d",queue[front]);
}

void display(int queue[],int front,int rear)
{
    if(front==-1)
    {
        printf("Queue is empty");
        return;
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf(" %d ",queue[i]);
        }
    }
}
