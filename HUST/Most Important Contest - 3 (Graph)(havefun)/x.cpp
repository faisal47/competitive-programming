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
int X[]={-1,0,1,0};
int Y[]={0,1,0,-1};

///***************************************************** ekhon kamer kam ********************************************************************///

#define mt 45

int dist[mt][mt],n,m,ans,c;

bool col[mt][mt];

void dfs(int u1,int u2,int m1,int k,int mot)
{
    if(c==m1)
        return;
    c++;
    col[u1][u2]=1;
    int v1,i,v2;

    for(i=0;i<4;i++)
    {
        v1=X[i] + u1;
        v2=Y[i] + u2;
        if(v1>=1 && v2>=1 && v1<=n && v2<=m && !col[v1][v2] && dist[v1][v2]>=k && dist[v1][v2]<=k+mot)
        dfs(v1,v2,m1,k,mot);
    }

    return;
}

bool okay(int mot,int m1)
{
    int k,i,j;

    for(k=0;k + mot<100 ; k++)
    {
        ms(col,0);

        for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(!col[i][j] && dist[i][j]>=k && dist[i][j]<=k+mot)
            {
                c=0;
                dfs(i,j,m1,k,mot);
                if(c == m1)
                    return 1;
            }
        }
    }

    return false;
}

int bs(int k)
{
    int lo,hi,mid;

    lo=0;
    hi=99;

    while(lo <= hi)
    {
        mid = (lo + hi) >> 1;

        if(okay(mid,k))
        {
            ans=mid;
            hi=mid-1;
        }
        else
            lo=mid+1;
    }

    return ans;
}

int main ()
{
    cin>>n>>m;

    int i,j;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            cin>>dist[i][j];
    int q;
    cin>>q;
    int k;
    while(q--)
    {
        cin>>k;
        cout<<bs(k)<<endl;
    }

    return 0;
}
