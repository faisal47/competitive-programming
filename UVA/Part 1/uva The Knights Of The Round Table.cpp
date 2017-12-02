#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
    double a,b,c,r,p;
    while(cin>>a>>b>>c)
    {
        if(a==0||b==0||c==0)
        {
            printf("The radius of the round table is: 0.000\n");
            continue;
        }
        p=(a+b+c)/2.;
        r=sqrt(p*(p-a)*(p-b)*(p-c));
        p=a+b+c;
        r=(2.*r)/p;
        printf("The radius of the round table is: %.3lf\n",r);
    }
    return 0;
}
