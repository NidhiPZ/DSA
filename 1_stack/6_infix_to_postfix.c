#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100 

void push(char c);
char pop();
char peek();
int precedence(char op);
int isOperator(char c);
void infixToPostfix(char* infix, char* postfix);

char stack[MAX];
int top = -1;

void push(char c) 
{
    if (top == MAX - 1) 
    {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop()
 {
    if (top == -1) 
    {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

char peek() 
{
    if (top == -1)
    {
        return -1;
    }
    return stack[top];
}

int precedence(char op)
 {
    switch (op)
     {
        case '^':
            return 3;

        case '*':
        case '/':
            return 2;

        case '+':
        case '-':
            return 1;
        
        default:
            return 0;
    }
}

int isOperator(char c) 
{
    switch (c) 
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            return 1;
        default:
            return 0;
    }
}

void infixToPostfix(char* infix, char* postfix)
 {
    int i, j = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++) 
    {
        c = infix[i];

        switch (c)
         {
            case ' ':
            case '\t':
                // Ignore whitespace
                break;
            case '(':
                push(c);
                break;
            case ')':
                while (top != -1 && peek() != '(')
                {
                    postfix[j++] = pop();
                }
                if (top != -1) 
                {
                    pop(); // pop the '('
                }
                break;
            default:
                if (isalnum(c))
                {
                    postfix[j++] = c;
                } 
                else if (isOperator(c)) 
                {
                    while (top != -1 && precedence(peek()) >= precedence(c)) 
                    {
                        postfix[j++] = pop();
                    }
                    push(c);
                }
                break;
        }
    }

    while (top != -1) 
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() 
{
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
