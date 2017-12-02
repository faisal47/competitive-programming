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
struct  data
{
    int node;
    bool hoise;
};
vec_ <int>v[sz];
int pre[sz],ti,cnt,root;
data dfs(int u,int p)
{
    data a,d;
    if(pre[u]!=0)
    {
        a.node=pre[u];
        a.hoise=0;
        return a;
    }
    int tim=ti++;
    int next,c=0,i,b=0;
    pre[u]=tim;
    d.hoise=0;
    for(i=0; i<v[u].size(); i++)
    {
        next=v[u][i];
        if(next!=p && pre[next]<pre[u])
        {
            a=dfs(next,u);
            d.hoise|=a.hoise;
            tim=min(tim,a.node);
            if(a.hoise)
                c++;
            if(a.node>pre[u])
            b++;
        }
    }
    if(tim==pre[u] && u!=root && c==0)
    cnt++,d.hoise=1;
    if(u==root && b==1 && c==1)
    cnt++;
    d.node=tim;
    return d;
}
int main ()
{
    int i,j,n,test,t,m;
    cin>>test;
    for(t=1; t<=test; t++)
    {
        cnt=0;
        ti=1;
        cin>>n>>m;
        for(i=0; i<n; i++)
        {
            v[i].clear();
            pre[i]=0;
        }
        while(m--)
        {
            cin>>i>>j;
            v[i].pb(j);
            v[j].pb(i);
        }
        for(i=0; i<n; i++)
        {
            if(pre[i]==0)
            {
                root=i;
                dfs(i,i);
            }
        }
        if(cnt%2)
            cnt=(cnt/2)+1;
        else
            cnt/=2;
        printf("Case %d: %d\n",t,cnt);
    }
    return 0;
}
