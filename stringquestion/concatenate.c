//  ENTER TWO STRINGS FROM USER AND CONCATENATE THOSE STRINGS IN ANOTHER STRING AND DISPLAY THE ANSWER?

#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
  char str1[100] = "hello";
  char str2[100] = "world";

  strcat(str1, str2);

  printf("Concatenated String: %s\n", str1);
  return 0;
}