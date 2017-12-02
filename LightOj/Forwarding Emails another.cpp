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
#define sz 50010
using namespace std;
int low[sz],exact[sz],dp[sz],t,n,col[sz],scc_count,under_scc[sz],scc_mini[sz],scc_mot[sz];
vec_<int>v[sz],dag[sz];
stack<int>s;
void initialize()
{
    int i;
    scc_count=0;
    t=1;
    while(!s.empty())
    s.pop();
    for(i=1;i<=n;i++)
    {
        clr(v[i]);
        clr(dag[i]);
        exact[i]=low[i]=col[i]=0;
        dp[i]=-1;
    }
}
void tarjan(int a)
{
    s.push(a);
    col[a]=1;
    low[a]=exact[a]=t++;
    int i,j;
    for(i=0;i<v[a].size();i++)
    {
        j=v[a][i];
        if(!col[j])
        {
           tarjan(j);
           low[a]=min(low[a],low[j]);
        }
        else if(col[j]==1)
         low[a]=min(low[a],exact[j]);
    }
    if(exact[a]==low[a])
    {
        int c=0,mini=inf;
        scc_count++;
        j=-1;
        while(j!=a)
        {
            j=s.top();
            s.pop();
            //cout<<"its scc "<<scc_count<<" "<<j<<endl;
            col[j]=2;
            under_scc[j]=scc_count;
            c++;
            mini=min(mini,j);
        }
        scc_mot[scc_count]=c;
        scc_mini[scc_count]=mini;
    }
}
void create_dag()
{
    int i,j,p,q;
    for(i=1;i<=n;i++)
    {
        p=under_scc[i];
        for(j=0;j<v[i].size();j++)
        {
            q=under_scc[v[i][j]];
            if(p!=q)
            {
              //  cout<<"in dag "<<p<<" "<<q<<endl;
                dag[p].pb(q);
            }
        }
    }
}
int dfs(int a)
{
    int &ret=dp[a];
    if(ret!=-1)
    return ret;
    ret=scc_mot[a];
    int i;
    for(i=0;i<dag[a].size();i++)
    ret+=dfs(dag[a][i]);
    return ret;
}
int main ()
{
    int test,te=1,i,a,b,ans,ans_mot;
    sci1(test);
    while(test--)
    {
        sci1(n);
        initialize();
        for(i=1;i<=n;i++)
        {
            sci2(a,b);
            v[a].pb(b);
        }
        for(i=1;i<=n;i++)
        if(!col[i])
        tarjan(i);
        create_dag();
        ans_mot=-2;
        ans=inf;
        for(i=1;i<=scc_count;i++)
        {
            dfs(i);
//            cout<<"in dp "<<dp[i]<<" "<<i<<endl;
            if(dp[i]>ans_mot)
            {
                ans=scc_mini[i];
                ans_mot=dp[i];
                //cout<<"in dp "<<dp[i]<<" "<<i<<" "<<ans<<endl;
            }
            else if(dp[i]==ans_mot)
                ans=min(ans,scc_mini[i]);
        }
        printf("Case %d: %d\n",te++,ans);
    }
    return 0;
}
