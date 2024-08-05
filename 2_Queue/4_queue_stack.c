#include <stdio.h>
#include <stdlib.h>
#define N 5

int s1[N];
int s2[N];
int top1 = -1;
int top2 = -1;
int count = 0;

void enqueue();
void dequeue();
int pop1();
int pop2();
void push1(int a);
void push2(int a);
int peek();
void display();

void enqueue() 
{
    int data;
    if (top1 == N - 1) 
    {
        printf("Queue overflow\n");
    } 
    else
    {
        printf("Enter the data: ");
        scanf("%d", &data);
        push1(data);   // Push data into stack1
        count++;
    }
}
void push1(int a) 
{
    if (top1 == N - 1) 
    {
        printf("Stack1 overflow\n");
    } 
    else 
    {
        top1++;
        s1[top1] = a;   // Increment top1 and push the element
    }
}
void push2(int a) 
{
    if (top2 == N - 1) 
    {
        printf("Stack2 overflow\n");
    } 
    else 
    {
        top2++;
        s2[top2] = a;   // Increment top2 and push the element
    }
}

void dequeue() 
{
    int i, a, b, x;

    if (top1 == -1)
    {
        printf("Queue underflow\n");
    } 
    else 
    {
        // Move all elements from stack1 to stack2
        for (i = 0; i < count; i++) 
        {
            a = pop1();
            push2(a);
        }
        b = pop2();    // Pop the top element from stack2, which is the front of the queue
        printf("The dequeued element is: %d\n", b);
        count--;     

        // Move remaining elements back from stack2 to stack1
        for (i = 0; i < count; i++) 
        {
            x = pop2();
            push1(x);
        }
    }
}
// Function to pop an element from stack1
int pop1() 
{
    if (top1 == -1) 
    {
        printf("Stack1 underflow\n");
        exit(1);
    }
    return s1[top1--];  // Return the top element and decrement top1
}

// Function to pop an element from stack2
int pop2() 
{
    if (top2 == -1)
    {
        printf("Stack2 underflow\n");
        exit(1);
    }
    return s2[top2--];    // Return the top element and decrement top2
}


int peek() 
{
    if (top1 == -1) 
    {
        printf("Queue is empty\n");
        exit(1);
    }
    return s1[0];   // Return the bottom element of stack1 (front of the queue)
}

void display() 
{
    int i;
    if (top1 == -1) 
    {
        printf("Queue is empty\n");
    } 
    else 
    {
        printf("Queue elements: ");
        for (i = 0; i <= top1; i++)   // Iterate and print all elements in stack1
        {
            printf("%d ", s1[i]);
        }
        printf("\n");
    }
}

int main() 
{
    int choice;

    while(1) 
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
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("Front element: %d\n", peek());
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
