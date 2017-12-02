#include <bits/stdc++.h>
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define sci1(a) scanf("%d",&a)
#define sz(a) a.size()
#define mt 110
using namespace std;
int par[mt];
bool col[mt];
vec_<int>v[mt];
int m,n,test,t,a[mt],b[mt];
bool dfs(int node)
{
    int v1;
    for(int i=0; i<sz(v[node]); i++)
    {
        v1=v[node][i];
        if(!col[v1])
        {
            col[v1]=1;
            if(par[v1]==-1||dfs(par[v1]))
            {
                par[v1]=node;
                return true;
            }
        }
    }
    return false;
}
int bpm()
{
    int i,j;
    int ans=0;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
            col[j]=0;
        if(dfs(i))
            ans++;
    }
    return ans;
}
int main ()
{
    int i,j;
    sci1(test);
    for(t=1; t<=test; t++)
    {
        sci1(n);
        for(i=1; i<=n; i++)
        {
            clr(v[i]);
            sci1(a[i]);
        }
        cin>>m;
        for(j=1; j<=m; j++)
        {
            par[j]=-1;
            sci1(b[j]);
            for(i=1; i<=n; i++)
                if(b[j]%a[i]==0)
                    v[i].pb(j);
        }
        printf("Case %d: %d\n",t,bpm());
    }
    return 0;
}
