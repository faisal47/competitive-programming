
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
#define sort_n(a) sort(a.begin(),a.end())
#define sort_m(a) sort(a.begin(),a.end(),comp)
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
#define pri1(a) printf("%d ",a)
#define pri2(a,b) printf("%d %d ",a,b)
#define prll1(a) printf("%I64d ",a)
#define prll2(a,b) printf("%I64d %I64d ",a,b)
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define mt 110
using namespace std;
struct data //for dj()
{
   int node,cost,khaisi;
   bool operator < (const data& p) const
   {
       return cost > p.cost;
   }
};

int dist[mt],limit;
vec_<int>cost[mt],edge[mt];
int ans=inf,p[mt];
void dj()
{
    priority_queue<data>q;
    data u,v;
    u.node=0;
    u.cost=0;
    u.khaisi=0;
    q.push(u);
    dist[0]=0;
    while(!q.empty())
    {
        u=q.top();
        q.pop();
        int d=dist[u.node];
        for(int i=0;i<sz(edge[u.node]);i++)
        {
            v.node=edge[u.node][i];
            v.cost=cost[u.node][i]+d;
            v.khaisi=p[.node]+u.khaisi;
            if(v.cost<dist[v.node])
            {
                dist[v.node]=v.cost;
                q.push(v);
                if(v.khaisi>=limit)
                ans=min(ans,v.cost);
            }
        }
    }
}

int main ()
{
    int test,n,a,b,c,i,sum,m;
    sci1(test);
    while(test--)
    {
        sum=0;
        sci2(n,m);
        ans=inf;
        for(i=0;i<=n;i++)
        {
            clr(edge[i]);
            clr(cost[i]);
            dist[i]=inf;
        }
        while(m--)
        {
            sci3(a,b,c);
            edge[a].pb(b);
            cost[a].pb(c);

            edge[b].pb(a);
            cost[b].pb(c);
        }
        for(i=1;i<=n;i++)
        {
            sci1(a);
            sum+=a;
            p[i]=a;
        }

        limit=sum/2;
        if(sum&1)
        limit++;

        dj();
        if(ans==inf)
        cout<<"impossible\n";
        else
        printf("%d\n",ans);
    }
    return 0;
}

