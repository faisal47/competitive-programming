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
#define mt 55<<1
using namespace std;
vec_<int>adj[mt];
int dist[mt][mt],i,j,k,e,res,col[mt],flow,par[mt],s;
void make_edge(int a,int b,int cost)
{
    if(dist[a][b])
    {
        dist[a][b]+=cost;
        return;
    }
    adj[a].pb(b);
    dist[a][b]=cost;
}
queue<int>q;
bool has_path()
{
    while(!q.empty())q.pop();
    ms(col,0);
    par[1]=-1;
    q.push(1);
    col[1]=1;
    while(!q.empty())
    {
        s=q.front();q.pop();
        for(i=0; i<sz(adj[s]); i++)
        {
            j=adj[s][i];
            if(!col[j] && dist[s][j]>0)
            {
                par[j]=s;
                if(j==e)return true;
                col[j]=1;
                q.push(j);
            }
        }
    }
    return false;
}
void visit_path(int e1)
{
    if(par[e1]==-1)return;
    int s1=par[e1];
    flow=min(flow,dist[s1][e1]);
    visit_path(s1);
    dist[s1][e1]-=flow;
    dist[e1][s1]+=flow;
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
    int n,m,mot;
//    sci1(test);
    while(sci2(n,m)==2)
    {
        if(n ==0 && m==0)
            break;
        int a;
        e=n+n;
        mot=(n<<1)+10;
        for(i=1; i<=mot; i++)
        {
            clr(adj[i]);
            for(j=1; j<=mot; j++)dist[i][j]=0;
        }
        for(i=1; i<=n; i++)
        {
            if(i==1 || i==n)
            {
                make_edge(i,i+n,inf);
                make_edge(i+n,i,0);
            }
            else
            {
                sci2(a,j);
                make_edge(a,a+n,j);
                make_edge(a+n,a,0);
            }
        }
        while(m--)
        {
            sci3(i,j,k);
            make_edge(i+n,j,k);
            make_edge(j,i+n,0);
            make_edge(j+n,i,k);
            make_edge(i,j+n,0);
        }
        printf("%d\n",max_flow());
    }
    return 0;
}
