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
    bool operator < (const data &p) const
    {
        return cost > p.cost;
    }
};

vec_<data>adj[mt];
priority_queue<data>q;
dd arr[mt][3];

dd dur(dd x1,dd x2,dd y1,dd y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int dist[mt];

bool dj()
{
    while(!q.empty())q.pop();

    data u,v;
    dist[1]=0;
    q.push({1,0});
    int i;

    while(!q.empty())
    {
        u=q.top();
        q.pop();

        if(u.node==2)
            return 1;

        for(i=0; i<sz(adj[u.node]); i++)
        {
            v=adj[u.node][i];
            v.cost+=dist[u.node];
            if(dist[v.node] > v.cost)
            {
                dist[v.node] = v.cost;
                q.push(v);
            }
        }
    }

    return 0;
}

int main ()
{
    int i,j,n,m,k,d,e;
    dd w;

    while(scanf(" %d %d",&k,&m)==2)
    {
        scanf(" %lf %lf %lf",&arr[1][0],&arr[1][1],&arr[1][2]);
        scanf(" %lf %lf %lf",&arr[2][0],&arr[2][1],&arr[2][2]);

        scanf("%d",&n);

        n+=2;

        for(i=3; i<=n; i++)
            scanf(" %lf %lf %lf",&arr[i][0],&arr[i][1],&arr[i][2]);

        for(i=1; i<=n; i++)
            dist[i]=inf;

        for(i=1; i<=n; i++)
            for(j=i+1; j<=n; j++)
            {
                w=dur(arr[i][0],arr[j][0],arr[i][1],arr[j][1])-arr[i][2]-arr[j][2];

                d=ceil(w);

                e=d/m;
                if(d%m)
                    e++;

               // deb2(d,w);
                if(e<=k)
                {
                    adj[i].pb({j,e});
                    adj[j].pb({i,e});
                }
            }

        if(dj())
            pf("Larry and Ryan will escape!\n");
        else
            pf("Larry and Ryan will be eaten to death.\n");

        for(i=1; i<=n; i++)
            clr(adj[i]);
    }
    return 0;
}

