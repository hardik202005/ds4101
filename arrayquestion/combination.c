// 14. Enter an array from user and print all possible combinations of the elements?

#include <stdio.h>
void getArr(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("ENTER ELEMENT %d : ", i);
    scanf("%d", arr + i);
  }
}


void display(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
void printCombination(int arr[], int size)
{
  int j, k;
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < i; j++)
    {
      printf("%d ", arr[j]);
    }
    for (int k = i; k < size; k++)
    {
      printf("%d ", arr[k]);
    }
    printf("\n");
  }
}
int main()
{
  int arr[100];
  int size;
  printf("ENTER SIZE : ");
  scanf("%d", &size);
  getArr(arr, size);
  printCombination(arr, size);
  return 0;
}