/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <math.h>
#include <limits.h>
#include <limits>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
#include <ctime>
#include <queue>
#include <vector>
#include <map>
#include <assert.h>
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
#define allr(a) a.rbegin(),a.rend()
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
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
using namespace std;

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};

/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#define mt 1010
#define mod 1000000007

vec_<int>primes;

int arr[mt];
int ups[100010],downs[100010];

void upfactorize(int a)
{
    if(a<2)
        return;
    int i;
    for(i=0;i<sz(primes);i++)
    {
        if(a==1)
            return;

        if(a%primes[i]==0)
        {
            while(a%primes[i]==0)
            {
                a/=primes[i];
                ups[primes[i]]++;
            }
        }
    }
    if(a>1)
        ups[a]++;
}

void downfactorize(int a,int n)
{
    if(a<2)
        return;
    int i;
    for(i=0;i<sz(primes);i++)
    {
        if(a==1)
            break;
        if(a%primes[i]==0)
        {
            while(a%primes[i]==0)
            {
                a/=primes[i];
                downs[primes[i]]++;
            }
        }
    }

    if(a>1)
        downs[a]++;
    for(i=0;i<100005;i++)
        downs[i]*=n;
}

int main ()
{
//    fop;
    int i,j;
    primes.pb(2);
    for(i=3;i<319;i+=2)
    {
        if(!arr[i])
        {
            primes.pb(i);
            for(j=i+i;j<319;j+=i)
                arr[j]=1;
        }
    }

    int test,n,x,a,t=1;
    sci1(test);
    while(test--)
    {
        ms(ups,0);
        ms(downs,0);
        sci2(n,x);
        bool flag=false;
        for(i=0;i<n;i++)
        {
            sci1(a);
            a=x-a;
            if(a==0)
            {
                flag=true;
            }
            upfactorize(a);
        }
        downfactorize(x,n);
        if(flag)
        {
            printf("Case %d: 0\n",t++);
            continue;
        }
        for(i=0;i<100005;i++)
        {
            if(ups[i] || downs[i])
            if(ups[i]>=downs[i])
                {
                    ups[i]-=downs[i];
                    downs[i]=0;
                }
            else
                {
                    downs[i]-=ups[i];
                    ups[i]=0;
                }
//            if(ups[i] || downs[i])
//            deb("ups and downs == ",i,ups[i],downs[i]);
        }
        ll upor,nich;
        upor=1ll;
        nich=1ll;
        for(i=0;i<100005;i++)
        {
            if(ups[i])
            upor=(upor*bigmod(i,ups[i],mod))%mod;

            if(downs[i])
            nich=(nich*bigmod(i,downs[i],mod))%mod;
        }
        if(upor/nich==1 && upor%nich==0)
        {
            printf("Case %d: 1\n",t++);
        }
        else
        printf("Case %d: %lld/%lld\n",t++,upor,nich);
    }

    return 0;
}
