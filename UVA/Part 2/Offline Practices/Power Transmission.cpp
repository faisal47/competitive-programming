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
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sz(a) a.size()
#define mt 115<<1
using namespace std;
int dist[mt][mt],i,s,e,res,flow,flag[mt],s1,v,par[mt];
vec_<int>adj[mt];
void make_edge(int a,int b,int cost)
{
    if(dist[a][b])
    {
        dist[a][b]+=cost;return;
    }
    adj[a].pb(b);
    dist[a][b]=cost;
}
queue<int>q;
bool has_path()
{
    while(!q.empty())q.pop();
    q.push(0);
    par[0]=-1;
    ms(flag,0);
    flag[0]=1;
    while(!q.empty())
    {
        s1=q.front();q.pop();
        for(i=0;i<sz(adj[s1]);i++)
        {
            v=adj[s1][i];
            if(!flag[v] && dist[s1][v]>0)
            {
                par[v]=s1;
                if(v==e)return true;
                q.push(v);
                flag[v]=1;
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
    visit_path(u1);
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
    int j,test,t=1,mot,n,n1;
//    sci1(test);
    while(sci1(n)==1)
    {

        n1=n;
        mot=(n<<1)+1;
        e=mot;
        for(i=0; i<mot+10; i++)
        {
            clr(adj[i]);
            for(j=0; j<mot+10; j++)
                dist[i][j]=0;
        }
        for(i=1; i<=n; i++)
        {
            sci1(mot);
            make_edge(i,i+n1,mot);
            make_edge(i+n1,i,0);
        }
        sci1(n);
        while(n--)
        {
            sci3(i,j,mot);
            make_edge(i+n1,j,mot);
            make_edge(j,i+n1,0);
        }
        sci2(n,mot);
        while(n--)
        {
            sci1(j);
            make_edge(0,j,inf);
            make_edge(j,i,0);
        }
        while(mot--)
        {
            sci1(j);
            make_edge(j+n1,e,inf);
            make_edge(e,j+n1,0);
        }
        printf("%d\n",max_flow());
    }
    return 0;
}

