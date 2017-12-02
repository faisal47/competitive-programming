#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int inf=100000000,n;
struct data
{
    int node,cost;
    bool operator < (const data& p) const
    {
        return cost > p.cost;
    }
};
vector<int>cost[20010],edge[20010];
int dist[20010];
int dj(int start,int end)
{
    int i;
    priority_queue<data>q;
    data u,v;
    u.node=start;
    u.cost=0;
    q.push(u);
    dist[start]=0;
    while(!q.empty())
    {
        u=q.top();
        q.pop();
        int d=dist[u.node];
        for(i=0;i<edge[u.node].size();i++)
        {
            v.node=edge[u.node][i];
            v.cost=cost[u.node][i]+d;
            if(dist[v.node]>v.cost)
            {
                dist[v.node]=v.cost;
                q.push(v);
            }
        }
    }
    return dist[end];
}
int main ()
{
    int test,i,t,result,m,s,e,s1,s2,c;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        cin>>n>>m>>s>>e;
        for(i=0;i<n;i++)
        {
            dist[i]=inf;
            edge[i].clear();
            cost[i].clear();
        }
        while(m--)
        {
            cin>>s1>>s2>>c;
            edge[s1].push_back(s2);
            edge[s2].push_back(s1);
            cost[s1].push_back(c);
            cost[s2].push_back(c);
        }
        result=dj(s,e);
        if(result<inf)
        printf("Case #%d: %d\n",t,result);
        else
        printf("Case #%d: unreachable\n",t);
    }
    return 0;
}
