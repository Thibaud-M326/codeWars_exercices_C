#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//  return a dynamically allocated array
//  assign the length of this array to *z
//  memory will be freed by the test suite

void ft_count(const int *arr1, size_t n1, const int *arr2, size_t n2, size_t *z)
{
  unsigned long i;
  unsigned long j;
  int size;
  bool present;
  
  i = 0;
  j = 0;
  size = 0;
  present = false;
  
  while(i < n1)
  {
    while(j < n2 && present == false)
    {
      if(arr1[i] == arr2[j])
      {
        present = true;
      }
      j++;
    }
    if(present == false)
    {
      size++;
    }
    present = false;
    j = 0;
    i++;
  }
  
  *z = size;
}

int *array_diff(const int *arr1, size_t n1, const int *arr2, size_t n2, size_t *z) {
  int i;
  int j;
  int k;
  int *arr3;
  bool present;
  
  i = 0;
  j = 0;
  k = 0;
  present = false;
  ft_count(arr1, n1, arr2, n2, z);
  arr3 = (int *) malloc(*z * sizeof(int));
  
  while(i < n1)
  {
    while(j < n2 && present == false)
    {
      if(arr1[i] == arr2[j])
      {
        present = true;
      }
      j++;
    }
    if(present == false)
    {
      arr3[k] = arr1[i];
      k++;
    }
    present = false;
    j = 0;
    i++;
  }
  
  int u;
  u = 0;
  printf("*z : %zu\n", *z);
  printf("arr3 : ");
  while(u < *z)
  {
    printf("%d ", arr3[u]);
    u++;
  }
  
  printf("\nend\n-----\n");
  return arr3;
}