#include <stdio.h>

void ft_combination_display(int k, int ls[], int szls, int t, int *sum_m);
void ft_make_combination(int k, int ls[], int data[], int st, int end, int index, int *sum_m, int sum_c, int t);

int chooseBestSum(int t, int k, int ls[], int szls) {
    int *sum_m;
    int best_sum;
    
    sum_m = &best_sum;
    if(k > szls)
    {
      return -1;
    }
    ft_combination_display(k, ls, szls, t, sum_m);
    if(best_sum == 0)
    {
      return -1;
    }
    return best_sum;
}

void ft_combination_display(int k, int ls[], int szls, int t, int *sum_m)
{
  int data[k];
  int sum_c;
  
  sum_c = 0;
  ft_make_combination(k, ls, data, 0, szls - 1, 0, sum_m, sum_c, t);
}

void ft_make_combination(int k, int ls[], int data[], int st, int end, int index, int *sum_m, int sum_c, int t)
{
  int j;
  
  //base
  j = 0;
  if(index == k)
  {
    while(j < k)
    {
      sum_c += data[j];
      j++;
    }
    if(sum_c <= t && sum_c > *sum_m)
    {
      *sum_m = sum_c;
    }
  }
  //recursive
  for(int i = st; i <= end && end - i + 1 >= k - index; i++)
  {
    data[index] = ls[i];
    ft_make_combination(k, ls, data, i + 1, end, index + 1, sum_m, sum_c, t);
  }
}