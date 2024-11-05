/*
4. CREATE A STACK IMPLEMENTING THE OPERATIONS ON THE CHARACTERS NODES (DYNAMICALLY) (PUSH, POP, PEEK, ISEMPTY, ISFULL)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node *next;
} Node;

Node *top = NULL;
int isEmpty()
{
    return top == NULL;
}
void push(char value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Stack overflow! Unable to allocate memory.\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Pushed '%c' onto the stack.\n", value);
}
void pop()
{
    if (isEmpty())
    {
        printf("Stack underflow! The stack is empty.\n");
        return;
    }
    Node *temp = top;
    printf("Popped '%c' from the stack.\n", top->data);
    top = top->next;
    free(temp);
}
void peek()
{
    if (isEmpty())
    {
        printf("The stack is empty.\n");
    }
    else
    {
        printf("Top character is '%c'\n", top->data);
    }
}
int isFull()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return 1; // Stack is "full" (out of memory)
    }
    free(newNode); // Immediately free to avoid memory leak
    return 0;
}

int main()
{
    int choice;
    char value;
    while (1)
    {
        printf("\nStack Operations:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. isFull\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the character to push: ");
            scanf(" %c", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            if (isEmpty())
            {
                printf("The stack is empty.\n");
            }
            else
            {
                printf("The stack is not empty.\n");
            }
            break;
        case 5:
            if (isFull())
            {
                printf("The stack is full.\n");
            }
            else
            {
                printf("The stack is not full.\n");
            }
            break;
        case 6:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    }
}

/*      Output:-

Stack Operations:
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Exit
Enter your choice: 1
Enter the character to push: a
Pushed 'a' onto the stack.

Stack Operations:
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Exit
Enter your choice: 1
Enter the character to push: b
Pushed 'b' onto the stack.

Stack Operations:
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Exit
Enter your choice: 1
Enter the character to push: c
Pushed 'c' onto the stack.

Stack Operations:
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Exit
Enter your choice: 1
Enter the character to push: d
Pushed 'd' onto the stack.

Stack Operations:
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Exit
Enter your choice: 1
Enter the character to push: e
Pushed 'e' onto the stack.

Stack Operations:
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Exit
Enter your choice: 3
Top character is 'e'

Stack Operations:
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Exit
Enter your choice: 4
The stack is not empty.

Stack Operations:
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Exit
Enter your choice: 5
The stack is not full.

Stack Operations:
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Exit
Enter your choice: 2
Popped 'e' from the stack.

Stack Operations:
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Exit
Enter your choice: 2
Popped 'd' from the stack.

Stack Operations:
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Exit
Enter your choice: 2
Popped 'c' from the stack.

Stack Operations:
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Exit
Enter your choice: 2
Popped 'b' from the stack.

Stack Operations:
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Exit
Enter your choice: 2
Popped 'a' from the stack.

Stack Operations:
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Exit
Enter your choice: 2
Stack underflow! The stack is empty.

Stack Operations:
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Exit
Enter your choice: 4
The stack is empty.

Stack Operations:
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Exit
Enter your choice: 5
The stack is not full.

Stack Operations:
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Exit
Enter your choice: 6
Exiting...

*/