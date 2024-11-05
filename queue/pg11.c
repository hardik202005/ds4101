#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
  int *array;
  int capacity;
  int size;
} PriorityQueue;

PriorityQueue *createPriorityQueue(int capacity)
{
  PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
  pq->capacity = capacity;
  pq->size = 0;
  pq->array = (int *)malloc(capacity * sizeof(int));
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

void insert(PriorityQueue *pq, int value)
{
  if (isFull(pq))
  {
    printf("Priority Queue is full. Cannot insert %d.\n", value);
    return;
  }

  pq->array[pq->size] = value;
  pq->size++;

  for (int i = pq->size - 1; i > 0; i--)
  {
    if (pq->array[i] > pq->array[(i - 1) / 2])
    {

      int temp = pq->array[i];
      pq->array[i] = pq->array[(i - 1) / 2];
      pq->array[(i - 1) / 2] = temp;
    }
    else
    {
      break;
    }
  }
}

int deleteMax(PriorityQueue *pq)
{
  if (isEmpty(pq))
  {
    printf("Priority Queue is empty. Cannot delete.\n");
    return -1;
  }

  int maxValue = pq->array[0];
  pq->size--;
  pq->array[0] = pq->array[pq->size];

  int i = 0;
  while (i < pq->size / 2)
  {
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    int largerChild = leftChild;

    if (rightChild < pq->size && pq->array[rightChild] > pq->array[leftChild])
    {
      largerChild = rightChild;
    }

    if (pq->array[i] < pq->array[largerChild])
    {
      // Swap
      int temp = pq->array[i];
      pq->array[i] = pq->array[largerChild];
      pq->array[largerChild] = temp;
      i = largerChild;
    }
    else
    {
      break;
    }
  }

  printf("%d deleted from the priority queue.\n", maxValue);
  return maxValue;
}

int peekMax(PriorityQueue *pq)
{
  if (isEmpty(pq))
  {
    printf("Priority Queue is empty. Nothing to peek at.\n");
    return -1;
  }
  return pq->array[0];
}

int main()
{
  int capacity = 10;
  PriorityQueue *pq = createPriorityQueue(capacity);
  int choice, value;

  do
  {
    printf("\n1. Insert\n2. Delete Max\n3. Peek Max\n4. Check if Empty\n5. Check if Full\n6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter an integer to insert: ");
      scanf("%d", &value);
      insert(pq, value);
      break;
    case 2:
      deleteMax(pq);
      break;
    case 3:
      printf("Max element is %d\n", peekMax(pq));
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

  free(pq->array);
  free(pq);
  return 0;
}