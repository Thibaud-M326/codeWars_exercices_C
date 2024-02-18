int ft_count_left_char(char c);
int ft_count_right_char(char c);

char *alphabet_war(const char *fight)
{
    int i;
    int left_side;
    int right_side;
  
    i = 0;
    left_side = 0;
    right_side = 0;
    while(fight[i] != '\0')
    {
      if(fight[i - 1] != '*' && fight[i + 1] != '*')
      {
        if(fight[i] == 'w' || fight[i] == 'p' || fight[i] == 'b' || fight[i] == 's' )
        {
          left_side += ft_count_left_char(fight[i]);
        }
        if(fight[i] == 'm' || fight[i] == 'q' || fight[i] == 'd' || fight[i] == 'z' )
        {
          right_side += ft_count_right_char(fight[i]);
        }
      }
      i++;
    }
  
    if(left_side > right_side)
    {
      return "Left side wins!";
    }
    else if(right_side > left_side)
    {
      return "Right side wins!";
    }
    else
    {
      return "Let's fight again!";
    }
}

int ft_count_left_char(char c)
{
  if(c == 'w')
  {
    return 4;
  }
  if(c == 'p')
  {
    return 3;
  }
  if(c == 'b')
  {
    return 2;
  }
  if(c == 's')
  {
    return 1;
  }
  return 0;
}

int ft_count_right_char(char c)
{
  if(c == 'm')
  {
    return 4;
  }
  if(c == 'q')
  {
    return 3;
  }
  if(c == 'd')
  {
    return 2;
  }
  if(c == 'z')
  {
    return 1;
  }
  return 0;
}