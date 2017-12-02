#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
long long dp[5][30010];
int arr[]={1,5,10,25,50},n=5;
long long cc(int i,int w)
{
    if(i==n)
    {
        if(w==0)
        return 1;
        else
        return 0;
    }
    if(dp[i][w]!=-1)
    return dp[i][w];
    long long r1,r2;
    if(w-arr[i]>=0)
    r1=cc(i,w-arr[i]);
    else
    r1=0;
    r2=cc(i+1,w);
    return dp[i][w]=r1+r2;
}
int main ()
{
    memset(dp,-1,sizeof(dp));
    long long w,c;
    while(cin>>w)
    {
       c=cc(0,w);
       if(c==1)
       printf("There is only %lld way to produce %lld cents change.\n",c,w);
       else
       printf("There are %lld ways to produce %lld cents change.\n",c,w);
    }
    return 0;
}
