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
#define sort_n(a) sort(a.begin(),a.end())
#define sort_m(a) sort(a.begin(),a.end(),comp)
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define scch(a) scanf("%c",&a)
#define scll1(a) scanf("%I64d",&a)
#define scll2(a,b) scanf("%I64d %I64d",&a,&b)
#define scll3(a,b,c) scanf("%I64d %I64d %I64d",&a,&b,&c)
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define scd1(a) scanf("%lf",&a)
#define scd2(a,b) scanf("%lf %lf",&a,&b)
#define scd3(a,b,c) scanf("%lf %lf %lf",&a,&b,&c)
#define sz(a) a.size()
#define mt 510
using namespace std;
typedef long long ll;
ll arr[mt][mt],n,m,ans[mt][mt];
bool flag[mt][mt];
ll dfs(int s,int e,int hate)
{
    if(s==n && e==m)return 0;
    if(s>n || e>m)return inf;
    ll a,b,hate1,hate2;
    if(s+1>n)
    a=inf;
    else
    {
        a=hate+arr[s+1][e];
        if(a<0)
        {
            hate1=0;
            a=abs(a);
        }
        else if(a==0)
        {
            a=1;hate=0;
        }
    }
    return max(arr[s][e]+dfs(s+1,e),arr[s][e]+dfs(s,e+1));
}
int main ()
{
    ll i,j,test,ans;
    scll1(test);
    while(test--)
    {
        scll2(n,m);
        for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            scll1(arr[i][j]);
        }
        ans=dfs(1,1,0);
        cout<<ans<<endl;;
    }
    return 0;
}

