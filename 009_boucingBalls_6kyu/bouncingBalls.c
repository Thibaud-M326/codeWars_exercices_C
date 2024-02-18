#include <stdio.h>

int bouncingBall(double h, double bounce, double window) {
    int view;
  
    view = 0;
    if(h <= 0                       //false
    || bounce <= 0 || bounce >= 1   //false
    || window >= h)                 //false
    {
      return -1;
    }
  
    while(h > 0.01)
    {
      if(h > window)
      {
        view++;
      }
      h *= bounce;
      if(h > window)
      {
        view++;
      }
    }
    return view;
}