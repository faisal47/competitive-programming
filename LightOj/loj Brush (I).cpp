#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    long long int a;
    int test,t,n,d;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        a=0;
        cin>>n;
        while(n--)
        {
            cin>>d;
            if(d<0)
            continue;
            a+=d;
        }
        printf("Case %d: %lld\n",t,a);
    }
    return 0;
}
