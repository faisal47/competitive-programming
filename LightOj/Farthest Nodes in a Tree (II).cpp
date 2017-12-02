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
#define scll1(a) scanf(" %lld",&a)
#define scll2(a,b) scanf(" %lld %lld",&a,&b)
#define scll3(a,b,c) scanf(" %lld %lld %lld",&a,&b,&c)
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
#define mt 30010
using namespace std;

vec_<int>adj[mt],dist[mt];
int col[mt],cost1[mt],cost2[mt],fl;

int bfs(int s)
{
    queue<int>q;
    q.push(s);
    int i,dur=0,ret,v;
    col[s]=fl;
    cost1[s]=0;
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        for(i=0;i<sz(adj[s]);i++)
        {
            v=adj[s][i];
            if(col[v]!=fl)
            {
                col[v]=fl;
                q.push(v);
                cost1[v]=cost1[s]+dist[s][i];
                if(cost1[v]>dur)
                {
                    dur=cost1[v];
                    ret=v;
                }
            }
        }
    }
    return ret;
}

int bfs2(int s)
{
    queue<int>q;
    q.push(s);
    int i,dur=0,ret,v;
    col[s]=fl;
    cost2[s]=0;
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        for(i=0;i<sz(adj[s]);i++)
        {
            v=adj[s][i];
            if(col[v]!=fl)
            {
                col[v]=fl;
                q.push(v);
                cost2[v]=cost2[s]+dist[s][i];
                if(cost2[v]>dur)
                {
                    dur=cost2[v];
                    ret=v;
                }
            }
        }
    }
    return ret;
}


int main ()
{
    int n,test,t=1,i,a,b,c,s1,s2;
    sci1(test);
    while(test--)
    {

        fl=1;
        sci1(n);
        for(i=0;i<n;i++)
        {
            clr(adj[i]);
            clr(dist[i]);
            col[i]=0;
        }
        for(i=0;i<n-1;i++)
        {
            sci3(a,b,c);
            adj[a].pb(b);
            dist[a].pb(c);
            adj[b].pb(a);
            dist[b].pb(c);
        }
        s1=bfs(0);
        fl=2;
        s2=bfs(s1);
        cost1[s1]=cost1[s2];
        fl=3;
        s1=bfs2(s2);
        cost2[s2]=cost2[s1];
        printf("Case %d:\n",t++);
        for(i=0;i<n;i++)
        printf("%d\n",max(cost1[i],cost2[i]));
    }
    return 0;
}


