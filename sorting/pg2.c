#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void recursiveSelectionSort(int arr[], int n, int index)
{
  if (index >= n - 1)
  {
    return;
  }

  int minIndex = index;
  for (int j = index + 1; j < n; j++)
  {
    if (arr[j] < arr[minIndex])
    {
      minIndex = j;
    }
  }

  if (minIndex != index)
  {
    int temp = arr[index];
    arr[index] = arr[minIndex];
    arr[minIndex] = temp;
  }

  recursiveSelectionSort(arr, n, index + 1);
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

  recursiveSelectionSort(arr, n, 0);

  clock_t end = clock();
  double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

  printf("Sorted array: ");
  printArray(arr, n);
  printf("Time taken for recursive selection sort: %f seconds\n", time_taken);

  free(arr);

  return 0;
}