// ENTER THE STRING FROM THE USER, ALSO ENTER A CHARACTER AND PRINT THE INDEX OF THE CHARACTER IF IT IS EXIST IN THE STRING ELSE PRINT -1

#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
  int len, i, j;
  char str[100];
  char index;

  printf("enter the string:");
  scanf("%s", &str);
  printf("enter the index:");
  scanf("%c", &index);
  len = strlen(str);

  for (i = 0; i <= len; i++)
  {
    if (str[i] == str[index])
    {
      j++;
      break;
    }
  }

  if (j > 0)
  {
    printf("the character is present");
  }

  else
  {
    printf("-1");
  }
  return 0;
}