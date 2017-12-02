#include <stdio.h>
#include <iostream>
using namespace std;
int r,n;
long long dp[205][105],arr[205][105];
long long call(int i,int j)
{
    int flag=0;
    if(i<=r&&j>=1)
    {
        if(i<n&&j<n)
        flag=1;
        else if((i==n&&j<=n)||(i>n&&j<=n-(i-n)))
        flag=2;
    }
    if(flag==0)
    return 0;
    else if(dp[i][j]!=-1)
    return dp[i][j];
    else if(flag==1)
    {
       // cout<<i<<" "<<j<<endl;
        long long res=0;
        res=max(res,arr[i][j]+call(i+1,j));
        res=max(res,arr[i][j]+call(i+1,j+1));
        return dp[i][j]=res;
    }
    else
    {
        //cout<<i<<" "<<j<<endl;
        long long res=0;
        res=max(res,arr[i][j]+call(i+1,j-1));
        res=max(res,arr[i][j]+call(i+1,j));
        return dp[i][j]=res;
    }
}
int main ()
{
    int t1,t,i,j;
    cin>>t1;
    for(t=1;t<=t1;t++)
    {
        cin>>n;
        r=(n*2)-1;
        for(i=1;i<=n;i++)
        for(j=1;j<=i;j++)
        cin>>arr[i][j],dp[i][j]=-1;
        for(i=n+1;i<=r;i++)
        for(j=1;j<=n-(i-n);j++)
        cin>>arr[i][j],dp[i][j]=-1;
        printf("Case %d: %lld\n",t,call(1,1));
    }
    return 0;
}
