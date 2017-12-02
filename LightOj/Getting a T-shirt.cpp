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
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sz(a) a.size()
#define mt 310
using namespace std;
map<string,int>ma;
int par[mt],n,m,res,i,j;
bool col[mt];
vec_<int>adj[55];
bool dfs(int node)
{
    int asi;
    for(int i=0;i<sz(adj[node]);i++)
    {
        asi=adj[node][i];
        if(!col[asi])
        {
            col[asi]=1;
            if(par[asi]==-1 || dfs(par[asi]))
            {
                par[asi]=node;
                return true;
            }
        }
    }
    return false;

}
int bpm()
{
    res=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        col[j]=0;
        if(dfs(i))res++;
    }
    return res;
}
int main ()
{
    int test,t=1,k;
    ma["XXL"]=1;
    ma["XL"]=2;
    ma["L"]=3;
    ma["M"]=4;
    ma["S"]=5;
    ma["XS"]=6;
    string a,b;
    sci1(test);
    while(test--)
    {
        sci2(m,n);
        m*=6;
        for(i=1; i<=m; i++)par[i]=-1;
        for(i=1; i<=n; i++)
        {
            cin>>a>>b;
            clr(adj[i]);
            for(j=ma[a],k=ma[b]; j<=m,k<=m; j+=6,k+=6)
                adj[i].pb(j),adj[i].pb(k);
        }
        if(bpm()==n)
            printf("Case %d: YES\n",t++);
        else
            printf("Case %d: NO\n",t++);
    }
    return 0;
}

