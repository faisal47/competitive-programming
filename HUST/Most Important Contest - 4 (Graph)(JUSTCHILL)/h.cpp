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

#define mt 110

int par[mt];

struct data1
{
    int a,b,c;
};

vec_<data1>data;

bool comp(data1 a,data1 b)
{
    return a.c>b.c;
}

int ans;

int find_parent(int s)
{
    if(par[s]==s)
        return s;
    return par[s]=find_parent(par[s]);
}

void mst(int n)
{
    ans=inf;
    int i,u,v;

    for(i=0;i<=n;i++)
        par[i]=i;
    for(i=0;i<sz(data);i++)
    {
        u=find_parent(data[i].a);
        v=find_parent(data[i].b);
        if(u==v)
            continue;
        par[u]=v;
        ans=min(ans,data[i].c);

    }
}

int main ()
{
    int t=1,n,m,test,a,b,c;
    sci1(test);
    while(test--)
    {
        sci2(n,m);
        clr(data);
        while(m--)
        {
            sci3(a,b,c);
            data.pb({a,b,c});
        }
        sort(all(data),comp);
        mst(n);
        pf("Case #%d: %d\n",t++,ans);
    }
    return 0;
}


