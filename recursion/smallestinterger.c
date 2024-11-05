// 6. FIND THE SMALLEST ELEMENT IN THE INTEGER ARRAY USING RECURSION.
#include <stdio.h>
#define arrSize 100
int smallest(int *arr, int small, int curr, int size)
{

  if (arr[curr] < arr[small])
  {
    small = curr;
  }
  if (curr < (size - 1))
  {
    return smallest(arr, small, curr + 1, size);
  }
  return arr[small];
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
  printf("THE SMALLEST ELEMENT IN ARRAY : %d", smallest(arr, 0, 0, size));

  return 0;
}
