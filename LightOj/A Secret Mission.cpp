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
#define FOR_0(i,n) for(i=0;i<n;i++)
#define FOR_1(i,n) for(i=1;i<=n;i++)
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define eps 1E-7
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define sc1(a) scanf("%lld",&a)
#define sc2(a,b) scanf("%lld %lld",&a,&b)
#define sc3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define sz 100010
using namespace std;
typedef long long ll;
struct d2
{
    ll a,b,c;
};
struct nwd1
{
    ll a,d;
};
vec_<nwd1>nwd[sz];
vec_<d2>d1;
vec_<ll>nodes[sz];
ll n,m,par[sz],pare[sz][20],dist[sz][20],L[sz];
bool col[sz];
bool sign(d2 a,d2 b)
{
    return a.c<b.c;
}
ll find_parent(ll a)
{
    if(par[a]==a)
    return a;
    else
    return par[a]=find_parent(par[a]);
}
void make_parent(ll i)
{
    ll u=find_parent(d1[i].a);
    ll v=find_parent(d1[i].b);
    if(u==v)
    return;
    else
    par[u]=v;
    nwd[d1[i].a].pb({d1[i].b,d1[i].c});
    nwd[d1[i].b].pb({d1[i].a,d1[i].c});
}
void mst()
{
    ll i;
    for(i=0;i<d1.size();i++)
    make_parent(i);
}
void dfs(ll a)
{
    ll i,b;
    for(i=0;i<nwd[a].size();i++)
    {
        b=nwd[a][i].a;
        if(!col[b])
        {
            L[b]=L[a]+1;
            col[b]=1;
            pare[b][0]=a;
            dist[b][0]=nwd[a][i].d;
            dfs(b);
        }
    }
}
void pp()
{
    L[1]=0;
    col[1]=1;
    pare[1][0]=-1;
    dfs(1);
    ll h,level,i;
    for(h=1;(1<<h)<n;h++);h--;
    for(level=1;level<=h;level++)
    {
        for(i=1;i<=n;i++)
        if(pare[i][level-1]!=-1)
        {
            pare[i][level]=pare[pare[i][level-1]][level-1];
            dist[i][level]=max(dist[i][level-1],dist[pare[i][level-1]][level-1]);
        }
    }
}
ll query(ll a,ll b)
{
    if(L[a]<L[b])
    swap(a,b);
    ll h,maxi=-1,i;
    for(h=1;(1<<h)<=L[a];h++);
    h--;
    for(i=h;i>=0;i--)
    if((L[a]-(1<<i))>=L[b])
    {
        maxi=max(dist[a][i],maxi);
        a=pare[a][i];
    }
    if(a==b)
    return maxi;
    for(i=h;i>=0;i--)
    if(pare[a][i]!=-1 && pare[b][i]!=-1 && pare[a][i]!=pare[b][i])
    {
        maxi=max(maxi,max(dist[a][i],dist[b][i]));
        a=pare[a][i];
        b=pare[b][i];
    }
    maxi=max(maxi,max(dist[a][0],dist[b][0]));
    return maxi;
}
int main ()
{
    ll i,j,test,t=1,a,b,c;
    sc1(test);
    while(test--)
    {
        clr(d1);
        sc2(n,m);
        for(i=1;i<=n;i++)
        {
            col[i]=0;
            clr(nwd[i]);
            clr(nodes[i]);
            par[i]=i;
            for(j=0;j<20;j++)
            {
                pare[i][j]=-1;
            }
        }
        while(m--)
        {
            sc3(a,b,c);
            d1.pb({a,b,c});
        }
        sort(d1.begin(),d1.end(),sign);
        mst();
        pp();
        sc1(i);
        printf("Case %lld:\n",t++);
        while(i--)
        {
            sc2(a,b);
            printf("%lld\n",query(a,b));
        }
    }
    return 0;
}
