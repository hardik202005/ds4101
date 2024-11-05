#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
  int len1, len2;

  char str1[100];
  char str2[100];

  printf("enter the string1:");
  scanf("%s", str1);

  printf("enter the string2:");
  scanf("%s", str2);

  len1 = strlen(str1);
  len2 = strlen(str2);

  if (len1 == len2)
  {
    printf("equal");
  }

  else
  {
    printf("not equal");
  }

  return 0;
}