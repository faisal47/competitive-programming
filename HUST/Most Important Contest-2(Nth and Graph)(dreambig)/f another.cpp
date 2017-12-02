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

#define mt 210
int n;
vec_<int>adj[mt];
int dp[2][mt];
bool flag;

int solve(int parmu,int node)
{
    int &ret=dp[parmu][node];

    if(ret!=-1)
        return ret;

    ret=parmu;

    int i,v;
    for(i=0;i<sz(adj[node]);i++)
    {
        v=adj[node][i];
        if(parmu)
            ret+=solve(0,v);
        else
            ret+=max(solve(1,v),solve(0,v));
    }

    return ret;
}

void visit_path(int parmu,int node)
{
    if(flag)
        return;
    int i,v;
    for(i=0;i<sz(adj[node]);i++)
    {
        v=adj[node][i];
        if(!parmu)
        {
            if(dp[1][v]==dp[0][v])
            {
                flag=1;
            return;
            }
            else if(dp[1][v]>dp[0][v])
                visit_path(1,v);
            else
                visit_path(0,v);
        }
        else
            visit_path(0,v);
    }
}

int main ()
{
    int n1,i,j;
    string a,b;
    map<string,int>ma;

    while(cin>>n && n)
    {
        flag=0;
        n1=1;
        clr(ma);
        n+=1;
        for(i=1; i<=n; i++)
        {
            dp[0][i]=dp[1][i]=-1;
            clr(adj[i]);
        }
        cin>>a;
        if(ma.find(a)==ma.end())
            ma[a]=n1++;

        n-=2;

        for(i=1; i<=n; i++)
        {
            cin>>a>>b;
            if(ma.find(a)==ma.end())
                ma[a]=n1++;
            if(ma.find(b)==ma.end())
                ma[b]=n1++;

            adj[ma[b]].pb(ma[a]);
        }

        solve(0,1);
        solve(1,1);

        if(dp[0][1]==dp[1][1])
            flag=1;
        else if(dp[0][1]>dp[1][1])
            visit_path(0,1);
        else
            visit_path(1,1);

        pf("%d ",max(dp[0][1],dp[1][1]));
        if(flag)
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }

    return 0;
}


