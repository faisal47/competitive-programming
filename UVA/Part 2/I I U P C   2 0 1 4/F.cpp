#include <bits/stdc++.h>

#define ms(a,b) memset(a,b,sizeof(a))
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;


#define mt 10010

vector<int>adj[mt];
bool col[mt];
int par[mt],ans[mt];

int dfs(int node)
{
    int v,i,baccha,nb;
    baccha=0;

    for(i=0;i<adj[node].size();i++)
    {
        v=adj[node][i];
        if(!col[v])
        {
            col[v]=1;
            nb=dfs(v);
            ans[node]+=(baccha*nb);
            baccha+=nb;
        }
    }
    ans[node]+=baccha;
    return baccha+1;
}

int main ()
{
    cffi;
    int i,j,test,n,t=1;
    cin>>test;
    while(test--)
    {
        cin>>n;
        for(i=1; i<=n; i++)
        {
           adj[i].clear();
            col[i]=0;
            ans[i]=0;
        }
        for(i=1; i<=n; i++)
        {
            cin>>par[i];
            adj[par[i]].push_back(i);
        }
        for(i=1;i<=n;i++)
        {
            if(!par[i] && !col[i])
            {
                col[i]=1;
                dfs(i);
            }
        }

        cout<<"Forest#"<<t++<<":";

        for(i=1;i<=n;i++)
            cout<<" "<<ans[i];

        cout<<endl;

    }
    return 0;
}


