
// 16. Enter two arrays from the user and check they are same or not?
#include <stdio.h>
void getArr(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("ENTER ELEMENT %d : ", i);
    scanf("%d", arr + i);
  }
}
int checkEqual(int arr[], int size, int arr2[], int size2)
{
  if (size != size2)
  {
    return 0;
  }
  else
  {
    for (int i = 0; i < size; i++)
    {
      if (arr[i] != arr2[i])
      {
        return 0;
      }
    }
    return 1;
  }
}
int main()
{
  int arr[100];
  int arr2[100];
  int size, size2;
  printf("ENTER SIZE OF ARRAY 1 : ");
  scanf("%d", &size);
  printf("ENTER SIZE OF ARRAY 2 : ");
  scanf("%d", &size2);
  getArr(arr, size);
  getArr(arr2, size2);
  checkEqual(arr, size, arr2, size2) ? printf("Equal Array") : printf("Unequal Array");
  return 0;
}
