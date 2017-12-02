#include <bits/stdc++.h>

#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<30
#define mp make_pair
#define pi acos(-1)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define fs first
#define sc second
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()
#define ll long long
#define ull unsigned long long
#define dd double
#define rep(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
using namespace std;

template<class T1> void deb(T1 e)
{
    cout<<e<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
}



#define mt 10010
#define mod

#define fop freopen("bridges.in","r",stdin);freopen("bridges.out","w",stdout);

map<pii,int>cn,ma;
vec_<int>adj[mt];
int low[mt],pre[mt],ti;
vec_<pii>ans,ans2;
pii temp2;
void dfs(int u,int p)
{
    int v,i;
    pre[u]=low[u]=ti;
    ti++;
    for(i=0; i<adj[u].size(); i++)
    {
        v=adj[u][i];
        if(pre[v]==-1)
        {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(pre[v]==low[v])
            {
                temp2= {u,v};
                if(temp2.fs > temp2.sc)
                    swap(temp2.fs,temp2.sc);
                ans.pb(temp2);
            }
        }
        else if(v!=p)
            low[u]=min(low[u],pre[v]);
    }
}

int main ()
{
    cffi;
    fop;
    ti=1;
    ms(pre,-1);
    ms(low,-1);
    int i,j,test,n,t=1,m,a,b;
    pii temp;
    cin>>n>>m;

    rep1(i,m)
    {
        cin>>a>>b;
        if(a > b)
            swap(a,b);
        temp= {a,b};
        cn[temp]++;
        ma[temp]=i;
    }
    for(auto ind:ma)
    {
        adj[ind.fs.fs].pb(ind.fs.sc);
        adj[ind.fs.sc].pb(ind.fs.fs);
    }
    dfs(1,-1);
    for(auto ind:ans)
        if(cn[ind] == 1)
            ans2.pb(ind);
    deb(sz(ans2));
    bool f=0;
    for(auto ind: ans2)
    {
        if(f)
            cout<<" ";
        f=1;
        cout<<ma[ind];
    }
    return 0;
}








