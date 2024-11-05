/*
3. CREATE A STACK IMPLEMENTING THE OPERATIONS ON AN INTEGER NODES (DYNAMICALLY) (PUSH, POP, PEEK, ISEMPTY, ISFULL)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *top = NULL;
int isEmpty()
{
    return top == NULL;
}
void push(int value)
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
    printf("Pushed %d onto the stack.\n", value);
}
void pop()
{
    if (isEmpty())
    {
        printf("Stack underflow! The stack is empty.\n");
        return;
    }
    Node *temp = top;
    printf("Popped %d from the stack.\n", top->data);
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
        printf("Top element is %d\n", top->data);
    }
}
int isFull()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return 1;
    }
    free(newNode);
    return 0;
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("\nStack Operations:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. isFull\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to push: ");
            scanf("%d", &value);
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

/*  Output:-

Stack Operations:
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Exit
Enter your choice: 1
Enter the value to push: 2
Pushed 2 onto the stack.

Stack Operations:
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Exit
Enter your choice: 1
Enter the value to push: 4
Pushed 4 onto the stack.

Stack Operations:
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Exit
Enter your choice: 1
Enter the value to push: 5
Pushed 5 onto the stack.

Stack Operations:
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Exit
Enter your choice: 1
Enter the value to push: 7
Pushed 7 onto the stack.

Stack Operations:
1. Push
2. Pop
3. Peek
4. isEmpty
5. isFull
6. Exit
Enter your choice: 3
Top element is 7

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
Popped 7 from the stack.

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