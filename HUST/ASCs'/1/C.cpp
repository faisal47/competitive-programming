
#include <bits/stdc++.h>

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

#define fop freopen("grant.in","r",stdin);freopen("grant.out","w",stdout);

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


#define mt 500010
#define mod

int dp[mt][2];
vec_<int>adj[mt];

int solve(int node,int col,int par)
{
    int &ret=dp[node][col];
    if(ret != -1)
        return ret;
    ret=0;
    if(col)
        ret=1000;
    int i,b,mot=0,temp;
    rep(i,sz(adj[node]))
    {
        b=adj[node][i];
        if(b == par)
            continue;
        mot+=solve(b,0,node);
    }
    ret+=mot;
    if(!col)
    {
        rep(i,sz(adj[node]))
        {
            b=adj[node][i];
            if(b == par)
                continue;
            ret=max(ret,mot-solve(b,0,node)+solve(b,1,node));
        }
    }

    return ret;
}
vec_<int>ans;
void solve2(int node,int col,int par)
{
    int ret=dp[node][col],ret2;
    ret2=0;
    if(col)
    {
        ret2=1000;
        ans.pb(node);
    }
    int i,b,mot=0,j;
    rep(i,sz(adj[node]))
    {
        b=adj[node][i];
        if(b == par)
            continue;
        mot+=solve(b,0,node);
    }
    ret2+=mot;
    if(ret == ret2)
    {
        rep(i,sz(adj[node]))
        {
            b=adj[node][i];
            if(b == par)
                continue;
            solve2(b,0,node);
        }
        return;
    }
    if(!col)
    {
        rep(i,sz(adj[node]))
        {
            b=adj[node][i];
            if(b == par)
                continue;
            ret2=max(ret2,mot-solve(b,0,node)+solve(b,1,node));
            if(ret2 == ret)
            {
                rep(j,sz(adj[node]))
                {
                    b=adj[node][j];
                    if(b == par)
                        continue;
                    if(j == i)
                        solve2(b,1,node);
                    else
                        solve2(b,0,node);
                }
                return;
            }
        }
    }

    return;
}

int main ()
{
//    cffi;
    fop;
    int i,j,test,t=1,n;
    ms(dp,-1);
    sci1(n);
    rep1(i,n-1)
    {
        sci1(j);
        adj[j].pb(i+1);
    }
    deb(solve(1,0,-1));
    solve2(1,0,-1);
    sort(all(ans));
    rep(i,sz(ans))
    cout<<ans[i]<<" ";
    return 0;
}









