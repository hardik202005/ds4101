#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef struct CircularQueue
{
  int items[MAX];
  int front;
  int rear;
  int count;
} CircularQueue;

CircularQueue *createQueue()
{
  CircularQueue *q = (CircularQueue *)malloc(sizeof(CircularQueue));
  q->front = 0;
  q->rear = 0;
  q->count = 0;
  return q;
}

bool isEmpty(CircularQueue *q)
{
  return (q->count == 0);
}

bool isFull(CircularQueue *q)
{
  return (q->count == MAX);
}

void insert(CircularQueue *q, int value)
{
  if (isFull(q))
  {
    printf("Queue is full. Cannot insert %d.\n", value);
    return;
  }
  q->items[q->rear] = value;
  q->rear = (q->rear + 1) % MAX;
  q->count++;
  printf("%d inserted into the queue.\n", value);
}

int delete(CircularQueue *q)
{
  if (isEmpty(q))
  {
    printf("Queue is empty. Cannot delete.\n");
    return -1;
  }

  int item = q->items[q->front];
  q->front = (q->front + 1) % MAX;
  q->count--;

  printf("%d deleted from the queue.\n", item);
  return item;
}

int peek(CircularQueue *q)
{
  if (isEmpty(q))
  {
    printf("Queue is empty. Nothing to peek.\n");
    return -1;
  }
  return q->items[q->front];
}

int main()
{
  CircularQueue *q = createQueue();
  int choice, value;

  do
  {
    printf("\n1. Insert\n2. Delete\n3. Peek\n4. Check if Empty\n5. Check if Full\n6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter an integer to insert: ");
      scanf("%d", &value);
      insert(q, value);
      break;
    case 2:
      delete (q);
      break;
    case 3:
      printf("Front element is %d\n", peek(q));
      break;
    case 4:
      if (isEmpty(q))
      {
        printf("Queue is empty.\n");
      }
      else
      {
        printf("Queue is not empty.\n");
      }
      break;
    case 5:
      if (isFull(q))
      {
        printf("Queue is full.\n");
      }
      else
      {
        printf("Queue is not full.\n");
      }
      break;
    case 6:
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid choice. Please try again.\n");
      break;
    }
  } while (choice != 6);

  free(q);
  return 0;
}