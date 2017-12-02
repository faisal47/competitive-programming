#include <stdio.h>
#include <iostream>
using namespace std;
long long gcd(long long a,long long b)
{
    if(b==0)
    return a;
    else
    return gcd(b,a%b);
}
int main ()
{
    long long i,j,n,g;
    while(cin>>n)
    {
        if(n==0)
        break;
        g=0;
        for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
        g+=gcd(i,j);
        cout<<g<<endl;
    }
    return 0;
}
