#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
#define fs first
#define sc second
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define sort_m(a) sort(a.begin(),a.end(),comp)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sz(a) a.size()
#define mt 11010
using namespace std;
vec_<pii>ans;
int pre[mt],low[mt],ti,cou[mt];
vec_<int>v1[mt];
void dfs(int u,int p)
{
    int v,i;
    pre[u]=low[u]=ti++;
    for(i=0; i<sz(v1[u]); i++)
    {
        v=v1[u][i];
        if(!pre[v])
        {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(pre[v]==low[v])
            {
                cou[u]++;
                cou[v]++;
            }
        }
        else if(v!=p)
            low[u]=min(low[u],pre[v]);
    }
}
bool comp(pii a,pii b)
{
    if(a.sc>b.sc)
    return a.sc>b.sc;
    return a.fs<b.fs;
}
int main ()
{
    int i,j,n,m;
    while(sci2(n,m)==2)
    {
        if(!n && !m)break;
        ti=1;
        clr(ans);
        for(i=0; i<=n; i++)
        {
            cou[i]=pre[i]=low[i]=0;
            clr(v1[i]);
        }
        while(sci2(i,j)==2)
        {
            if(i==-1 && j==-1)break;
            v1[i].pb(j);
            v1[j].pb(i);
        }
        for(i=0; i<n; i++)
            if(!pre[i])
                dfs(i,i);
        for(i=0;i<n;i++)
        {
            if(cou[i]<sz(v1[i]))cou[i]++;
            ans.pb(mp(i,cou[i]));
        }
        sort_m(ans);
        i=0;
        while(m--)
        {
            cout<<ans[i].fs<<" "<<ans[i].sc<<endl;i++;
        }
        cout<<endl;
    }
    return 0;
}

