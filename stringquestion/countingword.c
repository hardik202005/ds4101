// ENTER A SENTENCE FROM USER AND THEN ENTER THE WORD AND COUNT THE OCCURENCE OF THAT WORD IN THE SENTENCE
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

int main()
{
  char str[MAX_SIZE];
  char toSearch[MAX_SIZE];
  int count;

  printf("enter the string: ");
  gets(str);
  printf("enter word to search occurrences: ");
  gets(toSearch);

  count = countOccurrences(str, toSearch);

  printf("Total occurrences of '%s': %d", toSearch, count);

  return 0;
}

int countOccurrences(char *str, char *toSearch)
{
  int i, j, found, count;
  int stringLen, searchLen;

  stringLen = strlen(str);
  searchLen = strlen(toSearch);

  count = 0;

  for (i = 0; i <= stringLen - searchLen; i++)
  {
    found = 1;
    for (j = 0; j < searchLen; j++)
    {
      if (str[i + j] != toSearch[j])
      {
        found = 0;
        break;
      }
    }

    if (found == 1)
    {
      count++;
    }
  }

  return count;
}