#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define sz
using namespace std;
double R,n,kon,AB;
double f(double r)
{
    AB=sqrt(pow(R-r,2.)-pow(r,2.));
    kon=r/AB;
    kon=atan(kon);
    kon*=180./acos(-1);
    kon*=2.;
    kon*=n;
    return kon;
}
double bs()
{
    double l=0,r=R,mid;
    for(int i=0;i<100;i++)
    {
        mid=(l+r)/2.;
        if(f(mid)>=360.)
        r=mid;
        else
        l=mid;
    }
    return l;
}
int main ()
{
    int test,t;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        cin>>R>>n;
        printf("Case %d: %.10lf\n",t,bs());
    }
    return 0;
}
