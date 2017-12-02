#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
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
#define deb1(a) cout<<a<<endl;
#define deb2(a,b) cout<<a<<" "<<b<<endl
#define deb3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
using namespace std;
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};

///***************************************************** ekhon kamer kam ********************************************************************///

#define mt 1010

struct data
{
    int b,c;
};

vec_<data>adj[mt];
vec_<int>adjulta[mt];

bool col[mt];
vec_<int>ans;
int dist[mt];

void dfs(int u)
{
    int i,v;
    col[u]=1;
    ans.pb(u);

    for(i=0; i<sz(adjulta[u]); i++)
    {
        v=adjulta[u][i];
        if(!col[v])
        {
//            ans.pb(v);
//            col[v]=1;
            dfs(v);
        }
    }

}

void bf(int n)
{
    int i,k,j;

    k=n-1;
    data v;
    while(k--)
    {
        for(i=0; i<n; i++)
            for(j=0; j<sz(adj[i]); j++)
            {
                v=adj[i][j];
                if(dist[i] + v.c < dist[v.b])
                    dist[v.b] = dist[i] + v.c;
            }
    }

    //while(k--)
    {
        for(i=0; i<n; i++)
            for(j=0; j<sz(adj[i]); j++)
            {
                v=adj[i][j];
                if(dist[i] + v.c < dist[v.b] && !col[i])
                {
//                    ans.pb(i);
//                    col[i]=1;
                    dfs(i);
                }
            }
    }
}

int main ()
{

    int test,t=1,n,m,a,b,c,i;

    cin>>test;
    while(test--)
    {
        cin>>n>>m;

        for(i=0; i<n; i++)
        {
            clr(adjulta[mt]);
            clr(adj[i]);
            col[i]=0;
            dist[i]=inf;
        }

        clr(ans);

        while(m--)
        {
            cin>>a>>b>>c;
            adj[a].pb({b,c});
            adjulta[b].pb(a);
        }

        bf(n);

        sort(all(ans));

        pf("Case %d:",t++);
        bool flag=0;
//        if(sz(ans))
//        {
//            for(i=0;i<sz(ans);i++)
//                cout<<" "<<ans[i];
//        }
        for(i=0; i<n; i++)
        {
            if(col[i])
            {
                flag=1;
                cout<<" "<<i;
            }

        }

        if(!flag)
            pf(" impossible");
        puts("");
    }
    return 0;
}
