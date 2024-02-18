#include <stdlib.h>
#include <stdio.h>

void sort_array(size_t n, int arr[n]) {
  int i;
  int j;
  int temp;
  
  printf("%d", n);
  
  i = 0;
  j = 0;
  while(i < n - 1)
  {
    j = i + 1;
    while(j < n)
    {
      if(arr[j] < arr[i] 
         && arr[j] % 2 != 0
         && arr[i] % 2 != 0)
      {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
      j++;   
    }
    i++;
  }
}