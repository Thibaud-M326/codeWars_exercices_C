// a and b contain coordinate points
// both are guaranteed to be size 2

int ft_absolute(int nb)
{
  if(nb < 0)
  {
    return -nb;
  }
  return nb;
}

int manhattan_distance(int *a, int *b) {
  int distance;
  int x;
  int y;
  
  x = b[0] - a[0];
  x = ft_absolute(x);
  y = b[1] - a[1];
  y = ft_absolute(y);
  distance = x + y;
  
  return distance;
}