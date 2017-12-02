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

#define mt 260

int dist[mt],sum[mt],dist1[mt][mt];

struct data
{
    int city,dist;

    bool operator < (const data &p) const
    {
        return dist > p.dist;
    }
};

vec_<data>adj[mt];

void init(int n)
{
    int i;
    for(i=0;i<n;i++)
    clr(adj[i]),sum[i]=0,dist[i]=inf;
}

void dj(int s,int c)
{
    priority_queue<data>q;
    q.push({s,0});
    dist[s]=0;

    data u,v;
    int i;

   // cout<<"hello";

    while(!q.empty())
    {
        u=q.top();
        q.pop();

        for(i=0;i<sz(adj[u.city]);i++)
        {
            v=adj[u.city][i];
            v.dist+=u.dist;
            if(dist[v.city] > v.dist)
            {
                dist[v.city] = v.dist;
                if(v.city >= c)
                    q.push(v);
            }
        }
    }
}

int main ()
{
    int n,m,k,c;

    while(cin>>n>>m>>c>>k && (n || m || c || k))
    {
        init(n);

        int a,b,d;
        while(m--)
        {
            cin>>a>>b>>d;
            adj[a].pb({b,d});
            adj[b].pb({a,d});
            dist1[a][b]=dist1[b][a]=d;
        }

        int i;

        for(i=c-2;i>=0;i--)
            sum[i]=sum[i+1]+dist1[i][i+1];

        dj(k,c);

      //  cout<<"hello";

        int ans=inf;

        for(i=0;i<c;i++)
            ans=min(ans,sum[i]+dist[i]);

        cout<<ans<<endl;
    }

    return 0;
}

