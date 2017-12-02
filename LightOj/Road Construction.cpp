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
#define mt 110
using namespace std;
map<string,int>ma;
struct rast
{
    int a,b,cost;
};
vec_<rast>ras;
bool col[mt],col2[mt];
int par[mt];
int ans;
vec_<int>con[mt];
int find_parent(int s)
{
    if(par[s]==s)return s;
    return par[s]=find_parent(par[s]);
}
void make_edge(int s)
{
    int a=ras[s].a;
    int b=ras[s].b;
    int u=find_parent(a);
    int v=find_parent(b);
    if(u==v)return;
    col[a]=col[b]=1;
    par[u]=v;
    con[u].pb(v);
    con[v].pb(u);
    ans+=ras[s].cost;
}

bool comp(rast a,rast b)
{
    return a.cost<b.cost;
}

void dfs(int s)
{
    int i,u;
    for(int i=0;i<sz(con[s]);i++)
    {
        u=con[s][i];
        if(!col2[u])
        {
            col2[u]=1;
            dfs(u);
        }
    }
}

int main ()
{
    int test,t=1,m,a,b,c,d,i;
    bool b_flag;
    string a1,b1;
    sci1(test);
    while(test--)
    {
        ans=0;
        b_flag=0;
        clr(ma);
        clr(ras);
        sci1(m);
        d=1;
        while(m--)
        {
            cin>>a1>>b1>>c;
            if(ma.find(a1)==ma.end())
            ma[a1]=d++;
            if(ma.find(b1)==ma.end())
            ma[b1]=d++;
            ras.pb({ma[a1],ma[b1],c});
        }
        sort_m(ras);

        for(i=1;i<d;i++)
        {
            par[i]=i;
            col[i]=0;
            col2[i]=0;
            clr(con[i]);
        }

        for(i=0;i<sz(ras);i++)make_edge(i);

        col[1]=1;

        dfs(1);

        for(i=1;i<d;i++)
        if(!col2[i])
        {
            b_flag=1;
            break;
        }

        printf("Case %d: ",t++);
        if(b_flag)
        cout<<"Impossible\n";
        else
        cout<<ans<<endl;
    }
    return 0;
}

