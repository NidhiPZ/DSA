#include<stdio.h>
#include<stdlib.h>

#define N 50

int stack_arr[N];
int top = -1;

int isFull()
{
    if(top == N- 1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
     if(top == -1)
        return 1;
    else
        return 0;
}
 
 void push(int data)
 {
    if(isFull())
    {
        printf("stack overflow");
        return;
    }
    top = top + 1;
    stack_arr[top] = data;
 }
 int pop()
 {
    int value;
    if(isEmpty())
    {
        printf("stack underflow");
        exit(1);
    }
    value = stack_arr[top];
    top--;
    return value;
 }
  void print()
{
    if(isEmpty())
    {
        printf("stack underflow");
        return;
    }
    while(!isEmpty())
    {
        printf("%d ",pop());
    }
}
void dec2bin(int n)
{
    while(n!= 0)
    {
        //push the reminder on stack
        push(n%2);
        n = n/2;
    }
}

int main()
{
    int dec;
    printf("Enter the decimal number: ");
    scanf("%d", &dec);

    dec2bin(dec);
    print();

    return 0;

}