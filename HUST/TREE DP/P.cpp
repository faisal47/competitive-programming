//#include <bits/stdc++.h>

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <math.h>
#include <limits.h>
#include <limits>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
#include <ctime>
#include <queue>
#include <vector>
#include <map>
#include <assert.h>
#include <utility>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define mp make_pair
#define pi acos(-1)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define fs first
#define sc second
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define sf scanf
#define pf printf
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define scch(a) scanf(" %c",&a)
#define scll1(a) scanf(" %I64d",&a)
#define scll2(a,b) scanf(" %I64d %I64d",&a,&b)
#define scll3(a,b,c) scanf(" %I64d %I64d %I64d",&a,&b,&c)
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sci3(a,b,c) scanf(" %d %d %d",&a,&b,&c)
#define scd1(a) scanf(" %lf",&a)
#define scd2(a,b) scanf(" %lf %lf",&a,&b)
#define scd3(a,b,c) scanf(" %lf %lf %lf",&a,&b,&c)
#define sz(a) (int)a.size()
#define ll long long
#define LL long long
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

#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define mt 50005
#define mod

vec_<int>adj[mt];
int dp[mt],n,mini,arr[mt];

void dfs1(int node,int par)
{
    dp[node]++;
    int i,b;
    rep(i,sz(adj[node]))
    {
        b=adj[node][i];
        if(b == par)
            continue;
        dfs1(b,node);
        dp[node]+=dp[b];
    }
}

void dfs2(int node,int par)
{
    int ret=0;
    int i,b;

    if(par != -1)
        ret=n-dp[node];

    rep(i,sz(adj[node]))
    {
        b=adj[node][i];
        if(b == par)
            continue;
        dfs2(b,node);
        ret=max(ret,dp[b]);
    }
    arr[node]=ret;
    mini=min(mini,ret);
}

vec_<int>ans;

int main ()
{
    int i,j,a,b;
    while(sci1(n) == 1)
    {
        mini=inf;
        rep1(i,n)
        {
            clr(adj[i]);
            dp[i]=0;
        }
        rep(i,n-1)
        {
            sci2(a,b);
            adj[a].pb(b);
            adj[b].pb(a);
        }
        clr(ans);
        dfs1(1,-1);
        dfs2(1,-1);
        rep1(i,n)
        if(mini == arr[i])
            ans.pb(i);

        rep(i,sz(ans))
        {
            if(i)
                printf(" ");
            printf("%d",ans[i]);
        }
        puts("");

    }
    return 0;
}

