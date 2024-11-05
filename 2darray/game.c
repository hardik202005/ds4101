// Create a tic tac toe game using 2D Arrays.

#define rows 3
#define cols 3
void printMat(char mat[rows][cols])
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      printf("%c ", mat[i][j]);
    }
    printf("\n");
  }
}
void setMat(char mat[rows][cols], char val)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      mat[i][j] = val;
    }
  }
}
int checkMat(char mat[rows][cols])
{
  if (mat[0][0] != ' ')
  {
    if (mat[0][1] == mat[0][0])
    {
      if (mat[0][2] == mat[0][0]) // r1
      {
        printf("%c wins !!!", mat[0][0]);
        return 1;
      }
    }
    else if (mat[1][0] == mat[0][0])
    {
      if (mat[2][0] == mat[0][0]) // c1
      {
        printf("%c wins !!!", mat[0][0]);
        return 1;
      }
    }
    else if (mat[1][1] == mat[0][0])
    {
      if (mat[2][2] == mat[0][0]) // d1
      {
        printf("%c wins !!!", mat[0][0]);
        return 1;
      }
    }
  }
  if (mat[0][1] != ' ')
  {
    if (mat[1][1] == mat[0][1])
    {
      if (mat[2][1] == mat[0][1]) // c2
      {
        printf("%c wins !!!", mat[0][1]);
        return 1;
      }
    }
  }
  if (mat[0][2] != ' ')
  {
    if (mat[1][2] == mat[0][2])
    {
      if (mat[2][2] == mat[0][2]) // c3
      {
        printf("%c wins !!!", mat[0][2]);
        return 1;
      }
    }
    else if (mat[1][1] == mat[0][2])
    {
      if (mat[0][2] == mat[2][0]) // d2
      {
        printf("%c wins !!!", mat[0][2]);
        return 1;
      }
    }
  }
  if (mat[1][0] != ' ')
  {
    if (mat[1][1] == mat[1][0])
    {
      if (mat[1][2] == mat[1][0]) // r2
      {
        printf("%c wins !!!", mat[1][0]);
        return 1;
      }
    }
  }
  if (mat[2][0] != ' ')
  {
    if (mat[2][1] == mat[2][0])
    {
      if (mat[2][2] == mat[2][0]) // r3
      {
        printf("%c wins !!!", mat[2][0]);
        return 1;
      }
    }
  }
  return 0;
}
int insertVal(char mat[rows][cols], int pos, char val)
{
  int r = pos / 3;
  int c = pos % 3;
  if (mat[r][c] == ' ')
  {
    mat[r][c] = val;
    return 1;
  }
  else
  {
    printf("Value already exists. Try other location \n");
    return 0;
  }
}
int main()
{
  char mat[rows][cols];
  int turn = 0, pos;
  setMat(mat, ' ');
  while (turn < 9)
  {
    printf("Enter position (0-8) : ");
    scanf("%d", &pos);
    if ((pos >= 0) && (pos <= 8))
    {
      if ((turn % 2) == 0)
      {
        if (insertVal(mat, pos, 'X'))
          turn++;
      }
      else
      {
        if (insertVal(mat, pos, 'O'))
          turn++;
      }
      printMat(mat);
      if (checkMat(mat))
        return 0;
    }
    else
    {
      printf("Invalid Move\n");
    }
  }
  printf("DRAW!!!");
}