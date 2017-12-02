#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
    int test;
    double a,d,r,pi=acos(-1);
    cin>>test;
    while(test--)
    {
        cin>>a;
        d=a*(3./5.);
        d*=a;
        r=a/5.;
        r=pi*r*r;
        d-=r;
        printf("%.2lf %.2lf\n",r,d);
    }
    return 0;
}
