#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define sz
using namespace std;
double x,y,c,A,B;
int f(double d)
{
    A=sqrt(pow(x,2.)-pow(d,2.));
    B=sqrt(pow(y,2.)-pow(d,2.));
    return (A*B)/(A+B);
}
double bs()
{
    double l,r,mid;
    r=x+y;
    l=0;
    int i;
    for(i=0;i<100;i++)
    {
        mid=(l+r)/2;
        if(f(mid)<c)
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
        cin>>x>>y>>c;
        printf("Case %d: %.10lf\n",t,bs());
    }
    return 0;
}
