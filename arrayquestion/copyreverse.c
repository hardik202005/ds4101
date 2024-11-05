// Enter an array from user and copy it into another array in reverse order?
#include <conio.h>
#include <stdio.h>

int main()
{
  int n, i;

  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  int array1[n];
  int array2[n];

  printf("Enter %d elements:\n", n);
  for (i = 0; i < n; i++)
  {
    printf("Element %d: ", i + 1);
    scanf("%d", &array1[i]);
  }

  for (i = 0; i < n; i++)
  {
    array2[i] = array1[n - 1 - i];
  }

  printf("Original array:\n");
  for (i = 0; i < n; i++)
  {
    printf("%d ", array1[i]);
  }
  printf("\n");

  printf("Copied array in reverse order:\n");
  for (i = 0; i < n; i++)
  {
    printf("%d ", array2[i]);
  }
  printf("\n");

  return 0;
}