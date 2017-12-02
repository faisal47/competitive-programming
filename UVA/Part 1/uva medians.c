#include <stdio.h>
#include <math.h>
int main ()
{
    double a,b,c,d,e;
    while(scanf("%lf %lf %lf",&a,&b,&c)==3)
    {
        if(a<=0||b<=0||c<=0||(a+b)<=c||(b+c)<=a||(c+a)<=b)
        printf("-1.000\n");
        else
        {
         d=((pow(a,2)*pow(b,2))+(pow(b,2)*pow(c,2))+(pow(c,2)*pow(a,2)));
         e=(pow(a,4)+pow(b,4)+pow(c,4));
        printf("%.3lf\n",((1/3.)*(double)(sqrt((2*d)-e))));
        }
    }
    return 0;
}
