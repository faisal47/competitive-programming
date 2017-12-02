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
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define sci1(a) scanf("%d",&a)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sz(a) a.size()
using namespace std;
vec_<int>v1[102],v2[102];
int cost,dist[102][102];
bool flag;
bool col[110];
void dfs(int u)
{
    col[u]=1;
    int v,i;
    for(i=0; i<sz(v1[u]); i++)
    {
        v=v1[u][i];
        if(!col[v])
        {
            flag=1;
            dfs(v);
            return;
        }
    }
    for(i=0; i<sz(v2[u]); i++)
    {
        v=v2[u][i];
        if(!col[v])
        {
            cost+=dist[u][v];
            flag=1;
            dfs(v);
            return;
        }
        else if(v==1 && flag)
        {
            cost+=dist[u][v];
            return;
        }
    }
}
int main ()
{
    int n,test,t=1,a,b,i,c,mot;
    sci1(test);
    while(test--)
    {
        mot=cost=0;
        sci1(n);
        for(i=1; i<=n; i++)
        {
            col[i]=0;
            clr(v1[i]);
            clr(v2[i]);
        }
        for(i=1; i<=n; i++)
        {
            sci3(a,b,c);
            dist[a][b]=dist[b][a]=c;
            v1[a].pb(b);
            v2[b].pb(a);
            mot+=c;
        }
        flag=0;
        col[1]=1;
        if(sz(v1[1]))
            dfs(v1[1][0]);
        else
        {
            cost+=dist[1][v2[1][0]];
            dfs(v2[1][0]);
        }
        mot-=cost;
        printf("Case %d: %d\n",t++,min(mot,cost));
    }
    return 0;
}

