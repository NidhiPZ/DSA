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

 void prime_fact(int num)
 {
    int i = 2;
    while(num != 1)
    {
        //push all facotor to the stack
        while(num%i == 0)
        {
            push(i);
            num = num/i;
        }
        i++;
    }
    printf("prime factor of the number in descending order are as follows: ");
    while(top != -1)
    {
        printf("%d ",pop());
    }
 }
 int main()
 {
    int number;
    printf("Please enter a positive number: ");
    scanf("%d",&number);
    prime_fact(number);
    return 0;
 }