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
#define inf 123456789123456789
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
    int node,cost;
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
struct edge
{
    int node,cost;
    bool notun;
};
vec_ <edge>edges[sz];
ll dist[sz][2],use_korte_parbi,puran,notun,n;
ll dj()
{
    ll i,koyta;
    priority_queue<data>q;
    data u,v;
    dist[0][0]=0;
    dist[0][1]=0;
    u.node=0;
    u.cost=0;
    q.push(u);
    while(!q.empty())
    {
        u=q.top();
        q.pop();
        koyta=dist[u.node][1];
        for(i=0; i<edges[u.node].size(); i++)
        {
            // cout<<"jdf "<<edges[u.node][i].cost<<endl;
            v.node=edges[u.node][i].node;
            v.cost=edges[u.node][i].cost + u.cost;
            if(edges[u.node][i].notun && koyta+1<=use_korte_parbi && dist[v.node][0]>v.cost)
            {
             //   cout<<v.node<<" "<<v.cost<<" "<<koyta<<endl;
                dist[v.node][0]=v.cost;
                dist[v.node][1]=koyta+1;
                q.push(v);
            }
            else if(dist[v.node][0]>v.cost && !edges[u.node][i].notun)
            {
               // cout<<v.node<<" "<<v.cost<<" "<<koyta<<endl;
                dist[v.node][0]=v.cost;
                dist[v.node][1]=koyta;
                q.push(v);
            }
        }
    }
//    for(i=0;i<n;i++)
//    cout<<dist[i]<<endl;
    return dist[n-1][0];
}
int main ()
{
    ll i,t,test,s,e,ans;
    edge edge_rough;
    cin>>test;
    for(t=1; t<=test; t++)
    {
        cin>>n>>puran>>notun>>use_korte_parbi;
        for(i=0; i<n; i++)
        {
            clr(edges[i]);
            dist[i][0]=inf;
            dist[i][1]=0;
        }
        for(i=0; i<puran; i++)
        {
            cin>>s>>e>>edge_rough.cost;
            edge_rough.notun=0;
            edge_rough.node=s;
            edges[e].pb(edge_rough);
            edge_rough.node=e;
            edges[s].pb(edge_rough);
        }
        for(i=0; i<notun; i++)
        {
            cin>>s>>e>>edge_rough.cost;
            edge_rough.notun=1;
            edge_rough.node=s;
            edges[e].pb(edge_rough);
            edge_rough.node=e;
            edges[s].pb(edge_rough);
        }
        ans=dj();
        if(ans==inf)
            printf("Case %lld: Impossible\n",t);
        else
            printf("Case %lld: %lld\n",t,ans);
    }
    return 0;
}
