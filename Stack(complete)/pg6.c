/*
6. CREATE THE PROGRAM TO MATCH THE SINGLE BRACKET USING STACKS.
*/
#include <stdio.h>

#define MAX 100

int isEmpty(int top)
{
    return top == -1;
}

int isFull(int top)
{
    return top == MAX - 1;
}

int push(char stack[], int top, char data)
{
    if (isFull(top))
    {
        printf("Stack overflow\n");
    }
    else
    {
        stack[++top] = data;
    }
    return top;
}
int pop(int top)
{
    if (isEmpty(top))
    {
        printf("Stack underflow\n");
    }
    else
    {
        top--;
    }
    return top;
}

int main()
{
    char expr[MAX];
    char stack[MAX];
    int top = -1;
    int i = 0;

    printf("Enter an expression with brackets: ");
    fgets(expr, MAX, stdin);
    while (expr[i] != '\0' && expr[i] != '\n')
    {
        if (expr[i] == '(')
        {
            top = push(stack, top, '(');
        }
        else if (expr[i] == ')')
        {
            if (isEmpty(top))
            {
                printf("Unmatched closing bracket at position %d\n", i);
                return 0;
            }
            top = pop(top);
        }
        i++;
    }

    if (!isEmpty(top))
    {
        printf("Unmatched opening bracket(s) found\n");
    }
    else
    {
        printf("Brackets are balanced\n");
    }

    return 0;
}


/*      Output  

Enter an expression with brackets: (a+b)(a)
Brackets are balanced

Enter an expression with brackets: (a+b)(a*b(c)
Unmatched opening bracket(s) found

*/