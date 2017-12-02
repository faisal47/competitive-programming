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
vec_<int>v1[sz],v2;
int col[sz];
int n;
void bfs1(int a)
{
    queue<int>q;
    q.push(a);
    int b,i;
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        for(i=0;i<v1[a].size();i++)
        {
            b=v1[a][i];
            if(!col[b])
            {
                col[b]=1;
                q.push(b);
            }
        }
    }
}
void bfs2(int a)
{
    queue<int>q;
    q.push(a);
    int b,i;
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        for(i=0;i<v1[a].size();i++)
        {
            b=v1[a][i];
            if(col[b]!=2)
            {
                col[b]=2;
                q.push(b);
            }
        }
    }
}
int main ()
{
    int i,a,b,m,test,t=1,c;
    sci1(test);
    while(test--)
    {
        c=0;
        clr(v2);
        sci2(n,m);
        for(i=1;i<=n;i++)
        {
            clr(v1[i]);
            col[i]=0;
        }
        while(m--)
        {
         sci2(a,b);
         v1[a].pb(b);
        }
        for(i=1;i<=n;i++)
        if(!col[i])
        {
            col[i]=1;
            v2.pb(i);
            bfs1(i);
        }
        for(i=v2.size()-1;i>=0;i--)
        if(col[v2[i]]!=2)
        {
            c++;
            col[v2[i]]=2;
            bfs2(v2[i]);
        }
        printf("Case %d: %d\n",t++,c);
    }
    return 0;
}

