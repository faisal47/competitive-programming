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

#define mt 30

vec_<int>adj[mt];
int flag[mt],n,c;

void dfs(int s)
{
    int i,v;
    for(i=0;i<sz(adj[s]);i++)
    {
        v=adj[s][i];
        if(!flag[v])
        {
            flag[v]=1;
            dfs(v);
        }
    }
}

int main ()
{
    char z,arr[4];
    int test,a,b,i,ans,t=0;
    scanf(" %d%c",&test,&z);
    gets(arr);

    while(test--)
    {
        gets(arr);
        z=arr[0];
        n=z-'A'+1;
       // cout<<n<<endl;
        for(i=0;i<n;i++)
        {
            clr(adj[i]);
            flag[i]=0;
        }

        while(gets(arr))
        {
            if(strlen(arr)==0)
                break;
            a=arr[0]-'A';
            b=arr[1]-'A';
            adj[a].pb(b);
            adj[b].pb(a);
        }
        ans=0;
        for(i=0;i<n;i++)
        {
            if(!flag[i])
            {
                flag[i]=1;
                dfs(i);
                ans++;
            }
        }
        if(t++)
            cout<<endl;
        pf("%d\n",ans);

    }
    return 0;
}


