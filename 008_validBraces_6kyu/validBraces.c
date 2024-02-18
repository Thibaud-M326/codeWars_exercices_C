#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int ft_length(const char* string)
{
  int c;
  int i;
  
  c = 0;
  i = 0;
  while(string[c] != '\0')
  {
    c++;
  }  
  return c;
}

void ft_copy(const char* string, char* copy)
{
  int i;
  
  i = 0;
  while(string[i] != '\0')
  {
    copy[i] = string[i];
    i++;
  }
  copy[i] = '\0';
}

int ft_search(char* copy, int i, char c)
{
  int j;
  bool search;
  
  j = i + 1;
  search = false;
  while(copy[j] == 'a' || copy[j] == c)
  {
    if(copy[j] == c)
    {
      copy[i] = 'a';
      copy[j] = 'a';
      search = true;
      return search;
    }
    j++;
  }
  return search;
}

bool valid_braces (const char* braces)
{
  char* copy = "";
  int length;
  int i;
  bool valid;
  bool search;
  
  length = ft_length(braces);
  copy = (char *)malloc(length * sizeof(char) + 1);
  i = 0;
  valid = true;
  search = false;
  ft_copy(braces, copy);
  while(copy[i] != '\0')
  {
    if(copy[i] == '('
    || copy[i] == '{'
    || copy[i] == '[')
    {
      if(copy[i] == '(')
      {
        search = ft_search(copy, i, ')');
        if(search == true)
        {
          i = 0;
          search = false;
        }
        else
        {
          i++;
        }
      }
      else if(copy[i] == '{')
      {
        search = ft_search(copy, i, '}');
        if(search == true)
        {
          i = 0;
          search = false;
        }
        else
        {
          i++;
        }
      }
      else if(copy[i] == '[')
      {
        search = ft_search(copy, i, ']');
        if(search == true)
        {
          i = 0;
          search = false;
        }
        else
        {
          i++;
        }
      }
    }
    else
    {
      i++;
    }
  }
  
  i = 0;
  while(copy[i] != '\0')
  {
    if(copy[i] != 'a')
    {
      valid = false;
    }
    i++;
  }
  return valid;
}