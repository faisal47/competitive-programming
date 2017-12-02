#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <utility>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define mp make_pair
#define pii pair<int,int>
#define fs first
#define sc second
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define sf scanf
#define pf printf
#define all(a) a.begin(),a.end()
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define scch(a) scanf(" %c",&a)
#define scll1(a) scanf(" %I64d",&a)
#define scll2(a,b) scanf(" %I64d %I64d",&a,&b)
#define scll3(a,b,c) scanf(" %I64d %I64d %I64d",&a,&b,&c)
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sci3(a,b,c) scanf(" %d %d %d",&a,&b,&c)
#define scd1(a) scanf(" %lf",&a)
#define scd2(a,b) scanf(" %lf %lf",&a,&b)
#define scd3(a,b,c) scanf(" %lf %lf %lf",&a,&b,&c)
#define deb1(a) cout<<a<<endl;
#define deb2(a,b) cout<<a<<" "<<b<<endl
#define deb3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
using namespace std;
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};

///***************************************************** ekhon kamer kam ********************************************************************///

#define mt 1130
ll arr[mt];
vec_<ll>primes;

ll n,k,dp[mt][16][200];

ll solve(int sum,int koyta,int s)
{
    if(sum<0 || koyta<0)
        return 0;

    if(sum==0 && koyta==0)
        return 1;

    if(s==sz(primes)  || (koyta==0 && sum>0) || (koyta>0 && sum==0))
        return 0;

    ll &ret=dp[sum][koyta][s],i;

    if(ret!=-1)
        return ret;

    ret=0;

    for(i=s;i<sz(primes);i++)
    {
        ret+=solve(sum-primes[i],koyta-1,i+1);
    }

    return ret;

}

int main ()
{
    ll i,j;
    primes.pb(2);
    arr[2]=1;
    for(i=3;i<mt;i+=2)
        if(!arr[i])
        {
            primes.pb(i);
            arr[i]=1;
            for(j=i+i;j<mt;j+=i)
                arr[j]=2;
        }

    ms(dp,-1);

    while(sci2(n,k) && n && k)
    {
        pf("%lld\n",solve(n,k,0));
    }

    return 0;
}


/*
24 3
24 2
2 1
1 1
4 2
18 3
17 1
17 3
17 4
100 5
*/
