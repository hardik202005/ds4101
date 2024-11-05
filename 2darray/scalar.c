// 6. Enter the Matrix from user, multiply it with a scalar value and display the answer?
#include <stdio.h>
#define rows 100
#define cols 100
void getMat(int r, int c, int mat[rows][cols])
{
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      printf("Enter array element [%d][%d] : ", i, j);
      scanf("%d", &mat[i][j]);
    }
  }
}
void printMat(int r, int c, int mat[rows][cols])
{
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
}
void scalarMul(int r, int c, int mat[rows][cols], int val)
{
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      printf("%d ", mat[i][j] * val);
    }
    printf("\n");
  }
}
int main()
{
  int mat[rows][cols];
  int r, c, val;
  printf("ENTER DIMENSIONS OF MATRIX\n");
  printf("Enter number of rows : ");
  scanf("%d", &r);
  printf("Enter number of columns : ");
  scanf("%d", &c);
  printf("Enter value to be multiplied : ");
  scanf("%d", &val);
  getMat(r, c, mat);
  printf("ORIGINAL MATRIX\n");
  printMat(r, c, mat);
  printf("AFTER SCALAR MULTIPLICATION\n");
  scalarMul(r, c, mat, val);
  return 0;
}