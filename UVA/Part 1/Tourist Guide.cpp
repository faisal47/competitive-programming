#include <bits/stdc++.h>
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define sci1(a) scanf("%d",&a)
#define sz(a) a.size()
#define sort_n(a) sort(a.begin(),a.end())
using namespace std;
vec_<int>v1[110];
vec_<string>ans;
map<string,int>m1;
map<int,string>m2;
int low[110],pre[110],root,ti;
void dfs(int u,int p)
{
    int v,i,child=0;
    bool flag=0;
    low[u]=pre[u]=ti++;
    //cout<<low[u]<<" "<<pre[u]<<endl;
    for(i=0; i<sz(v1[u]); i++)
    {
        v=v1[u][i];
        if(!pre[v])
        {
            child++;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=pre[u] && u!=root && !flag)
                {
                    ans.pb(m2[u]);
                    flag=1;
                }
        }
        else if(v!=p)
                low[u]=min(low[u],pre[v]);
        if(child>1 && u==root && !flag)
            {
                ans.pb(m2[u]);flag=1;
            }
    }
}
int main ()
{
    int n,t,test=0;
    string a,b;
    while(sci1(n)==1)
    {
        if(!n)break;
        if(test)cout<<endl;
        clr(m1);
        clr(m2);
        clr(ans);
        ti=t=1;
        while(n--)
        {
            cin>>a;
            if(m1.find(a)==m1.end())
            {
                m1[a]=t;
                m2[t++]=a;
            }

        }
        for(n=1; n<t; n++)
        {
            clr(v1[n]);
            pre[n]=low[n]=0;
        }
       // cout<<"t== "<<t<<endl;
        sci1(n);
        while(n--)
        {
            cin>>a>>b;
            v1[m1[a]].pb(m1[b]);
            v1[m1[b]].pb(m1[a]);
        }
        for(n=1; n<t; n++)
        {
            if(!pre[n])
            {
                root=n;
                dfs(n,n);
            }
        }
        sort_n(ans);
        printf("City map #%d: %d camera(s) found\n",++test,sz(ans));
        for(n=0;n<sz(ans);n++)
        cout<<ans[n]<<endl;
    }
    return 0;
}

