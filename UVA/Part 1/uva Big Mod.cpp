#include <stdio.h>
#include <iostream>
using namespace std;
long long c;
long long f(long long a,long long b)
{
    if(b==0)
    return 1;
    if(b%2==0)
    {
        long long ret=f(a,b/2);
        return ((ret%c)*(ret%c))%c;
    }
    else
    return ((a%c)*(f(a,b-1)%c))%c;
}
int main ()
{
    long long a,b;
    while(cin>>a>>b>>c)
    cout<<f(a,b)<<endl;
}
