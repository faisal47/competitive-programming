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
#define sz 100010
using namespace std;
ll val[sz],par[sz][20];
bool col[sz];
vec_<ll>v[sz];
ll lev,i,j,test,t,m,n,k,h;
void dfs(int a)
{
    int b,i1;
    for(i1=0;i1<v[a].size();i1++)
    {
        b=v[a][i1];
        if(!col[b])
        {
            par[b][0]=a;
            col[b]=1;
            dfs(b);
        }
    }
}
void pp()
{
    for(h=1;(1<<h)<m;h++);
    h--;
    for(lev=1;lev<=h;lev++)
    {
        for(i=0;i<m;i++)
        {
            if(par[i][lev-1]!=-1)
            {
                par[i][lev]=par[par[i][lev-1]][lev-1];
            }
        }
    }
}
ll query()
{
    for(lev=h;lev>=0;lev--)
    {
        if(par[i][lev]!=-1 && val[par[i][lev]]>=j)
        i=par[i][lev];
    }
    return i;
}
int main ()
{
    scanf("%lld",&test);
    for(t=1;t<=test;t++)
    {
        scanf("%lld %lld",&m,&n);
        val[0]=1;
        for(i=0;i<m;i++)
        {
            clr(v[i]),col[i]=0;
            for(j=0;j<20;j++)
            par[i][j]=-1;
        }
        for(i=1;i<m;i++)
        {
            scanf("%lld %lld",&j,&k);
            val[i]=k;
            v[j].pb(i);
        }
        val[0]=1;
        col[0]=1;
        dfs(0);
        pp();
        printf("Case %lld:\n",t);
        while(n--)
        {
            scanf("%lld %lld",&i,&j);
            printf("%lld\n",query());
       }
    }
    return 0;
}
