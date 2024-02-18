#include <stdio.h>

//  do not allocate memory for return string
//  assign the value to the pointer "result"

void ft_reverse(int i, int size, const char *sentence, char *result)
{
  printf("i : %d\n", i);
  printf("size : %d\n", size);
  int j;
  int k;
  
  j = size + i - 1; 
  k = i;
  while(sentence[j] != sentence[i - 1])
  {
    result[k] = sentence[j];
    k++;
    j--;
  }
}

void spin_words(const char *sentence, char *result) {
  int i;
  int j;
  int size;
  i = 0;
  while(sentence[i] != '\0')
  {
    result[i] = sentence[i];
    i++;
  }
  result[i] = '\0';
  
  i = 0;
  j = 0;
  size = 0;
  while(sentence[i] != '\0')
  {
    if((sentence[i] >= 65 && sentence[i] <= 90) 
    || (sentence[i] >= 97 && sentence[i] <= 122))
    {
      while((sentence[j] >= 65 && sentence[j] <= 90) 
      || (sentence[j] >= 97 && sentence[j] <= 122))
      {
        j++;
      }
      size = j - i;
      if(size >= 5)
      {
        ft_reverse(i, size, sentence, result);
      }
      i = j;
      j++;
    }
    else 
    {
      i++;
    }
  }
}