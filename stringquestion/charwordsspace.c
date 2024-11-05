#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
  int i, character = 0, word = 0, line = 0;
  char str[100];
  printf("enter the string:");
  gets(str);

  for (i = 0; str[i] != '\0'; i++)
  {
    character = character + 1;

    if (str[i] == ' ' || str[i] == '.')
    {
      word = word + 1;

      if (str[i] == ' ')
      {
        character = character - 1;
      }
    }

    if (str[i] == '.')
    {
      line = line + 1;
      character = character - 1;
    }
  }
  printf("character=%d", character);
  printf("\n");
  printf("word=%d", word);
  printf("\n");
  printf("line=%d", line);
  return 0;
}