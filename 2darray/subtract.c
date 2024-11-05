// Enter two Matrices from user, subtract the matrices and display the answer?

#include <stdio.h>
#include <conio.h>

int main()
{
  int matrix1[2][2];
  int matrix2[2][2];
  int sub[2][2];
  int i, j;

  printf("Enter the Matrix elements:\n");

  for (i = 0; i < 2; i++)
  {
    for (j = 0; j < 2; j++)
    {
      scanf("%d", &matrix1[i][j]);
    }
  }

  for (i = 0; i < 2; i++)
  {
    for (j = 0; j < 2; j++)
    {
      scanf("%d", &matrix2[i][j]);
    }
  }

  for (i = 0; i < 2; i++)
  {
    for (j = 0; j < 2; j++)
    {
      sub[i][j] = matrix1[i][j] - matrix2[i][j];
    }
  }

  printf("subtract matrix element:\n");
  for (i = 0; i < 2; i++)
  {
    printf("[");
    for (j = 0; j < 2; j++)
    {
      printf(" %d", sub[i][j]);
    }
    printf("]");
    printf("\n");
  }
}
