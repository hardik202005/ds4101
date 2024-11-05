#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 5       // Maximum size of the priority queue
#define STR_LEN 100 // Maximum length of the string

typedef struct PriorityQueue
{
  char items[MAX][STR_LEN];
  int count;
} PriorityQueue;

PriorityQueue *createQueue()
{
  PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
  pq->count = 0;
  return pq;
}

bool isEmpty(PriorityQueue *pq)
{
  return (pq->count == 0);
}

bool isFull(PriorityQueue *pq)
{
  return (pq->count == MAX);
}

void insert(PriorityQueue *pq, const char *value)
{
  if (isFull(pq))
  {
    printf("Priority Queue is full. Cannot insert \"%s\".\n", value);
    return;
  }

  int i;
  for (i = pq->count - 1; (i >= 0 && strcmp(pq->items[i], value) > 0); i--)
  {
    strcpy(pq->items[i + 1], pq->items[i]);
  }
  strcpy(pq->items[i + 1], value);
  pq->count++;
  printf("\"%s\" inserted into the priority queue.\n", value);
}

char *delete(PriorityQueue *pq)
{
  if (isEmpty(pq))
  {
    printf("Priority Queue is empty. Cannot delete.\n");
    return NULL;
  }

  char *item = pq->items[0];
  for (int i = 0; i < pq->count - 1; i++)
  {
    strcpy(pq->items[i], pq->items[i + 1]);
  }
  pq->count--;

  printf("\"%s\" deleted from the priority queue.\n", item);
  return item;
}

char *peek(PriorityQueue *pq)
{
  if (isEmpty(pq))
  {
    printf("Priority Queue is empty. Nothing to peek.\n");
    return NULL;
  }
  return pq->items[0];
}

int main()
{
  PriorityQueue *pq = createQueue();
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
      fgets(input, sizeof(input), stdin);
      input[strcspn(input, "\n")] = '\0';
      insert(pq, input);
      break;
    case 2:
      delete (pq);
      break;
    case 3:
      printf("Highest priority element is \"%s\"\n", peek(pq));
      break;
    case 4:
      if (isEmpty(pq))
      {
        printf("Priority Queue is empty.\n");
      }
      else
      {
        printf("Priority Queue is not empty.\n");
      }
      break;
    case 5:
      if (isFull(pq))
      {
        printf("Priority Queue is full.\n");
      }
      else
      {
        printf("Priority Queue is not full.\n");
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

  free(pq);
  return 0;
}