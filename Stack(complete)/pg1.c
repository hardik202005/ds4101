/*1. CREATE A STACK IMPLEMENTING THE OPERATIONS ON AN INTEGER ARRAY (PUSH, POP, PEEK, ISEMPTY, ISFULL) */

#include <stdio.h>

int isFull(int top, int size)
{
    return top == size - 1;
}

int isEmpty(int top)
{
    return top == -1;
}

int push(int arr[], int length, int data, int topElt)
{
    if (topElt == length - 1)
    {
        printf("The stack is full \n");
    }
    else
    {
        topElt++;
        arr[topElt] = data;
        printf("Entered value in the stack is: %d \n", arr[topElt]);
    }
    return topElt; // returns updated top value
}

int pop(int arr[], int topElt)
{
    if (topElt == -1)
    {
        printf("Stack is underflow \n");
    }
    else
    {
        printf("Popped element is: %d  \n", arr[topElt--]);
    }
    return topElt; // returns updated top value
}

int peek(int arr[], int topElt)
{
    return arr[topElt];
}

int main()
{
    int stck_arr[100];
    int length = 3, choice, data, top = -1, check;

    while (1)
    {
        printf("1. For pushing value in stack:\n");
        printf("2. For popping out value from the stack:\n");
        printf("3. For viewing last element of the stack:\n");
        printf("4. For checking if stack is full:\n");
        printf("5. For checking if stack is empty:\n");
        printf("6. Quit:\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter a value to push in the stack: ");
            scanf("%d", &data);
            top = push(stck_arr, length, data, top); // updates top value
        }
        else if (choice == 2)
        {
            top = pop(stck_arr, top); // pops value and updates top
        }
        else if (choice == 3)
        {
            if (isEmpty(top))
            {
                printf("The stack is empty, no top element.\n");
            }
            else
            {
                printf("Last/top element of the stack is: %d \n", peek(stck_arr, top));
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

    1. For pushing value in stack:
    2. For popping out value from the stack:
    3. For viewing last element of the stack:
    4. For checking if stack is full:
    5. For checking if stack is empty:
    6. Quit:
    Enter your choice: 5
    Stack is empty.
    1. For pushing value in stack:
    2. For popping out value from the stack:
    3. For viewing last element of the stack:
    4. For checking if stack is full:
    5. For checking if stack is empty:
    6. Quit:
    Enter your choice: 4
    Stack is not full.
    1. For pushing value in stack:
    2. For popping out value from the stack:
    3. For viewing last element of the stack:
    4. For checking if stack is full:
    5. For checking if stack is empty:
    6. Quit:
    Enter your choice: 1
    Enter a value to push in the stack: 12
    Entered value in the stack is: 12
    1. For pushing value in stack:
    2. For popping out value from the stack:
    3. For viewing last element of the stack:
    4. For checking if stack is full:
    5. For checking if stack is empty:
    6. Quit:
    Enter your choice: 4
    Stack is not full.
    1. For pushing value in stack:
    2. For popping out value from the stack:
    3. For viewing last element of the stack:
    4. For checking if stack is full:
    5. For checking if stack is empty:
    6. Quit:
    Enter your choice: 5
    Stack is not empty.
    1. For pushing value in stack:
    2. For popping out value from the stack:
    3. For viewing last element of the stack:
    4. For checking if stack is full:
    5. For checking if stack is empty:
    6. Quit:
    Enter your choice: 3
    Last/top element of the stack is: 12
    1. For pushing value in stack:
    2. For popping out value from the stack:
    3. For viewing last element of the stack:
    4. For checking if stack is full:
    5. For checking if stack is empty:
    6. Quit:
    Enter your choice: 2
    Popped element is: 12
    1. For pushing value in stack:
    2. For popping out value from the stack:
    3. For viewing last element of the stack:
    4. For checking if stack is full:
    5. For checking if stack is empty:
    6. Quit:
    Enter your choice: 6
    You have successfully exited the program!

 */