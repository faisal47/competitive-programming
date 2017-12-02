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
#define sz 10010
using namespace std;
typedef long long ll;
map<string,int>maps;
vec_<int>v[sz];
bool flag_cycle_ase,color[sz];
void scc(int from)
{
    int to,i;
    for(i=0;i<v[from].size();i++)
    {
        to=v[from][i];
        if(!color[to])
        {
            color[to]=1;
            scc(to);
        }
        else
        {
            flag_cycle_ase=1;
        }
    }
}
int main ()
{
    string a,b;
    int n=1,t=1,test,m,i,j;
    sci1(test);
    while(test--)
    {
        clr(maps);
        sci1(m);
        while(m--)
        {
            cin>>a>>b;
            if(maps.find(a)==maps.end())
            maps[a]=n++;
            if(maps.find(b)==maps.end())
            maps[b]=n++;
            v[maps[a]].pb(maps[b]);
        }
        flag_cycle_ase=0;
        for(i=1;i<=n;i++)
        {
//            if(!color[i])
            for(j=1;j<=n;j++)
            color[j]=0;
            color[i]=1;
            scc(i);
        }
        if(flag_cycle_ase)
        printf("Case %d: No\n",t++);
        else
        printf("Case %d: Yes\n",t++);
        for(i=1;i<=n;i++)
        {
            color[i]=0;
            clr(v[i]);
        }
    }
    return 0;
}

