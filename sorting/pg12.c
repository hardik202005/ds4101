#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 100

void swap(char *a, char *b)
{
  char temp[MAX_STR_LEN];
  strcpy(temp, a);
  strcpy(a, b);
  strcpy(b, temp);
}

void selectionSortRecursive(char arr[][MAX_STR_LEN], int n, int start)
{
  if (start >= n - 1)
    return;

  int min_idx = start;
  for (int i = start + 1; i < n; i++)
  {
    if (strcmp(arr[i], arr[min_idx]) < 0)
    {
      min_idx = i;
    }
  }

  swap(arr[min_idx], arr[start]);

  selectionSortRecursive(arr, n, start + 1);
}

void printArray(char arr[][MAX_STR_LEN], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%s ", arr[i]);
  }
  printf("\n");
}

int main()
{
  int n;
  printf("Enter the number of strings: ");
  scanf("%d", &n);

  char(*arr)[MAX_STR_LEN] = malloc(n * sizeof(*arr));
  if (arr == NULL)
  {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
  }

  printf("Enter %d strings:\n", n);
  for (int i = 0; i < n; i++)
  {
    scanf("%s", arr[i]);
  }

  clock_t start = clock();

  selectionSortRecursive(arr, n, 0);

  clock_t end = clock();
  double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

  printf("Sorted strings: ");
  printArray(arr, n);
  printf("Time taken for recursive selection sort: %f seconds\n", time_taken);

  free(arr);

  return 0;
}