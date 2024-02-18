#include <stddef.h>

void move_zeros(size_t len, int arr[len])
{
    size_t i;
    size_t j;
    int temp;
    int count_zero;
  
    i = 0;
    j = 0;
    count_zero = 0;
    temp = 0;
    while(i < len)
    {
      if(arr[i] == 0)
      {
        count_zero++;
      }
      i++;
    }
    i = 0;
    while(i < len - count_zero)
    {
      if(arr[i] == 0)
      {
        j = i; 
        while(j < len - 1)
        {
          temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
          j++;
        }
        i--;
      }
      i++;
    }
}