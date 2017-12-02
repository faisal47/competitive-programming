#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <stack>
#include <utility>
#include <queue>
#include <algorithm>
#include <math.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define FOR_0(i,n) for(i=0;i<n;i++)
#define FOR_1(i,n) for(i=1;i<=n;i++)
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define eps 1E-7
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define scll1(a) scanf("%lld",&a)
#define scll2(a,b) scanf("%lld %lld",&a,&b)
#define scll3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define scd1(a) scanf("%lf",&a)
#define scd2(a,b) scanf("%lf %lf",&a,&b)
#define scd3(a,b,c) scanf("%lf %lf %lf",&a,&b,&c)
#define sz
using namespace std;
typedef long long ll;
struct d1
{
    ll x,y;
} data[110];
vec_<int>v[110];
ll f;
bool flag,col[110];
void dfs(ll a)
{
    col[a]=1;
    if(flag || a==f)
    {
        flag=1;
        return;
    }
    ll i,j;
    for(i=0; i<v[a].size(); i++)
    {
        j=v[a][i];
        if(!col[j])
            dfs(j);
    }
}
int main ()
{
    ll i,j,a,b,n,c=1;
    cin>>n;
    while(n--)
    {
        cin>>a>>i>>j;
        if(a==1)
        {
            data[c].x=i;
            data[c].y=j;
            c++;
            for(i=1; i<c; i++)
                if((data[i].x > data[c-1].x && data[i].x < data[c-1].y)|| (data[i].y > data[c-1].x && data[i].y < data[c-1].y))
                    v[i].pb(c-1);
            for(i=1; i<c; i++)
                if((data[i].x < data[c-1].x && data[i].y > data[c-1].x)|| (data[i].x < data[c-1].y && data[i].y > data[c-1].y))
                    v[c-1].pb(i);
        }
        else
        {
            flag=0;
            ms(col,0);
            f=j;
            dfs(i);
            if(flag)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
    return 0;
}