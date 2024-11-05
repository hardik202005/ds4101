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

  printf("display array:");
  for (i = 0; size > i; i++)
  {
    printf("%d\n", array[i]);
  }
}
