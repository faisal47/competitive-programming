
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

#define mt 700

int dist[mt][2];

struct data
{
    int node,cost,flag;
    bool operator < (const data &p)const
    {
        return cost>p.cost;
    }
};

struct rasta1
{
    int node,cost;
};

vec_<rasta1>adj[mt];

int n;

int dj(int s)
{
    dist[s][0]=0;
    priority_queue<data>q;

    q.push({0,0,0});

    data u,v;
    int i;

    while(!q.empty())
    {
        u=q.top();
        q.pop();
        if(u.node==n-1 && !u.flag)
            return u.cost;
        u.cost=dist[u.node][u.flag];

        for(i=0;i<sz(adj[u.node]);i++)
        {
            v.node=adj[u.node][i].node;
            v.cost=u.cost+adj[u.node][i].cost;

            v.flag=!u.flag;
            if(dist[v.node][v.flag]>v.cost)
            {
                dist[v.node][v.flag]=v.cost;
                q.push(v);

//                if(v.node==n-1 && !v.flag)
//                return dist[n-1][v.flag];
            }
        }
    }
    return inf;
}

int main ()
{
    int i,a,b,c,ans,t=1,m;
    while(cin>>n>>m)
    {
        for(i=0; i<n;i++)
        {
            dist[i][0]=inf;
            dist[i][1]=inf;
            clr(adj[i]);
        }

        while(m--)
        {
            cin>>a>>b>>c;
            adj[a].pb({b,c});
            adj[b].pb({a,c});
        }

        ans=dj(0);

        pf("Set #%d\n",t++);
        if(ans>=inf)
            pf("?\n");
        else
            pf("%d\n",ans);
    }
    return 0;
}


