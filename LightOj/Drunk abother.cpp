#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
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
#define sz 100010
using namespace std;
typedef long long ll;
int col[sz],color_now;
vec_<int>v[sz];
map<string,int>maps;
bool flag_stop;
void dfs(int a)
{
    int i,b;
    for(i=0;i<v[a].size();i++)
    {
        b=v[a][i];
        if(!col[b])
        {
            col[b]=color_now;
            dfs(b);
        }
        else if(col[b]==color_now)
        {
            flag_stop=1;
        }
    }
}
int main ()
{
    int m,n,i,t=1,test,q;
    string a,b;
    sci1(test);
    while(test--)
    {
        flag_stop=0;
        sci1(m);
        n=1;
        while(m--)
        {
            cin>>a>>b;
        if(maps.find(a)==maps.end())
        maps[a]=n++;
        if(maps.find(b)==maps.end())
        maps[b]=n++;
        v[maps[a]].pb(maps[b]);
        }
        //v[maps[b]].pb(maps[a]);
        color_now=2;
        for(i=1;i<n;i++)
        if(!col[i])
        {
            if(color_now==2)
            color_now=1;
            else
            color_now=2;
            col[i]=color_now;
            dfs(i);
            if(flag_stop)
            break;
        }
        if(flag_stop)
        printf("Case %d: No\n",t++);
        else
        printf("Case %d: Yes\n",t++);
        for(i=1;i<n;i++)
        {
            clr(v[i]);
            col[i]=0;
        }
        clr(maps);
    }
    return 0;
}

