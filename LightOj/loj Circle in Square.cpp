#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
    double a,pi=2 * acos (0.0),b;
    int test,t;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        cin>>a;
        a*=2.;
        b=a*a;
        a/=2.;
        a=pi*a*a;
        b-=a;
        printf("Case %d: %.2lf\n",t,b);
    }
    return 0;
}
