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
#define mt 10000+50
using namespace std;

vec_<int>edge[mt];
map<pii,int>ma;
int col[mt],low[mt],pre[mt];
int ti;
void dfs(int u,int p)
{
    int v,i;
    pre[u]=low[u]=ti;
    ti++;
    for(i=0;i<edge[u].size();i++)
    {
        v=edge[u][i];
        if(!pre[v])
        {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(pre[v]==low[v])
            {
                ma[mp(u,v)]=1;
                ma[mp(v,u)]=1;
            }
        }
        else if(v!=p)
        low[u]=min(low[u],pre[v]);
    }
}

bool nimu;
int col_kormu,mot;

void bfs(int s)
{
    queue<int>q;
    q.push(s);
    col_kormu=1;
    col[s]=col_kormu;

    while(!q.empty())
    {
        s=q.front();
        q.pop();
        //cout<<s<<endl;
        col_kormu=col[s];
        for(int i=0;i<sz(edge[s]);i++)
        {
            int v=edge[s][i];
            if(ma.find(mp(s,v))==ma.end() && !col[v])
            {
                mot++;
               // cout<<s<<" "<<v<<endl;
                if(col_kormu==1)
                col[v]=2;
                else
                col[v]=1;
                q.push(v);
            }
            else if(ma.find(mp(s,v))==ma.end() && col[v]==col_kormu)
                nimu=false;
        }
    }
}

int main ()
{
    int test,n,m,i,a,b,ans,t=1;
    sci1(test);
    while(test--)
    {

        sci2(n,m);
        clr(ma);
        ti=1;

        for(i=1;i<=n;i++)
        {
            low[i]=pre[i]=col[i]=0;
            clr(edge[i]);
        }

        while(m--)
        {
            sci2(a,b);
            a++,b++;
            edge[a].pb(b);
            edge[b].pb(a);
        }
        ans=0;
        for(i=1;i<=n;i++)
        if(!pre[i])dfs(i,i);
        for(i=1;i<=n;i++)
        if(!col[i])
        {
            mot=1;
            nimu=true;
            bfs(i);
            if(!nimu && mot>1)
            ans+=mot;
        }
        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}


