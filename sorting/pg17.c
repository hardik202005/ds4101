//  ENTER A STRING ARRAY FROM THE USER AND PERFORM MERGE SORT ALGORITHM THROUGH ITERATION. ALSO CALCULATE THE WORST AND BEST COMPLEXITY WITH EXACT TIME.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 100

void merge(char arr[][MAX_STR_LEN], int left, int mid, int right)
{
  int n1 = mid - left + 1;
  int n2 = right - mid;

  char(*L)[MAX_STR_LEN] = malloc(n1 * sizeof(*L));
  char(*R)[MAX_STR_LEN] = malloc(n2 * sizeof(*R));

  for (int i = 0; i < n1; i++)
  {
    strcpy(L[i], arr[left + i]);
  }
  for (int j = 0; j < n2; j++)
  {
    strcpy(R[j], arr[mid + 1 + j]);
  }

  int i = 0, j = 0, k = left;

  while (i < n1 && j < n2)
  {
    if (strcmp(L[i], R[j]) <= 0)
    {
      strcpy(arr[k], L[i]);
      i++;
    }
    else
    {
      strcpy(arr[k], R[j]);
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    strcpy(arr[k], L[i]);
    i++;
    k++;
  }

  while (j < n2)
  {
    strcpy(arr[k], R[j]);
    j++;
    k++;
  }

  free(L);
  free(R);
}

void mergeSort(char arr[][MAX_STR_LEN], int n)
{
  for (int size = 1; size < n; size *= 2)
  {
    for (int left = 0; left < n; left += 2 * size)
    {
      int mid = left + size - 1;
      int right = left + 2 * size - 1;

      if (mid >= n)
        break;
      if (right >= n)
        right = n - 1;

      merge(arr, left, mid, right);
    }
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

  mergeSort(arr, n);

  clock_t end = clock();
  double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

  printf("Sorted strings: ");
  printArray(arr, n);
  printf("Time taken for iterative merge sort: %f seconds\n", time_taken);

  free(arr);

  return 0;
}