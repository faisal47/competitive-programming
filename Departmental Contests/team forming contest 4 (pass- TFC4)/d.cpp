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
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci4(a,b,c,d) scanf("%d %d %d %d",&a,&b,&c,&d)
#define sz(a) a.size()
#define mt 110<<1
using namespace std;
int dist[mt][mt],s,e,res,s1a,par[mt],i,flag[mt],v,flow,s1;
queue<int>q;
vec_<int>adj[mt];
void make_edge(int from,int to,int cost)
{
    adj[from].pb(to);
    dist[from][to]=cost;
}
bool has_path()
{
    while(!q.empty())q.pop();
    q.push(s);
    ms(flag,0);
    par[s]=-1;
    flag[s]=1;
    while(!q.empty())
    {
        s1=q.front();
        q.pop();
        for(i=0; i<sz(adj[s1]); i++)
        {
            v=adj[s1][i];
            if(!flag[v] && dist[s1][v]>0)
            {
                flag[v]=1;
                q.push(v);
                par[v]=s1;
                if(v==e)return true;
            }
        }
    }
    return false;
}
void visit_path(int e1)
{
    if(par[e1]==-1)return;
    int u1=par[e1];
    flow=min(flow,dist[u1][e1]);
    visit_path(par[e1]);
    dist[u1][e1]-=flow;
    dist[e1][u1]+=flow;
}
int max_flow()
{
    res=0;
    while(has_path())
    {
        flow=inf;
        visit_path(e);
        res+=flow;
    }
    return res;
}
int main ()
{
    int test,n,m,mot,j;
    sci1(test);
    while(test--)
    {
        sci4(n,m,s,e);
        mot=(n<<1)+2;
        for(i=1; i<=mot; i++)
        {
            clr(adj[i]);
            for(j=1; j<=mot; j++)
                dist[i][j]=0;
        }
        for(i=1; i<=n; i++)
        {
            sci1(j);
            make_edge(i,i+n,j);
            make_edge(i+n,i,0);
        }
        make_edge(s,s+n,inf);
        make_edge(s+n,s,0);
        make_edge(e,e+n,inf);
        make_edge(e+n,e,0);
        while(m--)
        {
            sci2(i,j);
            make_edge(i+n,j,inf);
            make_edge(j,i+n,0);
            make_edge(j+n,i,inf);
            make_edge(i,j+n,0);
        }
        printf("%d\n",max_flow());
    }
    return 0;
}

