/*8. SORT THE STACK IN ASCENDING ORDER USING INTEGER ARRAY.*/
#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top < MAX - 1)
    {
        stack[++top] = value;
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
        return stack[top--];
    }
    else
    {
        printf("Stack underflow\n");
        return -1;
    }
}

int isEmpty()
{
    return top == -1;
}

void sortStack()
{
    int tempStack[MAX];
    int tempTop = -1;

    while (!isEmpty())
    {
        int temp = pop();

        while (tempTop != -1 && tempStack[tempTop] > temp)
        {
            push(tempStack[tempTop--]);
        }

        tempStack[++tempTop] = temp;
    }

    while (tempTop != -1)
    {
        push(tempStack[tempTop--]);
    }
}

void displayStack()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    int n, value;

    printf("Enter the number of elements to push onto the stack: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &value);
        push(value);
    }

    printf("Original Stack: ");
    displayStack();

    sortStack();

    printf("Sorted Stack (Ascending): ");
    displayStack();

    return 0;
}

/*  Output:-

Enter the number of elements to push onto the stack: 5
Enter 5 elements:
Element 1: 3
Element 2: 5
Element 3: 2
Element 4: 6
Element 5: 7
Original Stack: 3 5 2 6 7
Sorted Stack (Ascending): 7 6 5 3 2

*/
