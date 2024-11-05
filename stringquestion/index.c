#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
  int len, i;
  char str[100];
  int index;

  printf("enter the string:");
  scanf("%s", &str);
  printf("enter the index:");
  scanf("%d", &index);
  len = strlen(str);

  for (i = 0; i <= len; i++)
  {
    if (i == index)
    {
      printf("the character is:%c", str[i]);
    }
  }
  return 0;
}