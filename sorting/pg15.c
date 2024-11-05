#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 100

void insertionSort(char arr[][MAX_STR_LEN], int n)
{
  for (int i = 1; i < n; i++)
  {
    char key[MAX_STR_LEN];
    strcpy(key, arr[i]);

    int j = i - 1;

    while (j >= 0 && strcmp(arr[j], key) > 0)
    {
      strcpy(arr[j + 1], arr[j]);
      j--;
    }
    strcpy(arr[j + 1], key);
  }
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

  insertionSort(arr, n);

  clock_t end = clock();
  double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

  printf("Sorted strings: ");
  printArray(arr, n);
  printf("Time taken for iterative insertion sort: %f seconds\n", time_taken);

  free(arr);

  return 0;
}