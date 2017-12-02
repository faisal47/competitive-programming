#include <stdio.h>
#include <math.h>
int main ()
{
    double l,w,h,degree,a,b,c,pi=acos(-1),d;
    while((scanf("%lf %lf %lf %lf",&l,&w,&h,&degree))==4)
    {
        degree=(90-degree);
        b=tan((pi/180)*degree);
        c=l/b;
        if(c<=h)
        {
        a=l*w*h;
        c=(.5*c*l*w);
        printf("%.3lf mL\n",a-c);
        }
        else
        {
            b=tan((pi/180)*degree);
            c=h*b;
            c=(w*.5*c*h);
            printf("%.3lf mL\n",c);
        }
    }
    return 0;
}
