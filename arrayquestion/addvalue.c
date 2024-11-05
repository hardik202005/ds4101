// 10. Enter an array from user and add all values ?

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

  int total = add(array, size);
  printf("adding array:%d", total);

  return 0;
}

int add(int array[], int size)
{
  int total = 0;
  for (int i = 0; i < size; i++)
  {
    total = array[i] + total;
  }

  return total;
}
