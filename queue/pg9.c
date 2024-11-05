#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef struct Deque
{
  int items[MAX];
  int front;
  int rear;
} Deque;

Deque *createDeque()
{
  Deque *dq = (Deque *)malloc(sizeof(Deque));
  dq->front = -1;
  dq->rear = -1;
  return dq;
}

bool isEmpty(Deque *dq)
{
  return (dq->front == -1);
}

bool isFull(Deque *dq)
{
  return ((dq->rear + 1) % MAX == dq->front);
}

void insertFront(Deque *dq, int value)
{
  if (isFull(dq))
  {
    printf("Deque is full. Cannot insert %d at front.\n", value);
    return;
  }

  if (isEmpty(dq))
  {
    dq->front = 0;
    dq->rear = 0;
  }
  else
  {
    dq->front = (dq->front - 1 + MAX) % MAX;
  }

  dq->items[dq->front] = value;
  printf("%d inserted at the front of the deque.\n", value);
}

void insertRear(Deque *dq, int value)
{
  if (isFull(dq))
  {
    printf("Deque is full. Cannot insert %d at rear.\n", value);
    return;
  }

  if (isEmpty(dq))
  {
    dq->front = 0;
    dq->rear = 0;
  }
  else
  {
    dq->rear = (dq->rear + 1) % MAX;
  }

  dq->items[dq->rear] = value;
  printf("%d inserted at the rear of the deque.\n", value);
}

int deleteFront(Deque *dq)
{
  if (isEmpty(dq))
  {
    printf("Deque is empty. Cannot delete from front.\n");
    return -1;
  }

  int item = dq->items[dq->front];
  if (dq->front == dq->rear)
  {
    dq->front = -1;
    dq->rear = -1;
  }
  else
  {
    dq->front = (dq->front + 1) % MAX;
  }

  printf("%d deleted from the front of the deque.\n", item);
  return item;
}

int deleteRear(Deque *dq)
{
  if (isEmpty(dq))
  {
    printf("Deque is empty. Cannot delete from rear.\n");
    return -1;
  }

  int item = dq->items[dq->rear];
  if (dq->front == dq->rear)
  {
    dq->front = -1;
    dq->rear = -1;
  }
  else
  {
    dq->rear = (dq->rear - 1 + MAX) % MAX;
  }

  printf("%d deleted from the rear of the deque.\n", item);
  return item;
}

int peekFront(Deque *dq)
{
  if (isEmpty(dq))
  {
    printf("Deque is empty. Nothing to peek at front.\n");
    return -1;
  }
  return dq->items[dq->front];
}

int peekRear(Deque *dq)
{
  if (isEmpty(dq))
  {
    printf("Deque is empty. Nothing to peek at rear.\n");
    return -1;
  }
  return dq->items[dq->rear];
}

int main()
{
  Deque *dq = createDeque();
  int choice, value;

  do
  {
    printf("\n1. Insert at Front\n2. Insert at Rear\n3. Delete from Front\n4. Delete from Rear\n5. Peek Front\n6. Peek Rear\n7. Check if Empty\n8. Check if Full\n9. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter an integer to insert at front: ");
      scanf("%d", &value);
      insertFront(dq, value);
      break;
    case 2:
      printf("Enter an integer to insert at rear: ");
      scanf("%d", &value);
      insertRear(dq, value);
      break;
    case 3:
      deleteFront(dq);
      break;
    case 4:
      deleteRear(dq);
      break;
    case 5:
      printf("Front element is %d\n", peekFront(dq));
      break;
    case 6:
      printf("Rear element is %d\n", peekRear(dq));
      break;
    case 7:
      if (isEmpty(dq))
      {
        printf("Deque is empty.\n");
      }
      else
      {
        printf("Deque is not empty.\n");
      }
      break;
    case 8:
      if (isFull(dq))
      {
        printf("Deque is full.\n");
      }
      else
      {
        printf("Deque is not full.\n");
      }
      break;
    case 9:
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid choice. Please try again.\n");
      break;
    }
  } while (choice != 9);

  free(dq);
  return 0;
}