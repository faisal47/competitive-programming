#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define ll long long
#define sz
using namespace std;
string a;
int dp[105][105];
int res(int s,int e)
{
    if(s>=e)
    return 0;
    if(dp[s][e]!=-1)
    return dp[s][e];
    if(a[s]==a[e])
    return dp[s][e]=res(s+1,e-1);
    int a=(1+res(s+1,e));
    int b=(1+res(s,e-1));
    return dp[s][e]=min(a,b);
}
int main ()
{
    int test,t;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        ms(dp,-1);
        cin>>a;
        printf("Case %d: %d\n",t,res(0,a.size()-1));
    }
    return 0;
}
