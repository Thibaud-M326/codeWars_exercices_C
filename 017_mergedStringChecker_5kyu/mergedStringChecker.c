#include <stdbool.h>

bool recursive_merge(const char *s, const char *part1, const char *part2, int i, int j, int k)
{
  bool merge;
  
  merge = false;
  while(s[i] != '\0')
  {
    if(part1[j] == part2[k])
    {
      merge = recursive_merge(s, part1, part2, i + 1, j, k + 1); 
      if(merge == true)
      {
        return merge;
      }
    }
    if(s[i] == part1[j])
    {
      j++; 
    }
    else if(s[i] == part2[k])
    {
      k++; 
    }
    i++;   
  }
  
  if(part1[j] == '\0'
  && part2[k] == '\0')
  {
    merge = true;
  }
  
  return merge;
}

bool is_merge (const char *s, const char *part1, const char *part2)
{
  int i;
  int j;
  int k;
  bool merge;
  
  i = 0;
  j = 0;
  k = 0;
  merge = recursive_merge(s, part1, part2, i, j, k); 
  
	return merge;
}