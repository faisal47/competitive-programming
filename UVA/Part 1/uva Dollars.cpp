#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
long long dp[12][30010],n=11;
int arr[]={5,10,20,50,100,200,500,1000,2000,5000,10000};
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

    long long c1,c2;

    if(w-arr[i]>=0)
    c1=cc(i,w-arr[i]);
    else
    c1=0;
    c2=cc(i+1,w);
    return dp[i][w]=c1+c2;
}
int main ()
{
    memset(dp,-1,sizeof(dp));
    long long res,a,w,b;
    while(scanf("%lld.%lld",&a,&w)==2)
    {
        b=(a*100)+w;
        if(b==0)
        break;
        res=cc(0,b);
        printf("%3lld.%02lld%17lld\n",a,w,res);
    }
    return 0;
}
