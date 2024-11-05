//  CALCULATE FACTORIAL OF A NUMBER USING RECURSION

#include <stdio.h>
#include <conio.h>

int factorital(int number);
// int fact=0;
int main()
{
  int number;
  printf("enter the number:");
  scanf("%d", &number);
  int facts = factorital(number);
  printf("factorial of number %d is:%d", number, facts);
  return 0;
}

int factorital(int number)
{
  int fact = 0;
  if (number == 1)
  {
    return 1;
  }

  else
  {
    fact = number * factorital(number - 1);
  }

  return fact;
}