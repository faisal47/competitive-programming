#include <stdio.h>
#include <math.h>
int main ()
{
    double area,r,n,a,b;
    while((scanf("%lf %lf",&r,&n))==2)
    {
        a=360/n;b=acos(-1);
        a=a*b;a/=180.;
        area=(sin(a)*r*r*n)/2;
        printf("%.3lf\n",area);
    }
    return 0;
}
