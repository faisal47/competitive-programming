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

///***************************************************** ekhon kamer kam ********************************************************************///

#define mt 10000010

int arr[mt];

vec_<ll>primes;

int main ()
{
    ll i,j,k;
    k=sqrt(mt);

    for(i=3; i<=k; i+=2)
    {
        if(!arr[i])
        {
            for(j=i*i; j<mt; j+=i)
                arr[j]=1;
        }
    }

    primes.pb(2);

    for(i=3; i<mt; i+=2)
        if(!arr[i])
            primes.pb(i);

    ll n,ans;

    int c;

    while(scll1(n)==1 && n)
    {
        c=0;
        if(n<0)
            n=-n;
        ans=-1ll;
        for(i=0; i<sz(primes); i++)
        {
            j=primes[i];
            while(n%j==0)
            {
                if(c==0)
                {
                    c++;
                    ans=j;
                }
                else if(ans!=j && c==1)
                {
                    c=2;
                    ans=max(ans,j);
                }
                else
                    ans=max(ans,j);
                n/=j;

            }
            if(n==1ll)
                break;
        }
        if(n!=1ll && c>0)
            {
                ans=max(ans,n);
                c=2;
            }

        if(c==2)
            pf("%lld\n",ans);
        else
        {
            pf("-1\n");
        }
    }

    return 0;
}


