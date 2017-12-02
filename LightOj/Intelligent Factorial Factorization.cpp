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
using namespace std;
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};

///***************************************************** ekhon kamer kam ********************************************************************///

#define mt 110

vec_<int>primes,prime_main;
int arr[mt],arr1[mt];

int main ()
{
    int i,j;

    primes.pb(2);
    for(i=3;i<mt;i+=2)
    {
        if(!arr[i])
            {
                primes.pb(i);
                for(j=i;j<mt;j+=i)
                    arr[j]=1;
            }
    }

    int test,t=1,n,a,n1;
    sci1(test);
    while(test--)
    {
        sci1(n);
        n1=n;
        ms(arr1,0);
        clr(prime_main);
        while(n>1)
        {
            a=n;
            for(i=0;i<sz(primes);i++)
            {
                j=primes[i];
                while(a%j==0)
                {
                    a/=j;
                    if(!arr1[j])
                        prime_main.pb(j);
                    arr1[j]++;
                }
                if(a==1)
                    break;
            }
            n--;
        }
        sort(all(prime_main));
        pf("Case %d: %d =",t++,n1);
        pf(" %d (%d)",prime_main[0],arr1[prime_main[0]]);
        for(i=1;i<sz(prime_main);i++)
            pf(" * %d (%d)",prime_main[i],arr1[prime_main[i]]);
        pf("\n");
    }

    return 0;
}

