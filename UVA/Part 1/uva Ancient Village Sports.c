#include <stdio.h>
#include <math.h>
int main ()
{
    double n,a,b,c,d,f,pi=acos(-1);
    int e=1;
    while((scanf("%lf %lf",&n,&a))==2)
    {
        if(n<3)
        break;
        b=sin((2*pi)/n);
        b/=2;
        b*=n;
        b=a/b;
        b=sqrt(b);
        c=(pi*b*b);
        d=b*(cos(pi/n));
        d=(pi*d*d);
        printf("Case %d: %.5lf %.5lf\n",e,c-a,a-d);
        ++e;
    }
    return 0;
}
