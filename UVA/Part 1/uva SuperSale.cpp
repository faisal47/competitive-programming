#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int arr[1010][2],n;
long long capas,dp[1010][35];
long long napsack(int i,int w)
{
    if(i==n)
    return 0;
    if(dp[i][w]!=-1)
    return dp[i][w];
    long long lav1,lav2;
    if(w+arr[i][1]<=capas)
    lav1=arr[i][0]+napsack(i+1,w+arr[i][1]);
    else
    lav1=0;
    lav2=napsack(i+1,w);
    dp[i][w]=max(lav1,lav2);
    return dp[i][w];
}

int main ()
{
    int test,i,n1;
    long long out;
    cin>>test;
    while(test--)
    {
        out=0;
        cin>>n;
        for(i=0;i<n;i++)
        cin>>arr[i][0]>>arr[i][1];
        cin>>n1;
        for(i=0;i<n1;i++)
        {
            memset(dp,-1,sizeof(dp));
            cin>>capas;
            out+=napsack(0,0);
        }
        cout<<out<<endl;
    }
    return 0;
}
