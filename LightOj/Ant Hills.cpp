#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <utility>
#include <queue>
#include <algorithm>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define ll long long
#define FOR_0(i,n) for(i=0;i<n;i++)
#define FOR_1(i,n) for(i=1;i<=n;i++)
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define eps 1E-7
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define sz 10010
using namespace std;
map<int,int>ma;
int low[sz],pre[sz],ti,c,root;
vec_ <int>edge[sz];
void dfs(int u,int p)
{
    int child=0,v,i;
    low[u]=pre[u]=ti;
    ti++;
    for(i=0;i<edge[u].size();i++)
    {
        v=edge[u][i];
        if(pre[v]==0)
        {
            //cout<<"jfd  "<<c<<endl;
            child++;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=pre[u] && u!=root && ma.find(u)==ma.end())
            {
                c++;
                ma[u]=1;
            }
        }
        else if(v!=p)
        {
            low[u]=min(low[u],pre[v]);
        }
        if(child>=2 && u==root && ma.find(u)==ma.end())
       {
            c++;
                ma[u]=1;
       }
    }
}
int main ()
{
    int i,j,test,t,n,m,a,b;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        clr(ma);
        c=0;ti=1;
        cin>>n>>m;
        for(i=1;i<=n;i++)
        {
            clr(edge[i]);
            low[i]=pre[i]=0;
        }
        while(m--)
        {
            cin>>a>>b;
            edge[a].pb(b);
            edge[b].pb(a);
        }
        for(i=1;i<=n;i++)
        {
            if(pre[i]==0)
            {
                root=i;
                dfs(i,i);
            }
        }
        printf("Case %d: %d\n",t,c);
    }
    return 0;
}

