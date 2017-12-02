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
#define inf 1<<20
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
#define ll long long
#define ull unsigned long long
#define mt 210
using namespace std;


int dist[mt][mt],dp[(1<<13)+10][14],n,m,arr[mt][mt];
int dx[]={0,0,1,-1},dy[]={-1,1,0,0},stop[15],gold[15][15];
vector<pii>res;

void bfs(pii s)
{
    queue<pii>Q;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            dist[i][j]=inf;
    Q.push(s);
    dist[s.first][s.second]=0;//arr[s.first][s.second];
    while(!Q.empty())
    {
        pii p=Q.front();
        Q.pop();
        for(int i=0;i<4;i++)
        {
            int tx=p.first+dx[i];
            int ty=p.second+dy[i];
            if(tx>=0 && tx<n && ty>=0 && ty<m &&\
               arr[tx][ty]!=-1 &&dist[tx][ty]>dist[p.first][p.second]+arr[tx][ty])
            {
                dist[tx][ty]=dist[p.first][p.second]+arr[tx][ty];
                Q.push(mp(tx,ty));
            }
        }
    }
}
int solve(int mask,int last)
{
    if(mask==((1<<res.size())-1))
    {
        return stop[last];//-arr[res[last].first][res[last].second];
    }
    int &ret=dp[mask][last];
    if(ret!=-1)
    return ret;
    ret=inf;
    for(int i=0;i<res.size();i++)
    {
        if((mask&(1<<i))==1)
            continue;
        ret=min(ret,solve(mask|(1<<i),i)+gold[i][last]);
    }
    return ret;
}
int main ()
{
    int test,p,a,b;
    sci1(test);
    while(test--)
    {
//        cin>>n>>m;
        sci2(n,m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //cin>>arr[i][j];
                sci1(arr[i][j]);
            }
        }
        sci1(p);
        for(int i=0;i<p;i++)
        {
           // cin>>a>>b;
            sci2(a,b);
            res.pb(mp(a,b));
        }
        for(int i=0;i<res.size();i++)
        for(int j=0;j<res.size();j++)
            gold[i][j]=inf;
        for(int i=0;i<res.size();i++)
        {
            bfs(res[i]);
            for(int j=0;j<res.size();j++)
            {
                if(i!=j)
                {
                    gold[i][j]=dist[res[j].first][res[j].second];
                }
            }
        }
        for(int i=0;i<res.size();i++)
        {
            int mn=inf;
            bfs(res[i]);
            for(int j=0;j<n;j++)
            {
                mn=min(mn,dist[j][0]);
                mn=min(mn,dist[j][m-1]);
            }
            for(int j=0;j<m;j++)
            {
                mn=min(mn,dist[0][j]);
                mn=min(mn,dist[n-1][j]);
            }
            stop[i]=mn;
        }
        int ans=inf;
        ms(dp,-1);
        for(int i=0;i<res.size();i++)
        {
            ans=min(ans,solve(1<<i,i)+stop[i]+arr[res[i].first][res[i].sc]);
        }
        res.clear();
        if(ans>=inf)
            printf("0");
        else
        printf("%d\n",ans);
    }
    return 0;
}

