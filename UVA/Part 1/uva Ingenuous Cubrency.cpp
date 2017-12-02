#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
long long dp[27][10000];
int arr[22],n=21;
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
    int i;
    for(i=0;i<21;i++)
    arr[i]=(i+1)*(i+1)*(i+1);
    int w;
    while(cin>>w)
    cout<<cc(0,w)<<endl;
    return 0;
}
