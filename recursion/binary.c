// 4. CONVERT A NUMBER INTO BINARY USING RECURSION

#include <stdio.h>
#include <conio.h>
int binary(int num);

int main()
{
  int num;
  printf("enter the number:");
  scanf("%d", &num);
  printf("binary of %d:%d", num, binary(num));
}

int binary(int num)
{
  if ((num / 2) > 0)
  {
    return (num % 2) + (binary(num / 2) * 10);
  }
  else
  {
    return 1;
  }
}
