#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct r
{
    int start,end,cost;
};
int arr[10005],totalcost,airports;
r road[100010];
bool color[10005];
vector<int>v[10005];
void bfs(int start)
{
    queue<int>q;
    int i;
    q.push(start);
    color[start]=1;
    while(!q.empty())
    {
        start=q.front();
        q.pop();
        for(i=0;i<v[start].size();i++)
        if(color[v[start][i]]==0)
        {
            q.push(v[start][i]);
            color[v[start][i]]=1;
        }
    }
}
int par(int r)
{
    if(arr[r]==r)
    return r;
    else
    return arr[r]=par(arr[r]);
}
void uni(int a,int b,int i,int d)
{
    int u1=par(a);
    int v1=par(b);
    if(u1==v1)
    return;
    arr[u1]=v1;
    v[a].push_back(b);
    v[b].push_back(a);
    if(road[i].cost<d)
    totalcost+=road[i].cost;
    else
    airports++;
}
bool sign(const r &a, const r &b)
{
    return a.cost < b.cost;
}
int main ()
{
    int i,test,j,n,m,k,a;
    cin>>test;
    for(i=1;i<=test;i++)
    {
        airports=totalcost=0;
        cin>>n>>m>>a;
        for(j=1;j<=n;j++)
        {
            v[j].clear();
            arr[j]=j;
            color[j]=0;
        }
        for(j=0;j<m;j++)
        cin>>road[j].start>>road[j].end>>road[j].cost;
        sort(road,road+m,sign);
        for(j=0;j<m;j++)
        uni(road[j].start,road[j].end,j,a);
        for(j=1;j<=n;j++)
        if(color[j]==0)
        {
            bfs(j);
            airports++;
        }
        printf("Case %d: %d %d\n",i,(totalcost+(airports*a)),airports);
    }
    return 0;
}

