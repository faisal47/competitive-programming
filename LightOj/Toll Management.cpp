#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include <math.h>
#include <queue>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 123456789123456789
#define ll long long
#define FOR_0(i,n) for(i=0;i<n;i++)
#define FOR_1(i,n) for(i=1;i<=n;i++)
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
//ll bigmod(ll a,ll b,ll m)
//{
//    if(b == 0) return 1%m;
//    ll x = bigmod(a,b/2,m);
//    x = (x * x) % m;
//    if(b % 2 == 1) x = (x * a) % m;
//    return x;
//}
#define sz 10005
using namespace std;
struct node_and_cost
{
    ll node,cost;
};
struct edge
{
    ll s,e,cost;
};
vec_ <edge>edges;
edge edge_rough;
node_and_cost node_and_cost_rough;
ll n,m,s,e;
vec_ <node_and_cost>v1[sz],v2[sz];
struct data
{
   int node,cost;
   bool operator < (const data& p) const
   {
       return cost > p.cost;
   }
};
ll dist1[sz],dist2[sz];
void dj1()
{
    ll i,d;
    priority_queue<data>q;
    data u,v;
    v.node=s;
    v.cost=0;
    q.push(v);
    dist1[s]=0;
    while(!q.empty())
    {
//        cout<<"jd";
        u=q.top();
        q.pop();
        for(i=0;i<v1[u.node].size();i++)
        {
            v.node=v1[u.node][i].node;
            v.cost=v1[u.node][i].cost+u.cost;
            if(dist1[v.node]>v.cost)
            {
                dist1[v.node]=v.cost;
                q.push(v);
            }
        }
    }
}
void dj2()
{
//    cout<<endl;
    ll i,d;
    priority_queue<data>q;
    data u,v;
    v.node=e;
    v.cost=0;
    q.push(v);
    dist2[e]=0;
    while(!q.empty())
    {
         //cout<<"jd";
        u=q.top();
        q.pop();
        for(i=0;i<v2[u.node].size();i++)
        {
            //cout<<"jhd";
            v.node=v2[u.node][i].node;
            v.cost=v2[u.node][i].cost+u.cost;
            if(dist2[v.node]>v.cost)
            {
                dist2[v.node]=v.cost;
                q.push(v);
            }
        }
    }
//    cout<<"jhd";
}
int main ()
{
    ll i,j,test,t,p,ans;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        ans=-1;
        clr(edges);
        cin>>n>>m>>s>>e>>p;
        for(i=1;i<=n;i++)
        {
            dist1[i]=dist2[i]=inf;
            clr(v1[i]);
            clr(v2[i]);
        }
        for(i=1;i<=m;i++)
        {
            cin>>edge_rough.s>>edge_rough.e>>edge_rough.cost;
            edges.pb(edge_rough);
            node_and_cost_rough.node=edge_rough.e;
            node_and_cost_rough.cost=edge_rough.cost;
            v1[edge_rough.s].pb(node_and_cost_rough);
            node_and_cost_rough.node=edge_rough.s;
            v2[edge_rough.e].pb(node_and_cost_rough);
        }
        dj1();
        dj2();
        //cout<<m<<endl;
        for(i=0;i<m;i++)
        {
            //cout<<"j1111hdf";
            if((dist1[edges[i].s]+dist2[edges[i].e]+edges[i].cost)<=p)
            ans=max(edges[i].cost,ans);
        }
        printf("Case %lld: %lld\n",t,ans);
    }
    return 0;
}
