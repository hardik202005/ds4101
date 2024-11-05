//  Enter an array from user and print the number which is positive ?

#include <stdio.h>
#include <conio.h>

int main()
{
  int array[100];
  int size;
  int i;

  printf("enter the array:");
  scanf("%d", &size);

  for (i = 0; size > i; i++)
  {
    scanf("%d", &array[i]);
  }

  for (i = 0; size > i; i++)
  {
    if (array[i] > 0)
    {
      printf("postive number is:%d\n", array[i]);
    }
  }
}
