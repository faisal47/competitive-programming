#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    int j,inf=123456789,i,dp[20010],w[110],ans=123456789,t,n,k,m;
    cin>>t;
    while(t--)
    {
        cin>>k;
        cin>>n;
        m=0;
        ans=123456789;
        for(i=0;i<n;i++)
        cin>>w[i],m=max(m,w[i]);
        for(i=1;i<=m+k;i++)
        dp[i]=inf;
        dp[0]=0;
        for(i=0;i<n;i++)
        {
            for(j=k;j>=0;j--)
            {
                if(dp[j]!=inf && j+w[i]<=k+m && dp[j+w[i]]>dp[j]+1)
                {
                    dp[j+w[i]]=dp[j]+1;
                    if(j+w[i]<ans && j+w[i] >= k)
                    ans=j+w[i];
                }
            }
        }
        cout<<ans<<" "<<dp[ans]<<endl;
    }
    return 0;
}
