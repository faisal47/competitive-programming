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
#define mt 110
using namespace std;
int flag[mt],ans,s,v1;
bool col[mt];
vec_<int>v[mt];
void make_ans(int s)
{
    int v2;
    for(int i=0;i<sz(v[s]);i++)
    {
        v2=v[s][i];
        if(!col[v2])
        {
            ans++;
            col[v2]=1;
        }
    }
}
void bfs()
{
    queue<int>q;
    q.push(1);
    int i;
    flag[1]=1;
    while(!q.empty())
    {
        s=q.front();
        q.pop();

        if(flag[s]==2)
        {
            make_ans(s);
        }

        for(i=0; i<sz(v[s]); i++)
        {
            v1=v[s][i];
            if(!flag[v1])
            {
                if(flag[s]==1)
                flag[v1]=2;
                else
                flag[v1]=1;
                q.push(v1);
            }
        }

    }
}
int main ()
{
    int n,test,t=1,i,j,m;
    sci1(test);
    while(test--)
    {
        ans=0;
        sci1(n);
        sci1(m);
        for(i=1; i<=n; i++)
        {
            clr(v[i]);
            col[i]=flag[i]=0;
        }
        while(m--)
        {
            sci2(i,j);
            v[i].pb(j);
            v[j].pb(i);
        }
        bfs();
        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}

