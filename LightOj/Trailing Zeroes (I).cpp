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
#define scll1(a) scanf(" %lld",&a)
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
using namespace std;
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};

////

#define mt 1000010

int arr[mt];

vec_<ll>primes;

int main ()
{
    int i,j;
    int k=sqrt(mt);
    primes.pb((ll)2);

    for(i=3;i<=k;i+=2)
    {
        if(!arr[i])
        {
            primes.pb((ll)i);

            for(j=i*i;j<mt;j+=i)
                arr[j]=1;
        }
    }

    for(i=3;i<mt;i+=2)
        if(!arr[i])
        primes.pb(i);

    int test,t=1;
    ll n,c,ans;

    scanf(" %d",&test);

    while(test--)
    {
        ans=1ll;
        scanf(" %lld",&n);

        for(i=0;i<sz(primes) && (primes[i]*primes[i] <= n);i++)
        {
            c=1ll;
            j=primes[i];
            while(n%j == 0ll)
            {
                n/=j;
                c++;
            }

            ans*=c;
        }

        if(n!=1ll)
            ans*=2ll;
        ans--;
        pf("Case %d: %lld\n",t++,ans);
    }

    return 0;
}

