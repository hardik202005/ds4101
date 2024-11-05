/*
5. ENTER THE STRING FROM THE USER AND REVERSE THE STRING USING STACKS.
*/

#include <stdio.h>

char str_stack[50];
int top = -1;

void push(char c)
{
    top++;
    str_stack[top] = c;
}

char pop()
{
    char c;
    c = str_stack[top];
    top--;
    return c;
}

int main()
{
    char str[50], value;
    int length = 0, i;
    printf("Enter string : ");
    scanf("%s", &str);
    printf("%s ", str);

    for (int i = 0; str[i]; i++)
    {
        length++;
    }
    printf("\n length of the str is : %d \n", length);

    for (int i = 0; i < length; i++)
    {
        push(str[i]);
    }

    printf("reverse string is :");
    for (int i = 0; i < length; i++)
    {
        value = pop();
        printf("%c", value);
    }

    return 0;
}

/*      Output:-
Enter string : string
string
length of the str is : 6
reverse string is :gnirts

*/