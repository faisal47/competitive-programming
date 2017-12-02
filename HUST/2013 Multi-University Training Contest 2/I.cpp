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
#define inf 1<<30
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
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()
#define ll long long
#define ull unsigned long long
#define dd double
#define rep(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
#define fop freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
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


//double dur(int x1,int y1,int x2,int y2)
//{
//    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//}
//template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll B,ll P,ll M){ll R=1;while(P>0){if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}return R;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};


#define mt 2010
#define MAX 2010
#define mod

int par[MAX];
bool col[MAX];
vec_<int>adj[mt];

int dfs(int u)
{
    if(col[u])
        return false;
    col[u] = true;
    for(int i = 0; i < sz(adj[u]); i++)
    {
        int v = adj[u][i];
        if(par[v] == -1 || dfs(par[v]))
        {
            par[v] = u;
            return true;
        }
    }
    return false;
}
int MAX_BMP(int n) // finds maximum possible bipartite matching
{
    int ret = 0, i;
    ms(par, -1);
    for(i = 0; i < n; i++)
    {
        ms(col, 0);
        if(dfs(i)) ret++;
    }
    return ret;
}

int arr1[mt][2];
int arr2[mt][2];

bool check(int i,int j)
{
    int x1=arr1[i][0];
    int y1=arr1[i][1];
    int x2=arr2[j][0];
    int y2=arr2[j][1];
    return (x2==x1 || x1+1==x2) && (y1==y2 || y1==y2+1);
}

int main ()
{
    cffi;
    int i,j,test,n,m,a,b;
    while(cin>>n>>m)
    {
        if(n ==0 && m==0)
            break;
        rep(i,n)
        clr(adj[i]);
        rep(i,n)
        cin>>arr1[i][0]>>arr1[i][1];
        rep(i,m)
        cin>>arr2[i][0]>>arr2[i][1];
        rep(i,n)
        rep(j,m)
        if(check(i,j))
            adj[i].pb(j);
        deb(n+m-MAX_BMP(n));
    }
    return 0;
}










