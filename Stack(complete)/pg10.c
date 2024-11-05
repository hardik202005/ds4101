/*
10. ENTER THE INFIX EXPRESSION FROM USER AND CONVERT INTO POSTFIX EXPRESSION.
*/

#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c)
{
    if (top < MAX - 1)
    {
        top++;
        stack[top] = c;
    }
    else
    {
        printf("Stack overflow\n");
    }
}

char pop()
{
    if (top >= 0)
    {
        return stack[top--];
    }
    else
    {
        printf("Stack underflow\n");
        return '\0';
    }
}

char peek()
{
    if (top >= 0)
    {
        return stack[top];
    }
    return '\0';
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        if ((infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= '0' && infix[i] <= '9'))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[j++] = pop();
            }
            pop();
        }
        else
        {
            while (top != -1 && precedence(peek()) >= precedence(infix[i]))
            {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
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
    int i = 0;
    char ch;
    while ((ch = getchar()) != '\n' && i < MAX - 1)
    {
        infix[i++] = ch;
    }
    infix[i] = '\0';

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}


/*  
        Output:-    
    Enter an infix expression: (A+B)*c/(A-B) 
    Postfix expression: AB+c*AB-/

    */