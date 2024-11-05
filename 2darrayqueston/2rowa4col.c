// 1. Enter a matrix of 4 rows and 2 columns from the user display it in matrix format?

#include <stdio.h>
#include <conio.h>

int main()
{
  int matrix[4][2];
  int i, j;

  printf("Enter the Matrix elements:\n");

  for (i = 0; i < 4; i++)
  {
    for (j = 0; j < 2; j++)
    {
      scanf("%d", &matrix[i][j]);
    }
  }
  printf("matrix element\n");
  for (i = 0; i < 4; i++)
  {
    printf("[");
    for (j = 0; j < 2; j++)
    {
      printf(" %d", matrix[i][j]);
    }
    printf("]");
    printf("\n");
  }
}