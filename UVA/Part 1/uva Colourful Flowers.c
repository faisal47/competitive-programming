#include <stdio.h>
#include <math.h>
int main ()
{
    double a,b,c,r1,r2,s,incircle,circumcircle,triangle,pi=acos(-1);
    while((scanf("%lf %lf %lf",&a,&b,&c))==3)
    {
        s=(a+b+c)/2;
        triangle=sqrt(s*(s-a)*(s-b)*(s-c));
        r1=((a*b*c)/sqrt((a+b+c)*(a+b-c)*(b+c-a)*(c+a-b)));
        circumcircle=(pi*r1*r1)-triangle;
        r2=((2*triangle)/(a+b+c));
        incircle=(pi*r2*r2);
        triangle-=incircle;
        printf("%.4lf %.4lf %.4lf\n",circumcircle,triangle,incircle);
    }
    return 0;
}
