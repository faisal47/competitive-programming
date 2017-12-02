#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <stack>
#include <utility>
#include <queue>
#include <algorithm>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define FOR_0(i,n) for(i=0;i<n;i++)
#define FOR_1(i,n) for(i=1;i<=n;i++)
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sz 510
using namespace std;
struct node
{
    int a,b,c;
};
vec_<node>nodes;
vec_<int>edges[sz],cost[sz];
int p,q,n,s,par[sz],dist[sz],col[sz],i;
void init()
{
    clr(nodes);
    for(i=0; i<n; i++)
    {
        par[i]=i;
        dist[i]=inf;
        col[i]=0;
        clr(edges[i]);
        clr(cost[i]);
    }
}
int find_parent(int a)
{
    if(par[a]==a)
        return a;
    else
        return par[a]=find_parent(par[a]);
}
bool sign(node a,node b)
{
    return a.c<b.c;
}
void make_mst()
{
    sort(nodes.begin(),nodes.end(),sign);
    for(i=0; i<nodes.size(); i++)
    {
        p=find_parent(nodes[i].a);
        q=find_parent(nodes[i].b);
        if(p==q)
            continue;
        else
        {
            par[p]=q;
            edges[nodes[i].a].pb(nodes[i].b);
            edges[nodes[i].b].pb(nodes[i].a);
            cost[nodes[i].a].pb(nodes[i].c);
            cost[nodes[i].b].pb(nodes[i].c);
        }
    }
}
struct data
{
    int node,cost;
    bool operator < (const data& p)const
    {
        return cost < p.cost;
    }
};
void dj(int s)
{
    dist[s]=0;
    priority_queue<data>q;
    data u,v;
    u.node=s;
    u.cost=0;
    q.push(u);
    col[u.node]=1;
    while(!q.empty())
    {
        u=q.top();
        q.pop();
        for(i=0;i<edges[u.node].size();i++)
        {
            v.node=edges[u.node][i];
            v.cost=cost[u.node][i];
            if(dist[u.node]!=inf)
            v.cost=max(dist[u.node],v.cost);
            if(dist[v.node]==inf  && !col[v.node])
            {
                col[v.node]=1;
                dist[v.node]=v.cost;
                q.push(v);
            }
        }
    }
}
int main ()
{
    int j,test,t=1,m,k;
    sci1(test);
    while(test--)
    {
        sci2(n,m);
        init();
        while(m--)
        {
            sci3(i,j,k);
            nodes.pb({i,j,k});
        }
        sci1(s);
        make_mst();
        dj(s);
        printf("Case %d:\n",t++);
        for(i=0; i<n; i++)
            if(dist[i]==inf)
                printf("Impossible\n");
            else
                printf("%d\n",dist[i]);
    }
    return 0;
}
