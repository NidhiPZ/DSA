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
    if(front == -1 && rear == -1)
    {
        front = rear = 0;
        que[rear] = num;
    }
    else if(((rear+1)%N) == front)    // Check if the queue is full
    {
        printf("Queue is full");
    }
    else
    {
        rear= (rear+1)%N;   // Circular increment of rear
        que[rear] = num;
    }
}
void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else if(front == rear)    // Check if there is only one element
    {
        front=rear=-1;
    }
    else
    {
       printf("%d ", que[front]);
        front= (front+1)%N;     // Circular increment of front
    }
   
}
void print()
{
    int i =front;
    if(front == -1 && rear == -1)
    {
       printf("Queue is empty");
    }
    else
    {
        while (i != rear)   // Loop to print elements from front to rear
        {
            printf("%d ",que[i]);
            i = (i+1)%N;
        }
         printf("%d ",que[rear]);
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