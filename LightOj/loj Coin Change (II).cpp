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
int dp[10010];
int n,k,arr[105];
int main ()
{
    int test,t,i,j;
    int res;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        cin>>n>>k;
        for(j=0;j<=k;j++)
                dp[j]=0;
        dp[0]=1;
        for(i=1;i<=n;i++)
            cin>>arr[i];
        for(i=1;i<=n;i++)
        for(j=arr[i];j<=k;j++)
        {
            dp[j]=(dp[j]+dp[j-arr[i]])%100000007;
        }
        printf("Case %d: %d\n",t,dp[k]);
    }
    return 0;
}
