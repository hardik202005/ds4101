#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {

        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
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

  bubbleSort(arr, n);

  clock_t end = clock();
  double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

  printf("Sorted array: ");
  printArray(arr, n);
  printf("Time taken for bubble sort: %f seconds\n", time_taken);

  free(arr);

  return 0;
}