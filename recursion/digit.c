// ENTER THE NUMBER FROM THE USER AND ADD ALL DIGITS OF THE NUMBER USING RECURSION.

#include <stdio.h>
int sumDigit(int num)
{
  if (num > 0)
  {
    return (num % 10) + sumDigit(num / 10);
  }
  return 0;
}
int main()
{
  int num;
  printf("ENTER A NUMBER : ");
  scanf("%d", &num);
  printf("SUM OF DIGITS OF %d : %d", num, sumDigit(num));
  return 0;
}