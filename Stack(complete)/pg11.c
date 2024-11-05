/*
11. CREATE A PROGRAM TO EVALUATE THE PREFIX EXPRESSION.
*/

#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top < MAX - 1)
    {
        top++;
        stack[top] = value;
    }
    else
    {
        printf("Stack overflow\n");
    }
}

int pop()
{
    if (top >= 0)
    {
        int value = stack[top];
        top--;
        return value;
    }
    else
    {
        printf("Stack underflow\n");
        return 0;
    }
}

int evaluatePrefix(char expression[])
{
    int i;
    for (i = 0; expression[i] != '\0'; i++); 
    i--;  

    while (i >= 0)
    {
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            int operand = expression[i] - '0'; 
            push(operand);
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
        {
            int operand1 = pop();
            int operand2 = pop();
            int result;

            if (expression[i] == '+')
            {
                result = operand1 + operand2;
            }
            else if (expression[i] == '-')
            {
                result = operand1 - operand2;
            }
            else if (expression[i] == '*')
            {
                result = operand1 * operand2;
            }
            else if (expression[i] == '/')
            {
                if (operand2 == 0)
                {
                    printf("Error: Division by zero\n");
                    return 0;
                }
                result = operand1 / operand2;
            }

            push(result);
        }
        else
        {
            printf("Error: Unrecognized character '%c' in expression\n", expression[i]);
            return 0;
        }

        i--;
    }

    return pop();
}

int main()
{
    char expression[MAX];
    printf("Enter a prefix expression: ");
    int i = 0;
    char ch;
    while ((ch = getchar()) != '\n' && i < MAX - 1)
    {
        expression[i++] = ch;
    }
    expression[i] = '\0';

    int result = evaluatePrefix(expression);
    printf("Result of the prefix expression: %d\n", result);

    return 0;
}

/*  Output:-

Enter a prefix expression: -+8/632
Result of the prefix expression: 8

Enter a prefix expression: *+2-21/-42+-531      
Result of the prefix expression: 0

*/