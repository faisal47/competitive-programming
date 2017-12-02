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
#define FOR_0(i,n) for(i=0;i<n;i++)
#define FOR_1(i,n) for(i=1;i<=n;i++)
#define clr(a) a.clear()
#define pb push_back
//ll bigmod(ll a,ll b,ll m)
//{
//    if(b == 0) return 1%m;
//    ll x = bigmod(a,b/2,m);
//    x = (x * x) % m;
//    if(b % 2 == 1) x = (x * a) % m;
//    return x;
//}
using namespace std;
#define sz 70
ll dp[sz][sz][2];
ll mot(ll n,ll m,bool s)
{

    if(n==0 && m==0)
        return 1;
    if(n<=0)
        return 0;
    if(dp[n][m][s]!=-1)
        return dp[n][m][s];
    if(s==1)
    return dp[n][m][s]=mot(n-1,m,0)+mot(n-1,m-1,1);
    else
    return dp[n][m][s]=mot(n-1,m,0)+mot(n-1,m,1);
}
int main ()
{
    ll n,m;
    while(cin>>n>>m)
    {
        if(n<0 && m<0)
            break;
        if(m>n)
        {
            cout<<"0"<<endl;
            continue;
        }
        ms(dp,-1);
        cout<<mot(n,m,1)<<endl;
    }
    return 0;
}
