#include <stdio.h>

#define ROWS1 4
#define COLS1 2
#define ROWS2 2
#define COLS2 3

int main()
{
  int matrix1[ROWS1][COLS1], matrix2[ROWS2][COLS2], product[ROWS1][COLS2];

  printf("Enter the elements of the first matrix (%d rows and %d columns):\n", ROWS1, COLS1);
  for (int i = 0; i < ROWS1; i++)
  {
    for (int j = 0; j < COLS1; j++)
    {
      printf("Element [%d][%d]: ", i, j);
      scanf("%d", &matrix1[i][j]);
    }
  }

  printf("\nEnter the elements of the second matrix (%d rows and %d columns):\n", ROWS2, COLS2);
  for (int i = 0; i < ROWS2; i++)
  {
    for (int j = 0; j < COLS2; j++)
    {
      printf("Element [%d][%d]: ", i, j);
      scanf("%d", &matrix2[i][j]);
    }
  }

  for (int i = 0; i < ROWS1; i++)
  {
    for (int j = 0; j < COLS2; j++)
    {
      product[i][j] = 0;
    }
  }

  for (int i = 0; i < ROWS1; i++)
  {
    for (int j = 0; j < COLS2; j++)
    {
      for (int k = 0; k < COLS1; k++)
      {
        product[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }

  printf("\nThe product of the two matrices is:\n");
  for (int i = 0; i < ROWS1; i++)
  {
    for (int j = 0; j < COLS2; j++)
    {
      printf("%d ", product[i][j]);
    }
    printf("\n");
  }

  return 0;
}