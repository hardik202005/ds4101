//  Enter an array from user and copy the array into second array?

#include <stdio.h>
#include <conio.h>

int main()
{
  int array[100];
  int copyarray[100];
  int size, i;

  printf("enter the array:");
  scanf("%d", &size);

  for (i = 0; i < size; i++)
  {
    scanf("%d", &array[i]);
  }

  printf("copy  array is:");

  for (i = 0; i < size; i++)
  {
    copyarray[i] = array[i];
  }

  for (i = 0; i < size; i++)
  {
    printf("%d", copyarray[i]);
  }

  return 0;
}