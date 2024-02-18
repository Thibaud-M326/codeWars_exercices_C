#include <stddef.h>

int count_jumps (size_t length, const int array[length])
{ 
  int jumps;
  int i;
  jumps = 0;
  i = 0;
  
  while(i < length && i >= 0)
  {
      if(jumps > length)
      {
          return -1;
      }
      i += array[i];
      jumps++;
  }
	return jumps;
}