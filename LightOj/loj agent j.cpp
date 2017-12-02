#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
    int test,t=1;
    cin>>test;
    double r1,b,c,d1,d2,d3,a,r2,r3,pi=acos(-1),p;
    while(test--)
    {
        cin>>r1>>r2>>r3;
        a=r1+r2;
        b=r2+r3;
        c=r3+r1;
        d3=(a*a)+(b*b)-(c*c);
        d3=d3/(2*a*b);
        d3=acos(d3);
        d3=(180./pi)*d3;
        d1=(b*b)+(c*c)-(a*a);
        d1=d1/(2*b*c);
        d1=acos(d1);
        d1=(180./pi)*d1;
        d2=(c*c)+(a*a)-(b*b);
        d2=d2/(2*a*c);
        d2=acos(d2);
        d2=(180./pi)*d2;
       // cout<<d1<<" "<<d2<<" "<<d3<<endl;
        d2=(d2/360.)*pi*r1*r1;
        d3=(d3/360.)*pi*r2*r2;
        d1=(d1/360.)*pi*r3*r3;
        //cout<<d1<<" "<<d2<<" "<<d3<<endl;
        d1+=d2+d3;
        p=(a+b+c)/2.;
        p=sqrt(p*(p-a)*(p-b)*(p-c));
       // cout<<p<<endl;
        printf("Case %d: ",t++);
        p-=d1;
        printf("%.10lf\n",p);
    }
    return 0;
}

