#include <stdio.h>
typedef unsigned long long ull;

ull even_fib(ull limit) {
  ull fiba;
  ull fibb;
  ull temp;
  ull even_f;
  
  fiba = 0;
  fibb = 1;
  temp = 0;
  even_f = 0;
  while(fibb < limit)
  {
    temp = fiba;
    fiba = fibb;
    fibb = temp + fibb;
    if(fibb % 2 == 0 && fibb < limit)
    {
      even_f = even_f + fibb;
    }
  }
  return even_f;
}