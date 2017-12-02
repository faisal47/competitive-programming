#include <stdio.h>
#include <math.h>
int main ()
{
    int n,m=1;
    double d,e,a,b,c;
    while((scanf("%d",&n))==1)
    {
         if(n==0)
      break;
        scanf("%lf%lf%lf",&a,&b,&c);
      if(n==1)
      {
          e=((b-a)/c);
          d=(((b*b)-(a*a))/(2*e));
      }
      else if(n==2)
      {
          d=(((b*b)-(a*a))/(2*c));
          e=((b-a)/c);
      }
      else if(n==3)
      {
          d=sqrt((a*a)+(2*b*c));
          e=((d-a)/b);
      }
      else if(n==4)
      {
          d=sqrt((a*a)-(2*b*c));
          e=((a-d)/b);
      }
      printf("Case %d: %.3lf %.3lf\n",m,d,e);
      m++;
    }
    return 0;
}
