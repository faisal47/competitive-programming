#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main ()
{
    double a,b,c;int d;
    while((scanf("%lf %lf",&a,&b))==2)
    {
        a=1./a;
        c=pow(b,a);
        printf("%.0lf\n",c);
    }
    return 0;
}
