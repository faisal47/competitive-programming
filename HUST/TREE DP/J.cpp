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

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}


//double dur(int x1,int y1,int x2,int y2)
//{
//    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//}
//template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll B,ll P,ll M){ll R=1;while(P>0){if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}return R;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};
//int X[]={1,1,2,2,-1,-1,-2,-2};//knight move//
//int Y[]={2,-2,1,-1,2,-2,1,-1};//knight move//

#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define mt 10010
#define mod

vec_<pii>adj[mt];
struct maan
{
    int maxi1,maxi1b;
    int maxi2,maxi2b;
};

maan dp[mt];
int ans[mt],n,upor[mt];

void dfs1(int node,int par)
{
    int b,i,d,tempd,tempp;
    dp[node].maxi1=0;
    dp[node].maxi2=0;
    dp[node].maxi1b=0;
    dp[node].maxi2b=0;
    rep(i,sz(adj[node]))
    {
        b=adj[node][i].fs;
        d=adj[node][i].sc;
        if(b == par)
            continue;
        dfs1(b,node);
        tempd=dp[b].maxi1+d;
        tempp=b;
        if(dp[node].maxi1 < tempd)
        {
            dp[node].maxi2=dp[node].maxi1;
            dp[node].maxi2b=dp[node].maxi1b;
            dp[node].maxi1=tempd;
            dp[node].maxi1b=tempp;
        }
        else if(dp[node].maxi2 < tempd)
        {
            dp[node].maxi2=tempd;
            dp[node].maxi2b=tempp;
        }
    }
//    deb(node,dp[node].maxi1,dp[node].maxi1b);
//    deb(node,dp[node].maxi2,dp[node].maxi2b);
}

void dfs3(int node,int par,int disti)
{
    upor[node]=disti;
    int i,b,temp,d;
    rep(i,sz(adj[node]))
    {
        b=adj[node][i].fs;
        d=adj[node][i].sc;
        if(b == par)
            continue;
        if(b == dp[node].maxi1b)
            temp=dp[node].maxi2;
        else
            temp=dp[node].maxi1;
        dfs3(b,node,max(temp,upor[node])+d);
    }
}

void dfs2(int node,int par)
{
    int ret1=upor[node];
    int ret2=dp[node].maxi1;
    ans[node]=max(ret1,ret2);
    int i,b;
    rep(i,sz(adj[node]))
    {
        b=adj[node][i].fs;
        if(b == par)
            continue;
        dfs2(b,node);
    }
}

int main ()
{
    cffi;
    int i,j,a,b;

    while(sci1(n) == 1)
    {
        rep1(i,n)
        {
            dp[i].maxi1=0;
            dp[i].maxi2=0;
            dp[i].maxi1b=0;
            dp[i].maxi2b=0;
            clr(adj[i]);
        }

        rep1(i,n-1)
        {
            sci2(a,b);
            adj[a].pb({i+1,b});
            adj[i+1].pb({a,b});
        }
        dfs1(1,-1);
        dfs3(1,-1,0);
        dfs2(1,-1);
        rep1(i,n)
        printf("%d\n",ans[i]);
    }

    return 0;
}

