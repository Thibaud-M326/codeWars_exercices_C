#include <stddef.h> // NULL
#include <stdio.h>
#include <stdlib.h>

int ft_find_size_plus_space_needed(const char *camelCase)
{
  int c;
  int i;

  c = 0;
  i = 0;
  while(camelCase[i] != '\0')
  {
    if(camelCase[i] >= 65 && camelCase[i] <= 90)
    {
      c += 2;
      i++;
    }
    else
    {
      c++;
      i++;
    }
  }
  return c; 
}

//returned buffer should be dynamically allocated and will be freed by a caller
char* solution(const char *camelCase) { 
  int i;
  int j;
  int c;
  char *breakCamel = ""; 
  
  i = 0;
  j = 0;
  c = ft_find_size_plus_space_needed(camelCase);
  c += 1; //for '\0'
  breakCamel = (char*) malloc(c * sizeof(char));
  while(camelCase[i] != '\0')
  {
    if(camelCase[i] >= 65 && camelCase[i] <= 90)
    {
      breakCamel[j] = ' ';
      j++;
    }
    breakCamel[j] = camelCase[i];
    j++;
    i++;
  }
  breakCamel[j] = '\0';
  return breakCamel;
}