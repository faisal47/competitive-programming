#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct r
{
    int start,end,cost;
};
map<string,int>m;
vector<int>v[405];
bool color[405];
int par[405],cost;
r railway[79810];
bool sign(const r &a,const r &b)
{
    return a.cost<b.cost;
}
int ja(int r)
{
    if(par[r]==r)
    return r;
    else
    return par[r]=ja(par[r]);
}
void uni(int i)
{
    int u1=ja(railway[i].start);
    int v1=ja(railway[i].end);
    if(u1==v1)
    return;
    par[u1]=v1;
    v[railway[i].start].push_back(railway[i].end);
    v[railway[i].end].push_back(railway[i].start);
    cost+=railway[i].cost;
    return;
}
void bfs(int start)
{
    color[start]=1;
    queue<int>q;q.push(start);
    int i;
    while(!q.empty())
    {
      start=q.front();
      q.pop();
      for(i=0;i<v[start].size();i++)
      {
          if(color[v[start][i]]==0)
          {
              color[v[start][i]]=1;
              q.push(v[start][i]);
          }
      }
    }
    return;
}
int main ()
{
    int a,b,c,i,flag;
    string s1,s2;
    while(cin>>a>>b)
    {
        if(a==0&&b==0)
        break;
        c=1;flag=cost=0;
        for(i=1;i<=a;i++)
        {
            color[i]=0;
            par[i]=i;
            v[i].clear();
        }
        m.clear();
        for(i=0;i<a;i++)
        {
            cin>>s1;
           m[s1]=c++;
        }
        for(i=0;i<b;i++)
        {
           cin>>s1>>s2>>railway[i].cost;
           railway[i].start=m.find(s1)->second;
           railway[i].end=m.find(s2)->second;
        }
        sort(railway,railway+b,sign);
        for(i=0;i<b;i++)
        uni(i);
        cin>>s1;
        bfs(m.find(s1)->second);
        for(i=1;i<=a;i++)
        if(color[i]==0)
        {
            flag=1;
            break;
        }
        if(flag==1)
        cout<<"Impossible\n";
        else
        cout<<cost<<endl;
    }
    return 0;
}
