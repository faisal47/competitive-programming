/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

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
#define pii pair<int,int>
#define fs first
#define sc second
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define sf scanf
#define pf printf
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
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
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
using namespace std;

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};
//int X[]={1,1,2,2,-1,-1,-2,-2};//knight move//
//int Y[]={2,-2,1,-1,2,-2,1,-1};//knight move//
/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#define mt 1010
#define mod

struct dat
{
    int u,v,c;
};

string arr[mt];

vec_<dat>data;

bool comp(dat a,dat b)
{
    return a.c<b.c;
}

int n,m,k,w,par[mt];
vec_<int>ans_edge[mt];

int get_dist(int a,int b)
{
    int c=0,i;
    for(i=0;i<n;i++)
        if(arr[a][i] != arr[b][i])
        c++;

    return c*w;
}

int find_parent(int u)
{
    if(par[u] == u)
        return u;
    return par[u]=find_parent(par[u]);
}

int mst()
{
    int u,v,i,maan=0;
    for(i=0;i<sz(data);i++)
    {
        u=find_parent(data[i].u);
        v=find_parent(data[i].v);
        if(u == v)
            continue;

        par[u]=v;
        maan+=data[i].c;
        ans_edge[data[i].u].pb(data[i].v);
        ans_edge[data[i].v].pb(data[i].u);
    }
    return maan;
}

bool col[mt];

void visit_path(int u,int parent)
{
    if(parent != -1)
        cout<<u<<" "<<parent<<endl;
    col[u]=1;
    int i;
    for(i=0;i<sz(ans_edge[u]);i++)
    if(!col[ans_edge[u][i]])
        visit_path(ans_edge[u][i],u);
}

int main ()
{
    int i,j,k;
    string temps;

    cin>>n>>m>>k>>w;

    for(i=0;i<=k;i++)
        par[i]=i;

    for(i=1;i<=k;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>temps;
            arr[i]+=temps;
        }
    }

    n*=m;

    int dist;

    for(i=1;i<=k;i++)
    {
        for(j=i+1;j<=k;j++)
        {
            dist=get_dist(i,j);
            data.pb({i,j,dist});
        }
        data.pb({0,i,n});
    }

    sort(all(data),comp);

    cout<<mst()<<endl;

    visit_path(0,-1);

    return 0;
}