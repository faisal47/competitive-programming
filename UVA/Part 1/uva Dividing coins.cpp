#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int dp[110][25010],m,cap,arr[110];
int ks(int i,int w)
{
    if(i==m)
    return 0;
    int p1,p2;
    if(dp[i][w]!=-1)
    return dp[i][w];
    if(w+arr[i]<=cap)
    p1=arr[i]+ks(i+1,w+arr[i]);
    else
    p1=0;
    p2=ks(i+1,w);
    dp[i][w]=max(p1,p2);
    return dp[i][w];
}

int main ()
{
    int test,i,sum;
    cin>>test;
    while(test--)
    {
        sum=0;
        cin>>m;
        for(i=0;i<m;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        cap=sum/2;
        memset(dp,-1,sizeof(dp));
        i=ks(0,0);
        cout<<sum-(2*i)<<endl;
    }
    return 0;
}
