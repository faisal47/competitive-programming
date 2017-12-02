
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
#define inf 1000001
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

#define mt 1010
#define mod

vec_<pii>adj[mt];
int m,mid;

int dfs(int node,int par)
{
    int i,ret=0,tr;
    pii b;
    rep(i,sz(adj[node]))
    {
        b=adj[node][i];
        if(b.fs == par)
            continue;

        tr=dfs(b.fs,node); /// ei dfs gie ei node er nicher optimal result ene tr e save korbe

        /// ekhon check kortechi tr theke valo result amar ei b.sc edge e ache kina
        if(b.sc < tr && b.sc<=mid)
            tr=b.sc;

        ret+=tr;
    }

    if(ret <= 0)
        ret=inf;

    return ret;
}

int bs()
{
    int ret=inf;
    int l=1,h=1000;
    while(l <= h)
    {
        mid=(l+h)>>1;
        if(dfs(1,-1) <= m)
        {
            ret=min(ret,mid);
            h=mid-1;
        }
        else
            l=mid+1;
    }
    return ret;
}

int main ()
{
    cffi;
    int n,ans,i,j,a,b,c;

    while(cin>>n>>m)
    {
        if(n==0 && m==0)
            break;
        rep1(i,n)
        clr(adj[i]);
        rep(i,n-1)
        {/// https://lh4.googleusercontent.com/-WzAOpgqE6_M/AAAAAAAAAAI/AAAAAAAAAU4/jdRt_2iUu2s/s46-c-k-no/photo.jpg
            cin>>a>>b>>c;
            adj[a].pb({b,c});
            adj[b].pb({a,c});
        }
        ans=bs();
        if(ans >= inf)
            ans=-1;
        deb(ans);
    }
    return 0;
}

