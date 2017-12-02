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
#define mt 55
using namespace std;
struct data //for dj()
{
   int node,cost,alt;
   bool operator < (const data& p) const
   {
       return cost > p.cost;
   }
};

vec_<int>edge[mt],cost[mt];
int alt[mt],visa[mt],dist1[mt],par[mt],dist2[mt],n;
bool col[mt];

int dj1()
{
    priority_queue<data>q;
    data u,v;
    int i;
    u.node=1;
    u.alt=0;
    u.cost=0;
    dist1[1]=0;
    q.push(u);
    int alt1,alt2;
    while(!q.empty())
    {
        u=q.top();
        q.pop();
        int d=dist1[u.node];
        alt1=u.alt;
        for(i=0;i<sz(edge[u.node]);i++)
        {
            v.node=edge[u.node][i];
            v.cost=cost[u.node][i]+d+visa[v.node];
            alt2=alt[v.node];
            v.alt=alt2;
            if(dist1[v.node]>v.cost && alt1<=alt2)
            {
               // cout<<u.node<<" "<<v.node<<endl;
                dist1[v.node]=v.cost;
                q.push(v);
                par[v.node]=u.node;
            }
        }
    }
    //cout<<dist1[n]<<endl;
    return dist1[n];
}

void color_path(int s)
{
    //cout<<s<<endl;

    if(s==1)
    {
        col[s]=1;
        return;
    }

    col[s]=1;

    return color_path(par[s]);
}

int dj2()
{
    priority_queue<data>q;
    data u,v;
    int i;
    u.node=n;
    u.alt=1000;
    u.cost=0;
    dist2[n]=0;
    q.push(u);
    int alt1,alt2;
    while(!q.empty())
    {
        u=q.top();
        q.pop();
        int d=dist2[u.node];
        alt1=u.alt;
        for(i=0;i<sz(edge[u.node]);i++)
        {
            v.node=edge[u.node][i];
            v.cost=cost[u.node][i]+d+visa[v.node];
            if(col[v.node])
            v.cost-=visa[v.node];
            alt2=alt[v.node];
            v.alt=alt2;
            if(dist2[v.node]>v.cost && alt1>=alt2)
            {
                dist2[v.node]=v.cost;
                q.push(v);
            }
        }
    }
    return dist2[1];
}

int main ()
{
    int i,j,m,k,a,b,c,ans1,ans2;
    while(cin>>n>>m && n && m)
    {
        for(i=1;i<=n;i++)
        {
            clr(edge[i]);
            clr(cost[i]);
            dist1[i]=inf;
            dist2[i]=inf;
            par[i]=i;
            col[i]=0;
            if(i==1)
            {
                visa[i]=0;
                alt[i]=0;
            }
            else if(i==n)
            {
                visa[i]=0;
                alt[i]=1000;
            }
            else
            {
                cin>>visa[i]>>alt[i];
            }
        }
        while(m--)
        {
            cin>>a>>b>>c;
            cost[a].pb(c);
            edge[a].pb(b);
        }
        ans1=dj1();
       // cout<<"hello == "<<ans1<<endl;
        if(ans1==inf)
        {
            cout<<-1<<endl;
            continue;
        }
        else
        {
           // cout<<"hello == "<<ans1<<endl;
            color_path(n);
            ans2=dj2();
            if(ans2==inf)
            {
                cout<<-1<<endl;
                continue;
            }
            cout<<ans1+ans2<<endl;
        }
    }
    return 0;
}


