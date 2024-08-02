#include<stdio.h>
#include<stdlib.h>
#define N 5

int que[N];
int front =  -1;
int rear = -1; 

void enqueue(int num);
void dequeue();
int peek();
void print();

int peek()
{
    if(front == -1 && rear == -1)
    {
       printf("underflow");
       exit (1);
    }
    return que[front];
}
void enqueue(int num)
{
    if (rear == N-1)
    {
        printf("overflow");
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        que[rear] = num;
    }
    else
    {
        rear++;
        que[rear] = num;
    }
}
void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("underflow");
    }
    else if(front == rear)
    {
        front=rear=-1;
    }
    else
    {
       printf("%d ", que[front]);
        front++;
    }
   
}
void print()
{
    if(front == -1 && rear == -1)
    {
       printf("underflow");
    }
    else
    {
        for(int i = front; i<rear + 1; i++)
        {
            printf("%d ",que[i]);
        }
    }
}

int main() 
{ 
    int choice, num;
    
    while (1) 
    {
        printf("\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) 
        {
            case 1:
                printf("Enter the val to enqueue: ");
                scanf("%d", &num);
                enqueue(num);
                break;
            case 2:
                dequeue();
                printf("Dequeued num from the array\n");
                break;
            case 3:
                printf("Front number: %d \n", peek());
                break;
            case 4:
                print();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}