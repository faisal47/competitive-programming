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

#define mt 10010

int arr[mt];
vec_<int>primes;

int main ()
{
    int i,j;
    primes.pb(2);
    for(i=3;i<mt;i++)
    {
        if(!arr[i])
        {
            arr[i]=1;
            primes.pb(i);
            for(j=i;j<mt;j+=i)
                arr[j]=1;
        }
    }

    int arr1[mt],arr2[mt],m,n,test,t=1,b,a,ans;
    sci1(test);
    vec_<int>prime_main;

    while(test--)
    {
        sci2(n,m);
        clr(prime_main);

        for(i=0;i<sz(primes);i++)
        {
            b=primes[i];
            arr1[b]=arr2[b]=0;

            while(n%b==0)
            {
                n/=b;

                if(!arr1[b])
                prime_main.pb(b);

                arr1[b]++;
            }

            if(n==1)
                break;
        }

        for(i=1;i<=m;i++)
        {
            a=i;
            for(j=0;j<sz(prime_main);j++)
            {
                b=prime_main[j];

                while(a%b==0)
                {
                    arr2[b]++;
                    a/=b;
                }
                if(a==1)
                    break;
            }
        }

        ans=inf;

        for(i=0;i<sz(prime_main);i++)
        {
            j=prime_main[i];
            ans=min(ans,arr2[j]/arr1[j]);
        }

        printf("Case %d:\n",t++);
        if(ans)
        printf("%d\n",ans);
        else
            printf("Impossible to divide\n");
    }

    return 0;
}


