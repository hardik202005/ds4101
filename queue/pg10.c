#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 5
#define STR_LEN 100

typedef struct Deque
{
  char items[MAX][STR_LEN];
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

void insertFront(Deque *dq, const char *value)
{
  if (isFull(dq))
  {
    printf("Deque is full. Cannot insert \"%s\" at front.\n", value);
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

  strcpy(dq->items[dq->front], value);
  printf("\"%s\" inserted at the front of the deque.\n", value);
}

void insertRear(Deque *dq, const char *value)
{
  if (isFull(dq))
  {
    printf("Deque is full. Cannot insert \"%s\" at rear.\n", value);
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

  strcpy(dq->items[dq->rear], value);
  printf("\"%s\" inserted at the rear of the deque.\n", value);
}

char *deleteFront(Deque *dq)
{
  if (isEmpty(dq))
  {
    printf("Deque is empty. Cannot delete from front.\n");
    return NULL;
  }

  char *item = dq->items[dq->front];
  if (dq->front == dq->rear)
  {
    dq->front = -1;
    dq->rear = -1;
  }
  else
  {
    dq->front = (dq->front + 1) % MAX;
  }

  printf("\"%s\" deleted from the front of the deque.\n", item);
  return item;
}

char *deleteRear(Deque *dq)
{
  if (isEmpty(dq))
  {
    printf("Deque is empty. Cannot delete from rear.\n");
    return NULL;
  }

  char *item = dq->items[dq->rear];
  if (dq->front == dq->rear)
  {
    dq->front = -1;
    dq->rear = -1;
  }
  else
  {
    dq->rear = (dq->rear - 1 + MAX) % MAX;
  }

  printf("\"%s\" deleted from the rear of the deque.\n", item);
  return item;
}

char *peekFront(Deque *dq)
{
  if (isEmpty(dq))
  {
    printf("Deque is empty. Nothing to peek at front.\n");
    return NULL;
  }
  return dq->items[dq->front];
}

char *peekRear(Deque *dq)
{
  if (isEmpty(dq))
  {
    printf("Deque is empty. Nothing to peek at rear.\n");
    return NULL;
  }
  return dq->items[dq->rear];
}

int main()
{
  Deque *dq = createDeque();
  char input[STR_LEN];
  int choice;

  do
  {
    printf("\n1. Insert at Front\n2. Insert at Rear\n3. Delete from Front\n4. Delete from Rear\n5. Peek Front\n6. Peek Rear\n7. Check if Empty\n8. Check if Full\n9. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
    case 1:
      printf("Enter a string to insert at front: ");
      fgets(input, sizeof(input), stdin);
      input[strcspn(input, "\n")] = '\0';
      insertFront(dq, input);
      break;
    case 2:
      printf("Enter a string to insert at rear: ");
      fgets(input, sizeof(input), stdin);
      input[strcspn(input, "\n")] = '\0';
      insertRear(dq, input);
      break;
    case 3:
      deleteFront(dq);
      break;
    case 4:
      deleteRear(dq);
      break;
    case 5:
      printf("Front element is \"%s\"\n", peekFront(dq));
      break;
    case 6:
      printf("Rear element is \"%s\"\n", peekRear(dq));
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