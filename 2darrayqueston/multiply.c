//  Enter two Matrices from user, multiply the matrices and display the answe

#include <stdio.h>
#include <conio.h>

int main()
{
  int matrix1[2][2];
  int matrix2[2][2];
  int mul[2][2];
  int i, j, sum = 0;
  ;

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
      sum = 0;
      for (int k = 0; k < 2; k++)
      {
        sum = sum + (matrix1[i][k] * matrix2[k][j]);
      }
      mul[i][j] = sum;
    }
  }

  printf("mul matrix element:\n");
  for (i = 0; i < 2; i++)
  {
    printf("[");
    for (j = 0; j < 2; j++)
    {
      printf(" %d", mul[i][j]);
    }
    printf("]");
    printf("\n");
  }
}
