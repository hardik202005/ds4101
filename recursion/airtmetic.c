// 8. FIND THE ARITHMETIC MEAN OF AN INTEGER ARRAY USING RECURSION.
#include <stdio.h>
#define arrSize 100
float am(int *arr, int curr, int size)
{
  if (curr < (size - 1))
  {
    return ((float)arr[curr] / (float)size) + am(arr, curr + 1, size);
  }
  return ((float)arr[curr] / (float)size);
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
  printf("THE ARITHMETIC MEAN OF ELEMENTS IN ARRAY : %f", am(arr, 0, size));
  return 0;
}
