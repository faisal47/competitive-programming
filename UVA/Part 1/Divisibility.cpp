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
#define vec_  vector
//ll bigmod(ll a,ll b,ll m)
//{
//    if(b == 0) return 1%m;
//    ll x = bigmod(a,b/2,m);
//    x = (x * x) % m;
//    if(b % 2 == 1) x = (x * a) % m;
//    return x;
//}
#define sz 105
using namespace std;
int dp[10005][sz],n,k;
vec_ <int>v;
int maan(int pos,int jog)
{
    if(pos==n)
    {
        if(jog%k==0)
        return 1;
        return 0;
    }
    if(dp[pos][jog]!=-1)
    return dp[pos][jog];
    int x=0;
    x=x||maan(pos+1,(jog+v[pos])%k);
    x=x||maan(pos+1,(jog-v[pos])%k);
    return dp[pos][jog]=x;
}
int main ()
{
    ll i,j,test;
    cin>>test;
    while(test--)
    {
        clr(v);
        ms(dp,-1);
        cin>>n>>k;
        for(i=0;i<n;i++)
        {
            cin>>j;
            v.pb(j);
        }
        if(maan(1,v[0]%k))
        cout<<"Divisible\n";
        else
        cout<<"Not divisible\n";
    }
    return 0;
}

