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
//#define sz
using namespace std;
double r,a,b;
double func(double deg)
{
   // printf("%.2lf\n",a*sin(deg)+b*cos(deg));
    return a*sin(deg)+b*cos(deg);
}
double ternary(double l,double r)
{
    double mid1,mid2;
    int i;
    for(i=0;i<100;i++)
    {
        mid1=((2*l)+r)/3;
        mid2=((2*r)+l)/3;
        if(func(mid1)>=func(mid2))
        {
            r=mid2;
        }
        else
        {
            l=mid1;
        }
    }
    return l;
}
int main ()
{
    int test;
    cin>>test;
    while(test--)
    {
        cin>>a>>b;
        r=sqrt(pow(a,2.)+pow(b,2.));
        //cout<<r<<endl;
        a=ternary(0,2*acos(-1));
        printf("%.2lf %.2lf\n",a,r);
    }
    return 0;
}
