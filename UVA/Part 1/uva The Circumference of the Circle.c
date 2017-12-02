#include <stdio.h>
#include <math.h>
int main ()
{
    double a1,a12,b1,b12,a2,a22,b2,b22,a3,a32,b3,b32,d1,d2,d3,d4,d5,d6,f,g,r,pi=acos(-1),g2,f2;
    while((scanf("%lf %lf %lf %lf %lf %lf",&a1,&b1,&a2,&b2,&a3,&b3))==6)
    {
        a12=pow(a1,2);
        b12=pow(b1,2);
        a22=pow(a2,2);
        b22=pow(b2,2);
        a32=pow(a3,2);
        b32=pow(b3,2);
        d1=a1-a2;
        d2=b1-b2;
        d3=a2-a3;
        d4=b2-b3;
        if(d1==0||d2==0||d3==0||d4==0)
        {
            d5=(a22+b22-a12-b12);
            d6=(a32+b32-a22-b22);
            if(d1==0)
            {
                f=d5/(2.*d2);
                g=(d6-(2.*f*d4))/(2.*d3);
            }
            else if(d2==0)
            {
                g=d5/(2.*d1);
                f=(d6-(2.*g*d3))/(2.*d4);
            }
            else if(d3==0)
            {
                f=d6/(2.*d4);
                g=(d5-(2.*f*d2))/(2.*d1);
            }
            else
            {
                g=d6/(2.*d3);
                f=(d5-(2.*g*d1))/(2.*d2);
            }
        }
        else
        {
            d5=((a32+b32-a22-b22)*d2)/d4;
            d6=(a12+b12-a22-b22);
            d6+=d5;
            d5=(2.*d1)-((2.*d3*d2)/d4);
            g=(-1.)*(d6/d5);
            f=(a32+b32-a22-b22-(2.*g*d3))/(2.*d4);
        }
        g2=pow(g,2);
        f2=pow(f,2);
        r=(a12+b12+(2.*g*a1)+(2.*f*b1)+g2+f2);
        r=sqrt(r);
        r=(2.*pi*r);
        printf("%.2lf\n",r);
    }
    return 0;
}
