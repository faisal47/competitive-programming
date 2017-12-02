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

#define mt 510

map<int,pii>ma1;
map<pii,int>ma2;
char arr[mt][mt];
int n,m,c1,c2,par[mt*mt];
vec_<int>adj[mt*mt];
bool col[mt*mt];

bool check(int i,int j)
{
    return i>=1 && i<=n && j>=1 && j<=m && arr[i][j]=='W';
}

void make_bamdan(int node)
{
    int i=ma1[node].fs;
    int j=ma1[node].sc;

    if(check(i,j-1))
        adj[node].pb(ma2[mp(i,j-1)]);

    if(check(i,j+1))
        adj[node].pb(ma2[mp(i,j+1)]);
}

void make_upornich(int node)
{
    int i=ma1[node].fs;
    int j=ma1[node].sc;

    if(check(i-1,j))
        adj[node+c1].pb(ma2[mp(i-1,j)]);

    if(check(i+1,j))
        adj[node+c1].pb(ma2[mp(i+1,j)]);
}

void make_graph(int node)
{
    make_bamdan(node);
    make_upornich(node);
}

bool dfs(int node)
{
    int asi;
    for(int i=0; i<sz(adj[node]); i++)
    {
        asi=adj[node][i];
        if(!col[asi])
        {
            col[asi]=true;
            if(par[asi]==-1 || dfs(par[asi]))
            {
                par[asi]=node;
                return true;
            }
        }
    }
    return false;
}

int bpm()
{
    int ans=0;
    int i,j;
    for(i=1; i<=c1; i++)
        {
            for(j=1; j<=c2; j++)
            col[j]=false;

            if(dfs(i))
                ans++;
        }
    return ans;
}

int main ()
{
    char z;
    int test,i,j;
    sci1(test);
    while(test--)
    {
        clr(ma1);
        clr(ma2);
        c1=c2=0;
        sci2(n,m);
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                scch(arr[i][j]);
                if(arr[i][j] == 'B')
                {
                    c1++;
                    ma1[c1]=mp(i,j);
                }
                else if(arr[i][j] == 'W')
                {
                    c2++;
                    ma2[mp(i,j)]=c2;
                }
            }
        }

        c1<<=1;

        if(c1 != c2)
        {
            puts("NO");
            continue;
        }

        for(i=1; i<=c1; i++)
        {
            clr(adj[i]);
            par[i]=-1;
        }

        c1>>=1;
        for(i=1; i<=c1; i++)
        {
            make_graph(i);
        }

        c1<<=1;

        if(bpm() == c1)
            puts("YES");
        else
            puts("NO");


    }
    return 0;
}

