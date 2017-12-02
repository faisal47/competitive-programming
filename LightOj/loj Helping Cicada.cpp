#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <map>
#include <math.h>
#include <ctype.h>
using namespace std;
#define inf 1<<28
long long n,m,ans[20],ins[20],val;
long long gcd(long long a,long long b)
{
    if(b==0)
    return a;
    return gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
    long long gc=gcd(a,b);
    return (a*b)/gc;
}
void bt(int in,int ansin)
{
    if(in>n)
    {
        if(ansin==1)
        return;
        long long lc=ans[1];
        for(int i=2;i<ansin;i++)
        lc=lcm(lc,ans[i]);
        if(ansin%2==0)
        val+=(m/lc);
        else
        val-=(m/lc);
        return;
    }
    ans[ansin]=ins[in];
    bt(in+1,ansin+1);
    bt(in+1,ansin);
}
int main ()
{
    int test,t,i;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        cin>>m>>n;
        for(i=1;i<=n;i++)
        cin>>ins[i];
        val=0;
        bt(1,1);
        printf("Case %d: %lld\n",t,m-val);
    }
    return 0;
}

