#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
  char str[100];
  int len = 0;
  int j = 0;

  printf("ENTER THE STRING=");
  gets(str);

  while (str[j] != 0)
  {
    if (str[j] == 32)
    {
      continue;
    }
    len++;
    j++;
  }

  printf(" THE LENGTH OF STRING IS=%d", len);

  return 0;
}