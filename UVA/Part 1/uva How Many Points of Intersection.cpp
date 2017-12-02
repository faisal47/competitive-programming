#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    long long a,t=1,b;
    while(cin>>a>>b)
    {
        if(a==0&&b==0)
        break;
        a=(a*(a-1))/2;
        b=(b*(b-1))/2;
        printf("Case %lld: %lld\n",t++,a*b);
    }
    return 0;
}
