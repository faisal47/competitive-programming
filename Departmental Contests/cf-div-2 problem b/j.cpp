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
#define pri1(a) printf("%d ",a)
#define pri2(a,b) printf("%d %d ",a,b)
#define prll1(a) printf("%I64d ",a)
#define prll2(a,b) printf("%I64d %I64d ",a,b)
#define sz(a) a.size()
#define mt 100010
using namespace std;
vec_<ll>v[mt];
bool col[mt];
ll n,ans=0,i,arr[mt],a,b,mini;
ll bfs()
{
    col[1]=1;
    queue<ll>q;
    q.push(1);
    while(!q.empty())
    {
        mini=inf;
        a=q.front();q.pop();
        for(i=0;i<sz(v[a]);i++)
        {
            b=v[a][i];
            if(!col[b])
            {
                col[b]=1;
                q.push(b);
                mini=min(mini,arr[b]);
            }
        }
    }
}
int main ()
{
    scll1(n);
    for(i=1;i<=n;i++)scll1(arr[i]);
    n--;
    for(i=1;i<=n;i++)
    {
        scll2(a,b);
        v[a].pb(b);
        v[b].pb(a);
    }
    n++;
    cout<<bfs()<<endl;
    return 0;
}

