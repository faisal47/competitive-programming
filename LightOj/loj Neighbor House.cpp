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
int n,dp[23][4],arr[23][4];
int call(int i,int j)
{
        if(i==n)
        return arr[i][j];
        else if(dp[i][j]!=-1)
        return dp[i][j];
        if(j==1)
        return dp[i][j]=min(arr[i][j]+call(i+1,2),arr[i][j]+call(i+1,3));
        else if(j==2)
        return dp[i][j]=min(arr[i][j]+call(i+1,1),arr[i][j]+call(i+1,3));
        else
        return dp[i][j]=min(arr[i][j]+call(i+1,1),arr[i][j]+call(i+1,2));
}
int main ()
{
    int ans,i,t,test,j;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        memset(dp,-1,sizeof(dp));
        cin>>n;
        for(i=1;i<=n;i++)
        for(j=1;j<=3;j++)
        cin>>arr[i][j];
        ans=inf;
        for(i=1;i<=3;i++)
        ans=min(ans,call(1,i));
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}

