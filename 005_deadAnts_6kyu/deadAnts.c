#include <stdio.h>

ft_count_biggest_dead_part(int a, int n, int t)
{
  int biggest;
  if(a > n)
  {
    biggest = a;
  } 
  else
  {
    biggest = n;
  } 
  if(t > biggest)
  {
    biggest = t;
  }
  
  
  
  return biggest;
}

int deadAntCount(const char* ants)
{
  int i;
  int a;
  int n;
  int t;
  int dead_ants;
  
  i = 0;
  a = 0;
  n = 0;
  t = 0;
  dead_ants = 0;
  while(ants[i] != '\0')
  {
    if(ants[i] == 'a' && ants[i + 1] == 'n' && ants[i + 2] == 't')
    {
      i += 3;
    }
    else
    {
      if(ants[i] == 'a')
      {
        a++;
      }
      if(ants[i] == 'n')
      {
        n++; 
      }
      if(ants[i] == 't')
      {
        t++; 
      }
      i++;
    }
  }
  dead_ants = ft_count_biggest_dead_part(a, n, t);
  
  printf("%s\n", ants);
  printf("%d\n", a);
  printf("%d\n", n);
  printf("%d\n", t);
  printf("end\n\n");
  
  return dead_ants;
}