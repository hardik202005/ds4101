#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

typedef struct Queue
{
  Node *front;
  Node *rear;
} Queue;

Queue *createQueue()
{
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->front = NULL;
  q->rear = NULL;
  return q;
}

bool isEmpty(Queue *q)
{
  return q->front == NULL;
}

void insert(Queue *q, int value)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = value;
  newNode->next = NULL;

  if (isEmpty(q))
  {
    q->front = newNode;
  }
  else
  {
    q->rear->next = newNode;
  }
  q->rear = newNode;

  printf("%d inserted into the queue.\n", value);
}

int delete(Queue *q)
{
  if (isEmpty(q))
  {
    printf("Queue is empty. Cannot delete.\n");
    return -1;
  }

  Node *temp = q->front;
  int item = temp->data;
  q->front = q->front->next;

  if (q->front == NULL)
  {
    q->rear = NULL;
  }

  free(temp);
  printf("%d deleted from the queue.\n", item);
  return item;
}

int peek(Queue *q)
{
  if (isEmpty(q))
  {
    printf("Queue is empty. Nothing to peek.\n");
    return -1;
  }
  return q->front->data;
}

int main()
{
  Queue *q = createQueue();
  int choice, value;

  do
  {
    printf("\n1. Insert\n2. Delete\n3. Peek\n4. Check if Empty\n5. Exit\n");
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
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid choice. Please try again.\n");
      break;
    }
  } while (choice != 5);

  while (!isEmpty(q))
  {
    delete (q);
  }

  free(q);
  return 0;
}