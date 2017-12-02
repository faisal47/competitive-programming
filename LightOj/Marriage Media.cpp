#include <bits/stdc++.h>
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sz(a) a.size()
#define mt 55
using namespace std;
typedef long long ll;
int a[mt][3],b[mt][3],n,m,par[mt],i,j,ans;
bool col[mt];
vec_<int>v[mt];
bool dfs(int s)
{
    int p,asi;
    for(p=0;p<sz(v[s]);p++)
    {
        asi=v[s][p];
        if(!col[asi])
        {
            col[asi]=1;
            if(par[asi]==-1 || dfs(par[asi]))
            {
                par[asi]=s;
                return 1;
            }
        }
    }
    return 0;
}
int bpm()
{
    ans=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        col[j]=0;
        ans+=dfs(i);
    }
    return ans;
}
int main ()
{
    int test,t=1;
    sci1(test);
    while(test--)
    {
        sci2(n,m);
        for(i=1;i<=n;i++)
        {
            clr(v[i]);
            sci3(a[i][0],a[i][1],a[i][2]);
        }
        for(j=1;j<=m;j++)
        {
            par[j]=-1;
            sci3(b[j][0],b[j][1],b[j][2]);
            for(i=1;i<=n;i++)
            {
                if(b[j][2]==a[i][2] && abs(b[j][1]-a[i][1])<=5 && abs(b[j][0]-a[i][0])<=12)
                v[i].pb(j);
            }
        }
        printf("Case %d: %d\n",t++,bpm());
    }
    return 0;
}

