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

#define mt 110
int arr[mt],c,par[mt],flag[mt];

struct data1
{
    int a,b,c;
};

vec_<int>adj[mt];
vec_<data1>data;
int c1,ans1,ans2,c2;

int find_parent(int s)
{
    if(par[s]==s)
        return s;
    return par[s]=find_parent(par[s]);
}

void make_set(int i)
{
    int u=find_parent(data[i].a);
    int v=find_parent(data[i].b);
    if(u==v)
        return;

    adj[u].pb(v);
    adj[v].pb(u);

    arr[c2++]=i;
    par[u]=v;
    ans1+=data[i].c;
}

bool comp(data1 a,data1 b)
{
    return a.c<b.c;
}

int ans2_t;

void makeset1(int i)
{
    int u=find_parent(data[i].a);
    int v=find_parent(data[i].b);
    if(u==v)
        return;

    adj[u].pb(v);
    adj[v].pb(u);

    par[u]=v;
    ans2_t+=data[i].c;
}

void dfs(int u)
{
    int i,v;
    for(i=0; i<sz(adj[u]); i++)
    {
        v=adj[u][i];
        if(!flag[v])
        {
            c1++;
            flag[v]=1;
            dfs(v);
        }
    }
}

int main ()
{
    int i,test,t=1,n,m,a,b,c,j;
    cin>>test;
    while(test--)
    {
        cin>>n>>m;
        ans1=c2=0;

        for(i=1; i<=n; i++)
        {
            par[i]=i;
            flag[i]=0;
            clr(adj[i]);
        }

        clr(data);

        while(m--)
        {
            cin>>a>>b>>c;
            if(a>b)
                swap(a,b);
            data.pb({a,b,c});
        }

        sort(all(data),comp);

        for(i=0; i<sz(data); i++)
        {
            make_set(i);
        }

        c1=1;
        flag[1]=1;
        dfs(1);

        pf("Case #%d : ",t++);
        if(c1!=n)
        {
            cout<<"No way\n";
        }
        else
        {
            ans2=inf;

            for(j=0; j<c2; j++)
            {
                for(i=1; i<=n; i++)
                {
                    par[i]=i;
                    flag[i]=0;
                    clr(adj[i]);
                }
                ans2_t=0;
                for(i=0; i<sz(data); i++)
                {
                    if(i!=arr[j])
                    {
                        makeset1(i);
                    }
                }

                c1=1;
                flag[1]=1;
                dfs(1);

                if(c1==n && ans1<=ans2_t)
                {
                    ans2=min(ans2,ans2_t);
                }

            }

            if(ans2==inf)
                cout<<"No second way\n";
            else
                cout<<ans2<<endl;

        }
    }
    return 0;
}


