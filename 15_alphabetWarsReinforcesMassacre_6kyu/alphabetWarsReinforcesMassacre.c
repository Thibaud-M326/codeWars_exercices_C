#include <stdlib.h>
#include <stdio.h>
void ft_print_reinforces(const char* reinforces[], size_t nreinforce)
{
    size_t i;
    int j;
  
    i = 0;
    j = 0;
    while(i < nreinforce)
    {
      printf("%zu :", i);
      while(reinforces[i][j] != '\0')
      {
        printf("%c", reinforces[i][j]);
        j++;
      }
      printf("\n");
      j = 0;
      i++;
    }
    printf("\n");
}

void ft_print_airstrikes(const char* airstrikes[], size_t nairstrike)
{
    size_t i;
    int j;
  
    i = 0;
    j = 0;
    while(i < nairstrike)
    {
      printf("%zu :", i);
      while(airstrikes[i][j] != '\0')
      {
        printf("%c", airstrikes[i][j]);
        j++;
      }
      printf("\n");
      j = 0;
      i++;
    }
    printf("\n");
}

int ft_size(const char* reinforces[])
{
  int i;
  
  i = 0;
  while(reinforces[0][i] != '\0')
  {
    i++;
  }
  return i;
}

char** ft_copy_airstrikes(int size, char **airstrikes_copy, const char *airstrikes[], size_t nairstrike)
{
    int i;
    int j;
  
    i = 0;
    j = 0;
    airstrikes_copy = (char **) malloc(nairstrike * sizeof(char *));
  
    while(i < nairstrike)
    {
      airstrikes_copy[i] = (char *) malloc(size * sizeof(char));
      i++;
    }
  
    i = 0;
    while(i < nairstrike)
    {
      while(j < size)
      {
        airstrikes_copy[i][j] = '.'; 
        j++;
      }
      j = 0;
      i++;
    }
    i = 0;
    j = 0;
    while(i < nairstrike)
    {
      while(airstrikes[i][j] != '\0')
      {
        if(airstrikes[i][j] == ' ')
        {
          airstrikes_copy[i][j] = '.'; 
        }
        else
        {
          airstrikes_copy[i][j] = airstrikes[i][j]; 
        }
        j++;
      }
      j = 0;
      i++;
    }
    return airstrikes_copy;
}

int* ft_init_int_tab(int size, int *tab)
{
    int i;
  
    i = 0;
    tab = (int *) malloc(size * sizeof(int));
    if(tab == NULL)
    {
      printf("no memory");
    }
    while(i < size)
    {
      tab[i] = 0;
      i++;
    }
    return tab;
}

void ft_print_int_tab(int size, int *tab)
{
    int i;
  
    i = 0;
    while(i < size)
    {
      printf("%d", tab[i]);
      i++;
    }
}

char* ft_init_char_tab(int size, char *tab)
{
    int i;
  
    i = 0;
    tab = (char *) malloc(size * sizeof(char) + 1);
    if(tab == NULL)
    {
      printf("no memory");
    }
    while(i < size)
    {
      tab[i] = '_';
      i++;
    }
    tab[i] = '\0';
    return tab;
}

void ft_print_char_tab(int size, char *tab)
{
    int i;
  
    i = 0;
    while(i < size)
    {
      printf("%c", tab[i]);
      i++;
    }
}

int* ft_count_bomb(int size, int *tab_strike, char **airstrikes_copy, size_t nairstrike)
{
    size_t i;
    int j;
    
    i = 0;
    j = 0;
    while(i < nairstrike)
    {
      while(airstrikes_copy[i][j] != '\0')
      {
          if(airstrikes_copy[i][j] == '*'
          || airstrikes_copy[i][j + 1] == '*'
          || airstrikes_copy[i][j - 1] == '*')
          {
             tab_strike[j] += 1; 
          }
          j++;
      }
      j = 0;
      i++;
    }
    return tab_strike;
}

char* ft_battlefield(int size, int *tab_strike, char *tab_war, const char *reinforces[], size_t nreinforce)
{
  int i;
  int j;
  
  
  i = 0;
  j = 0;
  printf("battlefield size : %d\n", size);
  while(i < size)
  {
    if(tab_strike[i] >= nreinforce)
    {
      i++;
    }
    else{
      tab_war[i] = reinforces[tab_strike[i]][i];
      i++;
    }
  }
    
  return tab_war;
}

char *alphabet_war(const char *reinforces[], const char *airstrikes[], size_t nreinforce, size_t nairstrike)
{
    ft_print_reinforces(reinforces, nreinforce);
    ft_print_airstrikes(airstrikes, nairstrike);
    int size;
    int *tab_strike = NULL;
    char *tab_war = NULL;
    char **airstrikes_copy = NULL;
  
    size = ft_size(reinforces);
    airstrikes_copy = ft_copy_airstrikes(size, airstrikes_copy, airstrikes, nairstrike);
    ft_print_airstrikes(airstrikes_copy, nairstrike);
    tab_strike = ft_init_int_tab(size, tab_strike);
    tab_war = ft_init_char_tab(size, tab_war);
    tab_strike = ft_count_bomb(size, tab_strike, airstrikes_copy, nairstrike);
    printf("   ");
    ft_print_int_tab(size, tab_strike);
    printf("\n\n");
    ft_battlefield(size, tab_strike, tab_war, reinforces, nreinforce);
    printf("\n");
    ft_print_char_tab(size, tab_war);
  
    free(tab_strike);
    return tab_war;
}