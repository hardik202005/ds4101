// 15. Enter an array from user and print all the palindrome numbers?

#include <stdio.h>
#include <conio.h>

int main()
{
  int array[100];
  int size;
  int n;
  int s = 0, j, t;

  printf("enter the size of array:");
  scanf("%d", &size);

  for (int i = 0; i < size; i++)
  {
    printf("enter element%d:", i);
    scanf("%d", &array);
  }

  for (int i = 0; i < size; i++)
  {
    n = array[i];

    while (n > 0)
    {
      t = n % 10;
      s = s * 10 + t;
      n = n / 10;
    }

    if (s == array[i])
    {
      printf("\n %d is palindrome", array[i]);
    }
  }
  return 0;
}
