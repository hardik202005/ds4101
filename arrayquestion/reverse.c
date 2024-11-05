#include <stdio.h>
#include <conio.h>

int main()
{
  int array[100];
  int size, i;

  printf("enter the array:");
  scanf("%d", &size);

  for (i = 0; i < size; i++)
  {
    scanf("%d", &array[i]);
  }

  printf("reverse array is:");

  for (int i = (size - 1); i >= 0; i--)
  {
    printf("%d ", array[i]);
  }

  return 0;
}