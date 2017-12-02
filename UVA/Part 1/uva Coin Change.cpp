#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int dp[6][7500],n=5,arr[]={1,5,10,25,50},cap;
long long cc(int i,int w)
{
    if(n==i)
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
    long long res;
    memset(dp,-1,sizeof(dp));
    while(cin>>cap)
    {
        res= cc(0,cap);
        cout<<res<<endl;
    }
    return 0;
}
