#include <stdio.h>
#define maxSize 100
// inserts element from unsorted array to sorted array at its correct place
void insertionSort(int arr[], int size, int i, int j, int temp)
{
  printf("\n");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  if (j < size)
  {
    if ((arr[i] > temp) && (i > 0))
    {
      arr[i + 1] = arr[i];
      insertionSort(arr, size, i - 1, j, temp);
    }
    else
    {
      arr[i] = temp;
      insertionSort(arr, size, j - 1, j, arr[j]);
    }
  }
}
int main()
{
  int arr[maxSize];
  int size;
  printf("ENTER SIZE OF ARRAY : ");
  scanf("%d", &size);
  for (int i = 0; i < size; i++)
  {
    printf("ENTER ARRAY ELEMENT : ");
    scanf("%d", &arr[i]);
  }
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  insertionSort(arr, size, 0, 1, arr[1]);
  printf("\n");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }

  return 0;
}