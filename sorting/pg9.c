#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j < high; j++)
  {
    if (arr[j] <= pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quickSortIterative(int arr[], int n)
{
  int *stack = (int *)malloc(n * sizeof(int));
  int top = -1;

  stack[++top] = 0;
  stack[++top] = n - 1;

  while (top >= 0)
  {

    int high = stack[top--];
    int low = stack[top--];

    int pivotIndex = partition(arr, low, high);

    if (pivotIndex - 1 > low)
    {
      stack[++top] = low;
      stack[++top] = pivotIndex - 1;
    }

    if (pivotIndex + 1 < high)
    {
      stack[++top] = pivotIndex + 1;
      stack[++top] = high;
    }
  }

  free(stack);
}

void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main()
{
  int n;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  int *arr = (int *)malloc(n * sizeof(int));
  printf("Enter %d integers:\n", n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  clock_t start = clock();

  quickSortIterative(arr, n);

  clock_t end = clock();
  double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

  printf("Sorted array: ");
  printArray(arr, n);
  printf("Time taken for iterative quick sort: %f seconds\n", time_taken);

  free(arr);

  return 0;
}