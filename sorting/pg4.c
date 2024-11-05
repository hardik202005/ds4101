#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSortRecursive(int arr[], int n)
{

  if (n == 1)
  {
    return;
  }

  for (int i = 0; i < n - 1; i++)
  {
    if (arr[i] > arr[i + 1])
    {

      int temp = arr[i];
      arr[i] = arr[i + 1];
      arr[i + 1] = temp;
    }
  }

  bubbleSortRecursive(arr, n - 1);
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

  bubbleSortRecursive(arr, n);

  clock_t end = clock();
  double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

  printf("Sorted array: ");
  printArray(arr, n);
  printf("Time taken for recursive bubble sort: %f seconds\n", time_taken);

  free(arr);

  return 0;
}