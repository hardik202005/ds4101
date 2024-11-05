#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node
{
  char *data;
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

void insert(Queue *q, const char *value)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = (char *)malloc((strlen(value) + 1) * sizeof(char));
  strcpy(newNode->data, value);
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

  printf("\"%s\" inserted into the queue.\n", value);
}

char *delete(Queue *q)
{
  if (isEmpty(q))
  {
    printf("Queue is empty. Cannot delete.\n");
    return NULL;
  }

  Node *temp = q->front;
  char *item = temp->data;
  q->front = q->front->next;

  if (q->front == NULL)
  {
    q->rear = NULL;
  }

  free(temp);
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
  return q->front->data;
}

int main()
{
  Queue *q = createQueue();
  char input[100];
  int choice;

  do
  {
    printf("\n1. Insert\n2. Delete\n3. Peek\n4. Check if Empty\n5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
    case 1:
      printf("Enter a string to insert: ");
      fgets(input, sizeof(input), stdin);
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
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid choice. Please try again.\n");
      break;
    }
  } while (choice != 5);

  while (!isEmpty(q))
  {
    char *deletedItem = delete (q);
    free(deletedItem);
  }

  free(q);
  return 0;
}