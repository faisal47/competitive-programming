#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct data
{
    int city,dist;
    bool operator < (const data& p) const
    {
        return dist>p.dist;
    }
};
vector<int>node[15],cost[15],path;
int d,n,dist[15],par[15],inf=123456789,i;
void dj(int start)
{
//    for(i=1;i<=n;i++)
//    dist[i]=inf;
    priority_queue<data>q;
    data u,v;
    dist[start]=0;
    u.city=start;
    u.dist=0;
    q.push(u);
    while(!q.empty())
    {
        u=q.top();q.pop();
        d=u.dist;
        for(i=0;i<node[u.city].size();i++)
        {
            v.city=node[u.city][i];
            v.dist=d+cost[u.city][i];
            if(v.dist<dist[v.city])
            {
                par[v.city]=u.city;
                dist[v.city]=v.dist;
                q.push(v);
            }
        }
    }
    return;
}
int main ()
{
    int test=1,a,b,i,c;
    while(cin>>n)
    {
        if(n==0)
        break;
        for(i=1;i<=n;i++)
        {
            cin>>c;
            dist[i]=inf;
            par[i]=i;
            cost[i].clear();
            node[i].clear();
            while(c--)
            {
                cin>>a>>b;
                node[i].push_back(a);
                cost[i].push_back(b);
            }
        }
        cin>>a>>b;
        dj(a);
        i=b;
        path.clear();
        path.push_back(b);
        while(1)
        {
            if(par[i]==i)
            break;
            path.push_back(par[i]);
            i=par[i];
        }
        printf("Case %d: Path =",test++);
        for(i=path.size()-1;i>=0;i--)
        cout<<" "<<path[i];
        printf("; %d second delay\n",dist[b]);
    }
    return 0;
}
