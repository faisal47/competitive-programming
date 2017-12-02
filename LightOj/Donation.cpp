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
#define mt 55
using namespace std;
struct rast
{
    int a,b,cost;
};
vec_<rast>ras;
bool comp(rast a,rast b)
{
    return a.cost<b.cost;
}

int par[mt];

int find_parent(int a)
{
    if(par[a]==a)return a;
    return par[a]=find_parent(par[a]);
}

int ans;
bool col[mt];
vec_<int>con[mt];
void make_edge(int s)
{
    int a=ras[s].a;
    int b=ras[s].b;
    int u=find_parent(a);
    int v=find_parent(b);
    if(u==v || a==b)
    {
        ans+=ras[s].cost;
        return;
    }
    par[u]=v;
    con[u].pb(v);
    con[v].pb(u);
}

void dfs(int a)
{
    int i,u;
    for(i=0;i<sz(con[a]);i++)
    {
        u=con[a][i];
        if(!col[u])
        {
            col[u]=1;
            dfs(u);
        }
    }
}

int main ()
{
    bool flag=0;
    int i,j,test,t=1,k,n;
    sci1(test);
    while(test--)
    {
        sci1(n);
        clr(ras);
        ans=0;
        flag=0;
        for(i=1; i<=n; i++)
        {
            par[i]=i;
            col[i]=0;
            clr(con[i]);
            for(j=1; j<=n; j++)
            {
                sci1(k);
                if(!k)continue;
                ras.pb( {i,j,k});
            }
        }
        sort_m(ras);
        for(i=0;i<sz(ras);i++)make_edge(i);

        col[1]=1;dfs(1);

        for(i=1;i<=n;i++)
        if(!col[i])
        {
            flag=1;
            break;
        }
        printf("Case %d: ",t++);
        if(flag)
        cout<<-1<<endl;
        else
        cout<<ans<<endl;
    }
    return 0;
}

