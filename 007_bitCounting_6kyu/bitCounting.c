#include <stddef.h>

size_t countBits(unsigned value)
{
  int rest;
  int bits;
  
  rest = 0;
  bits = 0;
  while(value != 0)
  {
    rest = value % 2;
    value /= 2;
    if(rest == 1)
    {
      bits++; 
    }
  }
	return bits;
}