#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    double a,b,c,d,e,f;
    while(cin>>a>>b>>c>>d)
    {
        if(a==0&&b==0&&c==0&&d==0)
        break;
        e=f=0;
        if(b>=a)
        e+=b-a;
        else
        {
            e+=(40.-b);
            e+=(a-b);
        }
        e/=2.;
        if(c<=b)
        e+=(b-c);
        else
        {
            e+=40.;
            e+=c-b;
        }
        if(d>=c)
        f+=d-c;
        else
        {
            f+=(40.-d);
            f+=(c-d);
        }
        f/=2.;
        e+=f;
        e*=22.5;
        printf("%.0lf\n",e);
    }
    return 0;
}
