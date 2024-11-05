#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX 5
#define STR_LEN 100

typedef struct Queue
{
  char items[MAX][STR_LEN];
  int front;
  int rear;
} Queue;

Queue *createQueue()
{
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->front = -1;
  q->rear = -1;
  return q;
}

bool isEmpty(Queue *q)
{
  return q->front == -1;
}

bool isFull(Queue *q)
{
  return q->rear == MAX - 1;
}

void insert(Queue *q, const char *value)
{
  if (isFull(q))
  {
    printf("Queue is full. Cannot insert \"%s\".\n", value);
    return;
  }
  if (isEmpty(q))
  {
    q->front = 0;
  }
  q->rear++;
  strcpy(q->items[q->rear], value);
  printf("\"%s\" inserted into the queue.\n", value);
}

char *delete(Queue *q)
{
  if (isEmpty(q))
  {
    printf("Queue is empty. Cannot delete.\n");
    return NULL;
  }
  char *item = q->items[q->front];
  q->front++;

  if (q->front > q->rear)
  {

    q->front = q->rear = -1;
  }

  printf("\"%s\" deleted from the queue.\n", item);
  return item;
}

char *peek(Queue *q)
{
  if (isEmpty(q))
  {
    printf("Queue is empty. Nothing to peek.\n");
    return NULL;
  }
  return q->items[q->front];
}

int main()
{
  Queue *q = createQueue();
  char input[STR_LEN];
  int choice;

  do
  {
    printf("\n1. Insert\n2. Delete\n3. Peek\n4. Check if Empty\n5. Check if Full\n6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
    case 1:
      printf("Enter a string to insert: ");
      fgets(input, STR_LEN, stdin);
      input[strcspn(input, "\n")] = '\0';
      insert(q, input);
      break;
    case 2:
      delete (q);
      break;
    case 3:
      printf("Front element is \"%s\"\n", peek(q));
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