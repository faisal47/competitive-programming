#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    int test,t,a,b,i,r;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        r=0;
        cin>>a>>b;
        for(i=a;i<=b;i++)
        if(i%2==1)
        r+=i;
        printf("Case %d: %d\n",t,r);
    }
    return 0;
}
