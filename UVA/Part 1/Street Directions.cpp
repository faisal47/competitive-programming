#include <bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sz(a) a.size()
#define mt 1010
using namespace std;
vec_<int>v1[mt];
bool flag[mt][mt];
int pre[mt],low[mt],ti;
void dfs(int u,int p)
{
    pre[u]=low[u]=ti++;
    int v,i;
    for(i=0;i<sz(v1[u]);i++)
    {
        v=v1[u][i];
        if(!pre[v])
        {
            cout<<u<<" "<<v<<endl;
            flag[u][v]=flag[v][u]=1;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(pre[v]==low[v])
                cout<<v<<" "<<u<<endl;
        }
        else if(pre[v] && v!=p)
        {
            if(!flag[u][v])
            {
                cout<<u<<" "<<v<<endl;
                flag[u][v]=flag[v][u]=1;
            }
            low[u]=min(low[u],pre[v]);
        }
    }
}
int main ()
{
    int n,m,i,j,t=1;
    while(sci2(n,m)==2)
    {
        if(!n && !m)break;
        ti=1;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            flag[i][j]=0;
            pre[i]=low[i]=0;
            clr(v1[i]);
        }
        while(m--)
        {
            sci2(i,j);
            v1[i].pb(j);
            v1[j].pb(i);
        }
        printf("%d\n\n",t++);
        for(i=1;i<=n;i++)
        if(!pre[i])
        dfs(i,i);
        cout<<"#\n";
    }
    return 0;
}
