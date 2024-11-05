// FIND THE LARGEST ELEMENT IN THE INTEGER ARRAY USING RECURSION.

#include <stdio.h>
#define arrSize 100
int largest(int *arr, int large, int curr, int size)
{

  if (arr[curr] > arr[large])
  {
    large = curr;
  }
  if (curr < (size - 1))
  {
    return largest(arr, large, curr + 1, size);
  }
  return arr[large];
}
int main()
{
  int arr[arrSize];
  int size;
  printf("ENTER ARRAY SIZE : ");
  scanf("%d", &size);
  for (int i = 0; i < size; i++)
  {
    printf("ENTER ARRAY ELEMENT : ");
    scanf("%d", &arr[i]);
  }
  printf("THE LARGEST ELEMENT IN ARRAY : %d", largest(arr, 0, 0, size));

  return 0;
}