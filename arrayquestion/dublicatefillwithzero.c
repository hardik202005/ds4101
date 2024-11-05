//  Enter an array from user and remove the duplicate values and fill with zero?

#include <stdio.h>
#include <conio.h>

int main()
{
  int array[100];
  int size, i;

  printf("enter the size:");
  scanf("%d", &size);

  for (i = 0; i < size; i++)
  {
    printf("ENTER ELEMENT %d : ", i);
    scanf("%d", &array[i]);
  }

  dublicate(array, size);
  return 0;
}

int dublicate(int array[], int size[])
{
  int zero;
  for (int i = 0; i < size; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      if (array[i] == array[j])
      {
        array[i] = zero;
        array[j] = zero;
      }
    }
  }

  for (int i = 0; i < size; i++)
  {
    printf("%d\n", array[i]);
  }
  return 0;
}