
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

struct data
{
    int node,cost;
    bool operator < (const data &p)const
    {
        return cost>p.cost;
    }
};

priority_queue<data>q;

struct info
{
    int node,cost;
};

vec_<info>adj[mt];
int dist[mt];

void dj(int s)
{
    while(!q.empty())q.pop();
    data u,v;
    dist[s]=0;
    u.node=s;
    u.cost=0;
    q.push(u);
    int i;
    while(!q.empty())
    {
        u=q.top();
        q.pop();
        for(i=0;i<sz(adj[u.node]);i++)
        {
            v.node=adj[u.node][i].node;
            v.cost=adj[u.node][i].cost+u.cost;
            if(dist[v.node]>v.cost)
            {
                dist[v.node]=v.cost;
                q.push(v);
            }
        }
    }
}

int main ()
{
    int test,t=0,i,n,s,ti,k,a,b,c,ans;
    sci1(test);
    while(test--)
    {
        if(t++)
            cout<<endl;
        sci3(n,s,ti);
        for(i=1;i<=n;i++)
            {
                dist[i]=inf;
                clr(adj[i]);
            }
        sci1(k);
        while(k--)
        {
            sci3(a,b,c);
            adj[b].pb({a,c});
        }
        dj(s);
        ans=0;
        for(i=1;i<=n;i++)
        {
            if(dist[i]<=ti)
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}


