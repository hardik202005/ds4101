// 20. Trapping Rain Water Problem: Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Explanation -

// // Input: height = [0,1,0,2,1,0,1,3,2,1,2,1] Output: 6 Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

// formula=mathmin(left[i]-right[i])-a[i]

#include <stdio.h>
#include <conio.h>
#include <limits.h>

int max(int x, int y)
{
  return (x > y) ? x : y;
}

int min(int x, int y)
{
  return (x < y) ? x : y;
}

int trap(int bars[], int n)
{
  if (n <= 2)
  {
    return 0;
  }

  int water = 0;
  int left[n - 1];
  left[0] = INT_MIN;

  for (int i = 1; i < n - 1; i++)
  {
    left[i] = max(left[i - 1], bars[i - 1]);
  }

  int right = INT_MIN;
  for (int i = n - 2; i >= 1; i--)
  {
    right = max(right, bars[i + 1]);
    if (min(left[i], right) > bars[i])
    {
      water += min(left[i], right) - bars[i];
    }
  }

  return water;
}

int main(void)
{
  int heights[100] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int n = sizeof(heights) / sizeof(heights[0]);

  printf("The maximum amount of water that can be trapped is %d",
         trap(heights, n));

  return 0;
}
