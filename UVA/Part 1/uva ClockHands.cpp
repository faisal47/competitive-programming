#include <stdio.h>
#include <iostream>
int main ()
{
    double a,b;
    while(scanf("%lf:%lf",&a,&b)==2)
    {
        if(a==0&&b==0)
        break;
      a*=5.;
      a+=(b/12.);
      if(a<=b)
      a=b-a;
      else
      a-=b;
      a*=6.;
      if(a>180.)
      a=360.-a;
      printf("%.3lf\n",a);
    }
    return 0;
}
