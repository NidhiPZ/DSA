//Double ended queue
#include <stdio.h>
#include <stdlib.h>
#define N 5  // Define the size of the deque

// Define the deque array and front and rear pointers
int deque[N];
int front = -1;
int rear = -1;


void insertFront(int num);
void insertRear(int num);
void deleteFront();
void deleteRear();
int getFront();
int getRear();
void display();

void insertFront(int num) 
{
    // Check if the deque is full
    if ((front == 0 && rear == N-1) || (front == rear + 1))
    {
        printf("Deque overflow\n");
    } 
    else 
    {
        // Check if the deque is initially empty
        if (front == -1) 
        {
            front = rear = 0;
        } 
        else if (front == 0) 
        {
            // Circular increment
            front = N - 1;
        } 
        else 
        {
            front--;
        }
        // Insert the element at the front
        deque[front] = num;
    }
}


void insertRear(int num) 
{
    // Check if the deque is full
    if ((front == 0 && rear == N-1) || (front == rear + 1)) 
    {
        printf("Deque overflow\n");
    } 
    else 
    {
        // Check if the deque is initially empty
        if (rear == -1) 
        {
            front = rear = 0;
        } 
        else if (rear == N - 1) 
        {
            // Circular increment
            rear = 0;
        } 
        else 
        {
            rear++;
        }
        // Insert the element at the rear
        deque[rear] = num;
    }
}


void deleteFront() 
{
    // Check if the deque is empty
    if (front == -1) 
    {
        printf("Deque underflow\n");
    } 
    else 
    {
        // Print the deleted element
        printf("Deleted element: %d\n", deque[front]);
        // Check if the deque has only one element
        if (front == rear) 
        {
            front = rear = -1;
        } 
        else 
        {
            if (front == N - 1) 
            {
                // Circular increment
                front = 0;
            } 
            else 
            {
                front++;
            }
        }
    }
}


void deleteRear() 
{
    // Check if the deque is empty
    if (rear == -1) 
    {
        printf("Deque underflow\n");
    } 
    else 
    {
        // Print the deleted element
        printf("Deleted element: %d\n", deque[rear]);
        // Check if the deque has only one element
        if (front == rear) 
        {
            front = rear = -1;
        } 
        else 
        {
            if (rear == 0) 
            {
                // Circular decrement
                rear = N - 1;
            } 
            else 
            {
                rear--;
            }
        }
    }
}

// Function to get the front element of the deque
int getFront() {
    // Check if the deque is empty
    if (front == -1) {
        printf("Deque is empty\n");
        exit(1);
    }
    // Return the front element
    return deque[front];
}

// Function to get the rear element of the deque
int getRear() 
{
    // Check if the deque is empty
    if (rear == -1) 
    {
        printf("Deque is empty\n");
        exit(1);
    }
    // Return the rear element
    return deque[rear];
}

// Function to display the elements of the deque
void display() 
{
    int i;
    // Check if the deque is empty
    if (front == -1) 
    {
        printf("Deque is empty\n");
    } 
    else 
    {
        printf("Deque elements: ");
        i = front;
        // Print elements from front to rear
        while (i != rear) 
        {
            printf("%d ", deque[i]);
            i = (i + 1) % N;
        }
        printf("%d\n", deque[rear]);
    }
}

// Main function to drive the program
int main() 
{
    int choice, num;

    while (1) 
    {
        printf("\n");
        printf("1. Insert at front\n");
        printf("2. Insert at rear\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Get front element\n");
        printf("6. Get rear element\n");
        printf("7. Display deque\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter the value to insert at front: ");
                scanf("%d", &num);
                insertFront(num);
                break;
            case 2:
                printf("Enter the value to insert at rear: ");
                scanf("%d", &num);
                insertRear(num);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                printf("Front element: %d\n", getFront());
                break;
            case 6:
                printf("Rear element: %d\n", getRear());
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
