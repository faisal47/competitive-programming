#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define sz 10010
using namespace std;
struct ou
{
    int a,b;
};
vec_ <ou>out;
vec_ <int>edge[sz];
int low[sz],pre[sz],ti;
ou out_rough;
void dfs(int u,int p)
{
    int v,i;
    pre[u]=low[u]=ti;
    ti++;
    for(i=0;i<edge[u].size();i++)
    {
        v=edge[u][i];
        if(pre[v]==-1)
        {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(pre[v]==low[v])
            {
                out_rough.a=u;
                out_rough.b=v;
                if(u>v)
                swap(out_rough.a,out_rough.b);
                out.pb(out_rough);
            }
        }
        else if(v!=p)
        low[u]=min(low[u],pre[v]);
    }
}
bool comp(ou a,ou b)
{
    if(a.a!=b.a)
    return a.a<b.a;
    return a.b<b.b;
}
int main ()
{
    int i,j,test,t,n,k,a,b;
    char c1,c2;
     scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        ti=1;
        clr(out);
         scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            clr(edge[i]);
            pre[i]=low[i]=-1;
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            scanf(" %c %d %c",&c1,&k,&c2);
            for(j=0;j<k;j++)
            {
                scanf("%d",&b);
                edge[a].pb(b);
                edge[b].pb(a);
            }
        }
        for(i=0;i<n;i++)
        {
            if(pre[i]==-1)
            dfs(i,i);
        }
        sort(out.begin(),out.end(),comp);
        printf("Case %d:\n%d critical links\n",t,out.size());
        for(i=0;i<out.size();i++)
        printf("%d - %d\n",out[i].a,out[i].b);
    }
    return 0;
}
