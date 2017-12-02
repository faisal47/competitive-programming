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
#define pb push_back
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()

#define scll1(a) scanf("%I64d",&a)
#define scll2(a,b) scanf("%I64d %I64d",&a,&b)
#define scll3(a,b,c) scanf("%I64d %I64d %I64d",&a,&b,&c)
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sci3(a,b,c) scanf(" %d %d %d",&a,&b,&c)

#define sz(a) a.size()
#define ll long long

#define mt 205010
using namespace std;

vec_<ll>adj[mt],dist[mt];
ll par[mt],ans_main,col[mt],fl,dist1[mt];

void bfs()
{
    queue<ll>q;
    q.push(0);
    dist1[0]=0;
    ll i,v;
    ll s;
    col[0]=fl;
    while(!q.empty())
    {
        s=q.front();
        q.pop();

        for(i=0;i<sz(adj[s]);i++)
        {
            v=adj[s][i];
            if(col[v]!=fl)
            {
                q.push(v);
                col[v]=fl;
                dist1[v]=dist1[s]+dist[s][i];
            }
        }
    }
}

int main ()
{
    ll n,i,n1,a,b,c,ans;
    while(scll1(n)==1)
    {
        n1=n+1;
        ans=(ll)(1LL<<62);



        for(i=0;i<n1;i++)
        {
            clr(adj[i]);
            clr(dist[i]);
            col[i]=0;
//            cin>>c;
            scll1(c);
            par[i]=c;
        }
            clr(adj[n1]);
            clr(dist[n1]);
            col[n1]=0;
        ans_main=0LL;
        for(i=1;i<=n;i++)
        {
//            cin>>a>>b>>c;
            scll3(a,b,c);
            adj[a].pb(b);
            dist[a].pb(c);

            adj[b].pb(a);
            dist[b].pb(c);

            ans_main+=(c*2);
        }

        fl=1LL;
        bfs();
        for(i=0;i<n1;i++)
        ans=min(ans,ans_main-dist1[i]+par[i]);
//        cout<<ans<<endl;
       cout<<ans<<endl;
    }
    return 0;
}


