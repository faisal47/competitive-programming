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
#define inf 1<<28
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sz(a) a.size()
#define mt 15
using namespace std;
vec_<int>v1[mt+1];
int dp[1<<mt],col[17][1<<mt],visit[1<<mt];

int dfs(int u,int mask)
{
    int i,v;
    visit[mask]=col[u][mask]=1;
    int new_mask;
    for(i=0; i<sz(v1[u]); i++)
    {
        v=v1[u][i];
        new_mask=mask|(1<<v);
        if(!col[v][new_mask])
        {
            col[v][new_mask]=1;
            dfs(v,new_mask);
        }
    }
}

int maan_de(int mask)
{
    if(!mask)return 0;
    int &ret=dp[mask];
    if(ret!=-1)return ret;
    int var=mask;
    ret=inf;
    while(var>0)
    {
        if(visit[var]==1)
            ret=min(ret,1+maan_de(mask^var));
        var--;
        if(var>0)var&=mask;
    }
    return ret;
}

int main ()
{
    int test,t=1,n,m,i,mask,j;
    sci1(test);
    while(test--)
    {
        sci2(n,m);
        mask=(1<<n)-1;
        for(i=0; i<=mask; i++)
            dp[i]=visit[i]=-1;
        for(i=0; i<n; i++)
            clr(v1[i]);

        while(m--)
        {
            sci2(i,j);
            v1[i-1].pb(j-1);
        }

        ms(col,0);

        for(i=0; i<n; i++)
        {
            col[i][1<<i]=1;
            dfs(i,1<<i);
        }

        printf("Case %d: %d\n",t++,maan_de(mask));
    }
    return 0;
}

