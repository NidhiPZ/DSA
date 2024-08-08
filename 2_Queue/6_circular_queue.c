//circular Queue using linked-list
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a queue Node
typedef struct Node
{
    int data;         
    struct Node *next; 
} Node_t;

// Define the front and rear pointers for the queue
Node_t *front = NULL;
Node_t *rear = NULL;

// Function prototypes
void enqueue(int num);
void dequeue();
int peek();
void print();

int peek()
{
    if (front == NULL) 
    { 
        printf("Underflow\n");
        exit(1);
    }
    return front->data; // Return the front element
}

void enqueue(int num) 
{
    Node_t *new = (Node_t*)malloc(sizeof(Node_t));
    new->data = num; 
    new->next = NULL; 

    if (rear == NULL) 
    { 
        front = rear = new; // Set both front and rear to the new Node
        rear->next = front; // Make it circular by pointing to front
    } 
    else 
    {
        rear->next = new; //Link the new Node to the end of the queue
        rear = new;  
        rear->next = front; //Make it circular by pointing to front
    }
    printf("Enqueued %d\n", num);
}

void dequeue() {
    if (front == NULL) 
    { 
        printf("Queue is empty\n");
        return;
    }

    if (front == rear)  // If there is only one Node in the queue
    { 
        printf("Dequeued %d\n", front->data); 
        free(front); 
        front = rear = NULL; // Set front and rear to NULL
    }
     else 
     {
        Node_t *temp = front; 
        front = front->next; 
        rear->next = front; // Maintain the circular link
        printf("Dequeued %d\n", temp->data); 
        free(temp); 
    }
}

void print()
{
    if (front == NULL) 
    { 
        printf("Queue is empty\n");
        return;
    }

    Node_t *temp = front; 
    //traverse the list
    do 
    {
        printf("%d ", temp->data); 
        temp = temp->next;   
    } while (temp != front); // Continue until we reach the front again
    printf("\n");
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

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &num);
                enqueue(num);
                break;
            case 2:
                dequeue();
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

}
