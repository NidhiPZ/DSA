#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL; 

int isEmpty();
void enqueue(int num);
void dequeue();
void print();
int peek();

int isEmpty()
 {
   return front == NULL;
}
void enqueue(int num) 
{
    struct node *newN;
    newN= malloc(sizeof(struct node));
    if (newN == NULL) 
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newN->data = num;
    newN->next = NULL;

    if (isEmpty()) 
    {
        front = rear = newN;
    } 
    else 
    {
        rear->next = newN;
        rear = newN;
    }
}

void print()
{
    if(isEmpty())
    {
        printf("Queue underflow");
        return;
    }
    else
    {
        struct node *temp;
        temp=front;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp= temp->next;
        }
    }
}
void dequeue() 
{
    if (isEmpty())
     {
        printf("Queue is empty\n");
        return;
    }

    struct node *temp = front;
    printf("%d ",front->data);
    front = front->next;
    free(temp);

}
int peek()
{
    if(isEmpty())
    {
        printf("Queue underflow");
    } 
    return front->data; 
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
                printf("dequeued num from the array\n");
                break;
            case 3:
                printf("Front number: %d \n", peek());
                break;
            case 4:
                printf("Queue Contains: ");
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