#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
int path[1010][1010],m,n,dist[1010][1010],inf=123456789;
struct jayga
{
  int x,y,cost;
  bool operator < (const jayga& p) const
  {
      return cost > p.cost;
  }
};
int dj()
{
    int x[]={0,-1,0,1};
    int y[]={-1,0,1,0};
    priority_queue<jayga>q;
    jayga u,v;
    int d,i,j;
    u.x=0;
    u.y=0;
    u.cost=0;
    dist[0][0]=path[0][0];
    q.push(u);
    while(!q.empty())
    {
        u=q.top();q.pop();
        d=dist[u.x][u.y];
       // cout<<u.x<<" "<<u.y<<endl;
        for(i=0;i<4;i++)
        {
            v.x=u.x+x[i];
            v.y=u.y+y[i];
            if(v.x>=0&&v.y>=0&&v.x<m&&v.y<n)
            {
                v.cost=path[v.x][v.y]+d;
                if(v.cost<dist[v.x][v.y])
                {
                    dist[v.x][v.y]=v.cost;
                    q.push(v);
                }
            }
        }
    }
//    for(i=0;i<m;i++)
//    for(int j=0;j<n;j++)
//    cout<<dist[i][j]<<endl;
    return dist[m-1][n-1];
}
int main ()
{
    int test,i,j;
    cin>>test;
    while(test--)
    {
        cin>>m>>n;
        for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            dist[i][j]=inf;
            cin>>path[i][j];
        }
        cout<<dj()<<endl;
    }
    return 0;
}
