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
#define sci4(a,b,c,d) scanf(" %d %d %d %d",&a,&b,&c,&d)
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

#define mt 1000010

int count2(int a)
{
    int cnt=0;

    while(a)
    {
        cnt+=a/2;
        a/=2;
    }
    return cnt;
}

int count5(int a)
{
    int cnt=0;

    while(a)
    {
        cnt+=a/5;
        a/=5;
    }

    return cnt;
}

pii facts(int n)
{
    int a1=0,a2=0;

    while(n%2==0)
    {
        a1++;
        n/=2;
    }
    while(n%5==0)
    {
        a2++;
        n/=5;
    }
    return mp(a1,a2);
}

int main ()
{

    int n,p,q,r,test,t=1,c2,c5;
    pii a;
    sci1(test);
    while(test--)
    {
        sci4(n,r,p,q);
        c2=c5=0;
        c2=count2(n);
        c5=count5(n);
        c2-=count2(n-r);
        c5-=count5(n-r);
        c2-=count2(r);
        c5-=count5(r);
        a=facts(p);
        a.fs*=q;
        a.sc*=q;
        c2+=a.fs;
        c5+=a.sc;
        pf("Case %d: %d\n",t++,min(c2,c5));

    }
    return 0;
}



