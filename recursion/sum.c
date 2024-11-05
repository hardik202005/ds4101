// 3. CALCULATE THE SUM OF NATURAL NUMBERS TILL 10 USING RECURSION.

#include <stdio.h>
#include <conio.h>
int sum(int number);
// int fact=0;
int main()
{
  int number;
  printf("enter the number:");
  scanf("%d", &number);
  int facts = sum(number);
  printf("sum of number %d is:%d", number, facts);
  return 0;
}

int sum(int number)
{
  int fact = 0;
  if (number == 1)
  {
    return 1;
  }

  else
  {
    fact = number + sum(number - 1);
  }

  return fact;
}