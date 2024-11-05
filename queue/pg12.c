#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 100

typedef struct
{
  char **array;
  int capacity;
  int size;
} PriorityQueue;

PriorityQueue *createPriorityQueue(int capacity)
{
  PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
  pq->capacity = capacity;
  pq->size = 0;
  pq->array = (char **)malloc(capacity * sizeof(char *));
  for (int i = 0; i < capacity; i++)
  {
    pq->array[i] = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
  }
  return pq;
}

bool isEmpty(PriorityQueue *pq)
{
  return pq->size == 0;
}

bool isFull(PriorityQueue *pq)
{
  return pq->size == pq->capacity;
}

void insert(PriorityQueue *pq, const char *value)
{
  if (isFull(pq))
  {
    printf("Priority Queue is full. Cannot insert \"%s\".\n", value);
    return;
  }

  strcpy(pq->array[pq->size], value);
  pq->size++;

  for (int i = pq->size - 1; i > 0; i--)
  {
    if (strcmp(pq->array[i], pq->array[(i - 1) / 2]) > 0)
    {

      char temp[MAX_STRING_LENGTH];
      strcpy(temp, pq->array[i]);
      strcpy(pq->array[i], pq->array[(i - 1) / 2]);
      strcpy(pq->array[(i - 1) / 2], temp);
    }
    else
    {
      break;
    }
  }
}

char *deleteMax(PriorityQueue *pq)
{
  if (isEmpty(pq))
  {
    printf("Priority Queue is empty. Cannot delete.\n");
    return NULL;
  }

  char *maxValue = pq->array[0];
  pq->size--;
  strcpy(pq->array[0], pq->array[pq->size]);

  int i = 0;
  while (i < pq->size / 2)
  {
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    int largerChild = leftChild;

    if (rightChild < pq->size && strcmp(pq->array[rightChild], pq->array[leftChild]) > 0)
    {
      largerChild = rightChild;
    }

    if (strcmp(pq->array[i], pq->array[largerChild]) < 0)
    {

      char temp[MAX_STRING_LENGTH];
      strcpy(temp, pq->array[i]);
      strcpy(pq->array[i], pq->array[largerChild]);
      strcpy(pq->array[largerChild], temp);
      i = largerChild;
    }
    else
    {
      break;
    }
  }

  printf("\"%s\" deleted from the priority queue.\n", maxValue);
  return maxValue;
}

char *peekMax(PriorityQueue *pq)
{
  if (isEmpty(pq))
  {
    printf("Priority Queue is empty. Nothing to peek at.\n");
    return NULL;
  }
  return pq->array[0];
}

int main()
{
  int capacity = 10;
  PriorityQueue *pq = createPriorityQueue(capacity);
  int choice;
  char input[MAX_STRING_LENGTH];

  do
  {
    printf("\n1. Insert\n2. Delete Max\n3. Peek Max\n4. Check if Empty\n5. Check if Full\n6. Exit\n");
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
      deleteMax(pq);
      break;
    case 3:
      printf("Max element is \"%s\"\n", peekMax(pq));
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

  for (int i = 0; i < pq->capacity; i++)
  {
    free(pq->array[i]);
  }
  free(pq->array);
  free(pq);
  return 0;
}