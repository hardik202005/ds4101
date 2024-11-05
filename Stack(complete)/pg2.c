#include <stdio.h>

int isFull(int top, int size)
{
    return top == size - 1;
}

int isEmpty(int top)
{
    return top == -1;
}

int push(char arr[], int length, char data, int topElt)
{
    if (topElt == length - 1)
    {
        printf("The stack is full\n");
    }
    else
    {
        topElt++;
        arr[topElt] = data;
        printf("Entered value in the stack is: %c\n", arr[topElt]);
    }
    return topElt;
}

int pop(char arr[], int topElt)
{
    if (topElt == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        printf("Popped element is: %c\n", arr[topElt--]);
    }
    return topElt;
}

char peek(char arr[], int topElt)
{
    return arr[topElt];
}

int main()
{
    char stck_str[100];
    int length = 3, choice, top = -1, check;
    char data;
    while (1)
    {
        printf("1. Push value into stack\n");
        printf("2. Pop value from stack\n");
        printf("3. View top element of stack\n");
        printf("4. Check if stack is full\n");
        printf("5. Check if stack is empty\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter a character to push into the stack: ");
            scanf(" %c", &data);
            top = push(stck_str, length, data, top);
        }
        else if (choice == 2)
        {
            top = pop(stck_str, top);
        }
        else if (choice == 3)
        {
            if (isEmpty(top))
            {
                printf("The stack is empty, no top element.\n");
            }
            else
            {
                printf("Top element of the stack is: %c\n", peek(stck_str, top));
            }
        }
        else if (choice == 4)
        {
            check = isFull(top, length);
            if (check == 1)
            {
                printf("Stack is full.\n");
            }
            else
            {
                printf("Stack is not full.\n");
            }
        }
        else if (choice == 5)
        {
            check = isEmpty(top);
            if (check == 1)
            {
                printf("Stack is empty.\n");
            }
            else
            {
                printf("Stack is not empty.\n");
            }
        }
        else if (choice == 6)
        {
            printf("You have successfully exited the program!\n");
            break;
        }
        else
        {
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

/*      Output:-

1. Push value into stack
2. Pop value from stack
3. View top element of stack
4. Check if stack is full
5. Check if stack is empty
6. Quit
Enter your choice: 1
Enter a character to push into the stack: a
Entered value in the stack is: a
1. Push value into stack
2. Pop value from stack
3. View top element of stack
4. Check if stack is full
5. Check if stack is empty
6. Quit
Enter your choice: 2
Popped element is: a
1. Push value into stack
2. Pop value from stack
3. View top element of stack
4. Check if stack is full
5. Check if stack is empty
6. Quit
Enter your choice: 1
Enter a character to push into the stack: r
Entered value in the stack is: r
1. Push value into stack
2. Pop value from stack
3. View top element of stack
4. Check if stack is full
5. Check if stack is empty
6. Quit
Enter your choice: 1
Enter a character to push into the stack: t
Entered value in the stack is: t
1. Push value into stack
2. Pop value from stack
3. View top element of stack
4. Check if stack is full
5. Check if stack is empty
6. Quit
Enter your choice: 1
Enter a character to push into the stack: y
Entered value in the stack is: y
1. Push value into stack
2. Pop value from stack
3. View top element of stack
4. Check if stack is full
5. Check if stack is empty
6. Quit
Enter your choice: 1
Enter a character to push into the stack: u
The stack is full
1. Push value into stack
2. Pop value from stack
3. View top element of stack
4. Check if stack is full
5. Check if stack is empty
6. Quit
Enter your choice: 3
Top element of the stack is: y
1. Push value into stack
2. Pop value from stack
3. View top element of stack
4. Check if stack is full
5. Check if stack is empty
6. Quit
Enter your choice: 4
Stack is full.
1. Push value into stack
2. Pop value from stack
3. View top element of stack
4. Check if stack is full
5. Check if stack is empty
6. Quit
Enter your choice: 5
Stack is not empty.
1. Push value into stack
2. Pop value from stack
3. View top element of stack
4. Check if stack is full
5. Check if stack is empty
6. Quit
Enter your choice: 6
You have successfully exited the program!

*/