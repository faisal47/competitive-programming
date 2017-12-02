#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <utility>
#include <queue>
#include <algorithm>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define ll long long
#define FOR_0(i,n) for(i=0;i<n;i++)
#define FOR_1(i,n) for(i=1;i<=n;i++)
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define sz
using namespace std;
//ll bigmod(ll a,ll b,ll m)
//{
//    if(b == 0) return 1%m;
//    ll x = bigmod(a,b/2,m);
//    x = (x * x) % m;
//    if(b % 2 == 1) x = (x * a) % m;
//    return x;
//}
//ll gcd(ll a,ll b)
//{
//   if(b==0)
//   return a;
//   return gcd(b,a%b);
//}
int main ()
{
    ll a,i,j,n,lo,lc,ro,rc;
    lo=lc=ro=rc=0;
    cin>>n;
    for(a=0;a<n;a++)
    {
        cin>>i>>j;
        if(i)
        lo++;
        else
        lc++;
        if(j)
        ro++;
        else
        rc++;
    }
    ll ans=0;
    if(lc>=lo)
        ans+=n-lc;
    else
    ans+=n-lo;
    if(rc>=ro)
    ans+=n-rc;
    else
    ans+=n-ro;
    cout<<ans;
    return 0;
}