#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int>nodes[2010],cost[2010];
struct data
{
  int city,cost;
  bool operator < (const data& p) const
  {
      return cost>p.cost;
  }
};
int m,n,k,a,b,ase[2010],cos[2010],inf=123456789;
void dj(int start)
{
    data u,v;
    int i,d;
    for(i=1;i<=n;i++)
    cos[i]=inf;
    priority_queue<data>q;
    cos[start]=0;
    u.city=start;
    u.cost=cos[start];
    q.push(u);
    while(!q.empty())
    {
        u=q.top();
        q.pop();
        d=u.cost;
        for(i=0;i<nodes[u.city].size();i++)
        {
            v.city=nodes[u.city][i];
            v.cost=cost[u.city][i]+d;
            if(v.cost<cos[v.city])
            {
                //cout<<v.city<<" "<<d+v.cost<<endl;
                cos[v.city]=v.cost;
                q.push(v);
            }
        }
    }
}
int main ()
{
    int t,test,i;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        cin>>n>>m>>k;
        for(i=1;i<=n;i++)
        {
            ase[i]=0;
            nodes[i].clear();
            cost[i].clear();
        }
        while(k--)
        {
            cin>>a;
            ase[a]=1;
        }
        while(m--)
        {
            cin>>a>>b;
            nodes[a].push_back(b);
            nodes[b].push_back(a);
            if(ase[a]==0)
            cost[b].push_back(1);
            else
            cost[b].push_back(0);
            if(ase[b]==0)
            cost[a].push_back(1);
            else
            cost[a].push_back(0);
        }
        cin>>k;
        printf("Case %d:\n",t);
        while(k--)
        {
            cin>>a>>b;
            if(a==b)
            {
                cout<<0<<endl;
                continue;
            }
            dj(a);
//            for(i=1;i<=n;i++)
//            cout<<cos[i]<<endl;
            if(cos[b]==inf)
            cout<<"-1"<<endl;
            else
           {
               if(ase[a]==0)
               cout<<cos[b]+1<<endl;
               else
               cout<<cos[b]<<endl;
           }
        }
        cout<<endl;
    }
    return 0;
}
