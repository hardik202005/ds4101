//  19. Find the local maxima in the array? (An element in an array is a local maxima if it greater than the element after it, and the element before it)

#include <stdio.h>
#include <conio.h>

int main()
{
  int i, size;
  int array[100];

  printf("enter the size of array:");
  scanf("%d", &size);

  for (i = 0; i < size; i++)
  {
    printf("the element of %d:", i);
    scanf("%d", &array[i]);
  }

  for (int i = 1; i < (size - 1); i++)
  {
    if ((array[i] > array[i - 1]) && (array[i] > array[i + 1]))
    {
      printf("%d at %d index is a local minima\n", array[i], i);
    }
  }
  return 0;
}