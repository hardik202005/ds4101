// 13. Enter an array from user and count the duplicate values?

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
  int count = 0;
  for (int i = 0; i < size; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      if (array[i] == array[j])
      {
        count++;
      }
    }
  }

  printf("dublicate values:%d", count);
  return 0;
}