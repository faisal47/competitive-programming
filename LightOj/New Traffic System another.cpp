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
#define inf 123456789
#define ll long long
#define FOR_0(i,n) for(i=0;i<n;i++)
#define FOR_1(i,n) for(i=1;i<=n;i++)
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define sz 10010
using namespace std;
struct data //for dj()
{
   ll node,cost,nea_hoise;
   bool operator < (const data& p) const
   {
       return cost > p.cost;
   }
};
//ll bigmod(ll a,ll b,ll m)
//{
//    if(b == 0) return 1%m;
//    ll x = bigmod(a,b/2,m);
//    x = (x * x) % m;
//    if(b % 2 == 1) x = (x * a) % m;
//    return x;
//}
//ll gcd(ll a,ll b)
//{
//   if(b==0)
//   return a;
//   return gcd(b,a%b);
//}
ll dist[sz][12],n,puran,notun,nea_jabe;
struct edge
{
    ll node,cost;
    ll notun;
};
vec_ <edge>edges[sz];
ll dj()
{
    ll i,ucost;
    priority_queue<data>q;
    data u,v;
    dist[0][0]=u.node=u.cost=u.nea_hoise=0;
    q.push(u);
    while(!q.empty())
    {
        u=q.top();
        q.pop();
        ucost=dist[u.node][u.nea_hoise];
        if(u.node==n-1)
        return ucost;
        for(i=0;i<edges[u.node].size();i++)
        {
            v.node=edges[u.node][i].node;
            v.cost=edges[u.node][i].cost+ucost;
            v.nea_hoise=u.nea_hoise+edges[u.node][i].notun;
            if(v.nea_hoise<=nea_jabe && v.cost<dist[v.node][v.nea_hoise])
            {
                dist[v.node][v.nea_hoise]=v.cost;
                q.push(v);
            }
        }
    }
    return inf;
}
int main ()
{
    ll i,test,t,ans,s,e,j,cost;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        cin>>n>>puran>>notun>>nea_jabe;
        for(i=0;i<=n;i++)
            {
                clr(edges[i]);
                for(j=0;j<12;j++)
                dist[i][j]=inf;
            }
        for(i=0;i<puran;i++)
        {
            cin>>s>>e>>cost;
            edges[s].pb(edge{e,cost,0});
        }
        for(i=0;i<notun;i++)
        {
            cin>>s>>e>>cost;
            edges[s].pb(edge{e,cost,1});
        }
        ans=dj();
        if(ans>=inf)
        printf("Case %lld: Impossible\n",t);
        else
        printf("Case %lld: %lld\n",t,ans);
    }
    return 0;
}

