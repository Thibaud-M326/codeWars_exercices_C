#include <stddef.h>
#include <stdio.h>

int maxSequence(const int* array, size_t n) {
  int i;
  int j;
  int sum_m;
  int sum_c;
  
  i = 0;
  j = 0;
  sum_m = 0;
  sum_c = 0;
  if(n <= 0)
  {
    return 0;
  }
  while(i < n)
  {
    while(j < n)
    {
      sum_c += array[j];
      if(sum_c > sum_m)
      {
        sum_m = sum_c;
      }
      j++;
    }
    sum_c = 0;
    i++;
    j = i;
  }
  if(sum_m < 0)
  {
    return 0;
  }
  return sum_m;
}