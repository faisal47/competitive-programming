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
#define ms(a,b) memset(a,b,sizeof(a))
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sci3(a,b,c) scanf(" %d %d %d",&a,&b,&c)
#define sz(a) a.size()
#define mt 105
using namespace std;
struct rast
{
    int a,b,cost;
};
vec_<rast>rasta;
int par[mt];
bool comp1(rast a,rast b)
{
    return a.cost<b.cost;
}
bool comp2(rast a,rast b)
{
    return a.cost>b.cost;
}
int ans1,ans2;
int find_parent(int a)
{
    if(par[a]==a)return a;
    return par[a]=find_parent(par[a]);
}
void make_edge(int s)
{
    int a=rasta[s].a;
    int b=rasta[s].b;
    int u=find_parent(a);
    int v=find_parent(b);
    if(u==v)return;
    par[u]=v;
    ans1+=rasta[s].cost;
}
int main ()
{
    int test,t=1,n,a,b,c,i;
    sci1(test);
    while(test--)
    {
        sci1(n);
        clr(rasta);
        for(i=0;i<=n;i++)par[i]=i;
        while(1)
        {
            sci3(a,b,c);
            if(a==0 && b==0 && c==0)break;
            rasta.pb({a,b,c});
        }
        sort(rasta.begin(),rasta.end(),comp1);
        ans1=0;
        for(i=0;i<sz(rasta);i++)
            make_edge(i);
        ans2=ans1;
        ans1=0;
        for(i=0;i<=n;i++)par[i]=i;
        sort(rasta.begin(),rasta.end(),comp2);
        for(i=0;i<sz(rasta);i++)
            make_edge(i);
        ans2+=ans1;
        printf("Case %d: ",t++);
        if(ans2&1)
        printf("%d/2\n",ans2);
        else
        printf("%d\n",ans2/2);
    }
    return 0;
}

