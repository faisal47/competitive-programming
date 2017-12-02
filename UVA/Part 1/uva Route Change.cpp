#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct  data
{
    int node,cost;
    bool operator < (const data& p) const
    {
        return cost>p.cost;
    }
};
vector<int>node[300],cost[300];
int dist[300],inf=123456789;
void dj(int s,int e,int n)
{
    int i,d;
    for(i=0; i<n; i++)
        dist[i]=inf;
    data u,v;
    priority_queue<data>q;
    u.node=s;
    u.cost=0;
    dist[s]=0;
    q.push(u);
    while(!q.empty())
    {
        u=q.top();
        q.pop();
        d=u.cost;
        if(u.node<=e)
        {
            for(i=0; i<node[u.node].size(); i++)
            {
                if(node[u.node][i]==(u.node+1))
                {
                    v.cost=d+cost[u.node][i];
                    v.node=node[u.node][i];
                    if(v.cost<dist[v.node])
                    {
                        dist[v.node]=v.cost;
                        q.push(v);
                    }
                }
            }
        }
        else
        {
            for(i=0; i<node[u.node].size(); i++)
            {

                v.cost=d+cost[u.node][i];
                v.node=node[u.node][i];
                if(v.cost<dist[v.node])
                {
                    dist[v.node]=v.cost;
                    q.push(v);
                }

            }
        }
    }
}
int main ()
{
    int n,m,c,k,i,a,b,d;
    while(cin>>n>>m>>c>>k)
    {
        if(n==0&&m==0&&c==0&&k==0)
            break;
        for(i=0; i<n; i++)
        {
            node[i].clear();
            cost[i].clear();
        }
        while(m--)
        {
            cin>>i>>a>>b;
            node[i].push_back(a);
            node[a].push_back(i);
            cost[i].push_back(b);
            cost[a].push_back(b);
        }
        dj(k,c-1,n);
        cout<<dist[c-1]<<endl;;
    }
    return 0;
}
