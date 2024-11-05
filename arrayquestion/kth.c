#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return i + 1;
}

int quickSelect(int arr[], int low, int high, int k)
{
  if (low <= high)
  {
    int pi = partition(arr, low, high);

    if (pi == k)
    {
      return arr[pi];
    }
    else if (pi > k)
    {
      return quickSelect(arr, low, pi - 1, k);
    }
    else
    {
      return quickSelect(arr, pi + 1, high, k);
    }
  }
  return -1;
}

int main()
{
  int n, k;

  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  int array[n];

  printf("Enter %d elements:\n", n);
  for (int i = 0; i < n; i++)
  {
    printf("Element %d: ", i + 1);
    scanf("%d", &array[i]);
  }

  printf("Enter the value of k (1 to %d): ", n);
  scanf("%d", &k);

  if (k >= 1 && k <= n)
  {
    int kthSmallest = quickSelect(array, 0, n - 1, k - 1);
    printf("The %d-th smallest value is: %d\n", k, kthSmallest);
  }
  else
  {
    printf("Invalid value of k.\n");
  }

  return 0;
}