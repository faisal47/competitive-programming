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
long long dp[35][35];
long long ncr(long long n,long long r)
{
    if(n==r||r==0)
        return 1;
    else if(r==1)
        return n;
    if(dp[n][r]!=-1)
    return dp[n][r];
    return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);
}
int main ()
{
    int test,t;
    long long a,k,n,r;
    cin>>test;
    memset(dp,-1,sizeof(dp));
    for(t=1; t<=test; t++)
    {
        cin>>n>>r;
        if(n<r)
            a=0;
        else
        {
            a=ncr(n,r);
            a*=a;
            k=1;
            while(1)
            {
                if(r<2)
                    break;
                k*=r;
                r--;
            }
            a*=k;
        }
        printf("Case %d: %lld\n",t,a);
    }
    return 0;
}
