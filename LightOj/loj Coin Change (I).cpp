#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int dp[1010][55],n,c[55],w[55],m1;
int cc(int m,int i)
{
    if(i==n)
    {
        if(m==m1)
        return 1;
        return 0;
    }
    if(m==m1)
        return 1;
    if(m>m1)
    return 0;
    if(dp[m][i]!=-1)
    return dp[m][i];
    int r1=0;
    for(int t=0;t<=c[i];t++)
    r1=(r1+cc(m+(w[i]*t),i+1))%100000007;
    return dp[m][i]=r1;
}
int main ()
{
    int t,m,t1,i;
    cin>>t1;
    for(t=1;t<=t1;t++)
    {
        cin>>n>>m1;
        for(i=0;i<n;i++)
        cin>>w[i];
        for(i=0;i<n;i++)
        cin>>c[i];
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",t,cc(0,0));
    }
    return 0;
}
