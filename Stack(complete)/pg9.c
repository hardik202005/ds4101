/*
9. ENTER THE INFIX EXPRESSION FROM USER AND CONVERT INTO PREFIX EXPRESSION.
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
void reverse(char *str)
{
    int length = 0;
    while (str[length] != '\0')
        length++;

    for (int i = 0; i < length / 2; i++)
    {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
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
            pop(); // Pop the '('
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
void infixToPrefix(char infix[], char prefix[])
{
    char postfix[MAX];

    reverse(infix);
    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    infixToPostfix(infix, postfix);
    reverse(postfix);
    int i;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        prefix[i] = postfix[i];
    }
    prefix[i] = '\0';
}

int main()
{
    char infix[MAX], prefix[MAX];

    printf("Enter an infix expression: ");
    int i = 0;
    char ch;
    while ((ch = getchar()) != '\n' && i < MAX - 1)
    {
        infix[i++] = ch;
    }
    infix[i] = '\0';

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}

/*  Output:-

Enter an infix expression: (A+B)*(C-D)
Prefix expression: *+AB-CD

*/