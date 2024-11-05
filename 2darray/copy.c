

// Enter a Matrix from user, copy it in another matrix of same size?

#include <stdio.h>
#include <conio.h>

int main()
{
  int matrix[2][2];
  int copymatrix[2][2];
  int i, j;

  printf("Enter the Matrix elements:\n");

  for (i = 0; i < 2; i++)
  {
    for (j = 0; j < 2; j++)
    {
      scanf("%d", &matrix[i][j]);
    }
  }

  for (i = 0; i < 2; i++)
  {
    for (j = 0; j < 2; j++)
    {
      copymatrix[i][j] = matrix[i][j];
    }
  }

  printf("matrix element\n");
  for (i = 0; i < 2; i++)
  {
    printf("[");
    for (j = 0; j < 2; j++)
    {
      printf(" %d", copymatrix[i][j]);
    }
    printf("]");
    printf("\n");
  }
}