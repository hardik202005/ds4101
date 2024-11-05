/* 7. CREATE TWO INTEGER STACKS IN A SINGLE ARRAY. */
#include <stdio.h>

#define MAX 100

int stack[MAX];
int top1 = -1;
int top2 = MAX;

void push1(int value)
{
    if (top1 < top2 - 1)
    {
        stack[++top1] = value;
        printf("Pushed %d to Stack 1\n", value);
    }
    else
    {
        printf("Stack Overflow! No space in Stack 1.\n");
    }
}

void push2(int value)
{
    if (top1 < top2 - 1)
    {
        stack[--top2] = value;
        printf("Pushed %d to Stack 2\n", value);
    }
    else
    {
        printf("Stack Overflow! No space in Stack 2.\n");
    }
}

int pop1()
{
    if (top1 >= 0)
    {
        int value = stack[top1--];
        printf("Popped %d from Stack 1\n", value);
        return value;
    }
    else
    {
        printf("Stack Underflow! Stack 1 is empty.\n");
        return -1;
    }
}

int pop2()
{
    if (top2 < MAX)
    {
        int value = stack[top2++];
        printf("Popped %d from Stack 2\n", value);
        return value;
    }
    else
    {
        printf("Stack Underflow! Stack 2 is empty.\n");
        return -1;
    }
}

int isEmpty1()
{
    return top1 == -1;
}

int isEmpty2()
{
    return top2 == MAX;
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Push to Stack 1\n");
        printf("2. Push to Stack 2\n");
        printf("3. Pop from Stack 1\n");
        printf("4. Pop from Stack 2\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push to Stack 1: ");
            scanf("%d", &value);
            push1(value);
            break;
        case 2:
            printf("Enter value to push to Stack 2: ");
            scanf("%d", &value);
            push2(value);
            break;
        case 3:
            pop1();
            break;
        case 4:
            pop2();
            break;
        case 5:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


/*   Output:-    

Menu:
1. Push to Stack 1
2. Push to Stack 2
3. Pop from Stack 1
4. Pop from Stack 2
5. Exit
Enter your choice: 1
Enter value to push to Stack 1: 10
Pushed 10 to Stack 1

Menu:
1. Push to Stack 1
2. Push to Stack 2
3. Pop from Stack 1
4. Pop from Stack 2
5. Exit
Enter your choice: 2
Enter value to push to Stack 2: 100
Pushed 100 to Stack 2

Menu:
1. Push to Stack 1
2. Push to Stack 2
3. Pop from Stack 1
4. Pop from Stack 2
5. Exit
Enter your choice: 3
Popped 10 from Stack 1

Menu:
1. Push to Stack 1
2. Push to Stack 2
3. Pop from Stack 1
4. Pop from Stack 2
5. Exit
Enter your choice: 5
Exiting program.


*/