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
int main ()
{
    int i,dp[20010],k,m,t,n,arr[105],j,ans;
    cin>>t;
    while(t--)
    {
        m=0;
        ans=inf;
        cin>>k;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>arr[i];
            m=max(m,arr[i]);
        }
        for(i=1;i<=k+m;i++)
        dp[i]=inf;
        dp[i]=0;
        for(i=1;i<=n;i++)
        for(j=k;j>=0;j--)
        if(dp[j]!=inf && dp[j+arr[i]]>dp[j]+1 && arr[i]+j<=k+m)
        {
            dp[j+arr[i]]=dp[j]+1;
            if(ans>j+arr[i] && j+arr[i]>=k)
            ans=j+arr[i];
        }
        cout<<ans<<" "<<dp[ans]<<endl;
    }
    return 0;
}
