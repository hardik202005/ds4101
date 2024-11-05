#include <stdio.h>
#include <conio.h>

#define MAX_SIZE 3

int queue[MAX_SIZE];
int front = -1; // helps of deletion
int rear = -1;  // helps of insertion
int item;

void insert()
{

  if (rear == MAX_SIZE - 1)
  {
    printf("queue is full:\n");
  }

  else
  {
    printf("enter the element:");
    scanf("%d", &item);

    if (front == -1)
    {
      front = rear = 0;
    }

    else
    {
      rear++;
    }

    queue[rear] = item;
    printf("item inserted:\n");
  }
}

void deletion()
{
  if (front == -1)
  {
    printf("queue is empty:");
  }

  else
  {
    item = queue[front];

    if (front == rear)
    {
      front = rear = -1;
    }

    else
    {
      front++;
    }
    printf("item deleted\n");
  }
}

void display()
{
  if (front == -1)
  {
    printf("queue is empty");
  }
  else
  {
    printf("queue elements are:");
    for (int i = front; i <= rear; i++)
    {
      printf("%d\n", queue[i]);
    }
    printf("\n");
  }
}

int main()
{
  int choice;

  printf("1.insertion\n 2.deletion \n 3.display \n 4.exit \n");

  while (1)
  {
    printf("enter your choice:");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      insert();
      break;

    case 2:
      deletion();
      break;

    case 3:
      display();
      break;

    case 4:
      printf("exit");
      return 0;

    default:
      printf("invalid choice");
    }
  }
}