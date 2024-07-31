#include<stdio.h>
#include<stdlib.h>
#define MAX 5
void push(int data);
int pop();
void print();


int stack_arr[MAX];
int top = -1;
int pop()
{
    int value;
    if(top == -1)
    {
        printf("stack underflow");
        exit(1);
    }
    value = stack_arr[top];
    top = top - 1;
    return value;
}

int main()
{
    int data;
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    data = pop();
    data = pop();
    print();
}
void push(int data)
{
    if(top == MAX -1)
    {
        printf("stack overflow");
        return;
    }
    top = top + 1;
    stack_arr[top]= data;
}
void print()
{
    if(top == -1)
    {
        printf("stack underflow");
        return;
    }
    for(int i = top; i>=0; i--)
    {
        printf("%d ",stack_arr[i]);
    }
}