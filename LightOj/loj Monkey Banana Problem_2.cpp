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
long long n,dp[205][105],arr[205][105],row;
long long call(int r,int c)
{
    bool flag=0;
    if(r>=1&&r<=row&&c>=1)
    {
        if(r<n&&c<n)
        flag=1;
        else if((r>n&&c<=((2*n)-r))||(r==n&&c<=n))
        flag=1;
    }
    if(flag==0)
    return 0;
    if(dp[r][c]!=-1)
    return dp[r][c];
        long long r1,r2;
        if(r<n)
        {
            r1=arr[r][c]+call(r+1,c);
            r2=arr[r][c]+call(r+1,c+1);
            return dp[r][c]=max(r1,r2);
        }
        else
        {
            r1=arr[r][c]+call(r+1,c-1);
            r2=arr[r][c]+call(r+1,c);
            return dp[r][c]=max(r1,r2);
        }
}
int main ()
{
    int test,t,i,j,a;
    long long res;
    cin>>test;
    for(t=1; t<=test; t++)
    {
        memset(dp,-1,sizeof(dp));
        cin>>n;
        for(i=1; i<=n; i++)
            for(j=1; j<=i; j++)
                cin>>arr[i][j];
        row=(2*n)-1;
        a=n+1;
        for(i=1; i<n; i++)
        {
            for(j=1; j<=n-i; j++)
                cin>>arr[a][j];
            a++;
        }
        res=call(1,1);
        printf("Case %d: %lld\n",t,res);
    }
    return 0;
}

