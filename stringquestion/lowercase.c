#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
  int i, len;
  char str[100];
  printf("enter the string");
  scanf("%s", str);

  len = strlen(str);

  for (i = 0; i <= len; i++)
  {
    if (str[i] >= 65 && str[i] <= 90)
    {
      str[i] = str[i] + 32;
    }
  }

  printf("string in lowecase:%s", str);
  return 0;
}