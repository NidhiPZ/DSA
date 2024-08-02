#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
} *top = NULL;

void push(int data)
{
    struct node *newN;
    newN =malloc(sizeof(newN));
    if (newN == NULL)
    {
        printf("stack overflow");
        exit(1);
    }
    newN->data = data;
    newN->link = NULL;

    newN->link = top;
    top = newN;
}
int isEmpty()
{
     if(top == NULL)
        return 1;
    else
        return 0;
}
void *pop()
{
    struct node *temp;
    int val;
    if(isEmpty())
    {
        printf("stack underflow"); 
        exit(1);
    }
    temp = top;
    val = temp->data;

    top = top ->link;
    free(temp);
    temp = NULL;
    return val;
}
int peek()
{
    if(isEmpty())
    {
        printf("stack underflow");
        exit(1);
    }
    return top->data;
}
void print()
{
    struct node *temp;
    temp = top;
    if (isEmpty())
    {
        printf("stack underflow");
        exit(1);
    }
    printf("The stack elements are: ");
    while(temp)
    {
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}
int main()
{
    int choice, data;
    while(1)
    {
       printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the top element\n");
        printf("4. Print the all element of the stack\n");
        printf("5. Quit\n");

        printf("Please enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter the element to be pushed:");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                data = pop();
                printf("Deleted element is %d\n",data);
                break;
            case 3:
                printf("The top most element of the stack is %d\n",peek());
                break;
            case 4:
                print();
                break;
            case 5:
                exit(1);
            default:
                printf("wrong choice");

        }
    }
    return 0;
}