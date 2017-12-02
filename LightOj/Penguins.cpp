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
#include <assert.h>
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
#define eps 1E-9
#define sf scanf
#define pf printf
#define all(a) a.begin(),a.end()
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
#define deb1(a) cout<<a<<endl;
#define deb2(a,b) cout<<a<<" "<<b<<endl
#define deb3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
using namespace std;
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};

///***************************************************** ekhon kamer kam ********************************************************************///

#define mt 220
#define mod

struct info1
{
    int a,b,c,d;
};

info1 info[mt];
int n,dist_t[mt][mt],dist[mt][mt],par[mt],mot;
bool flag[mt];
vec_<int>adj[mt];

void make_edge(int a,int b,int cost)
{
    adj[a].pb(b);
    dist[a][b]=cost;
}

vec_<int>ans;
int sink,flow,mot2;

queue<int>q;

bool has_path()
{
    int s1,i,v;
    while(!q.empty())q.pop();

    q.push(1);
    ms(flag,0);
    par[1]=-1;
    flag[1]=1;

    while(!q.empty())
    {
        s1=q.front();
        q.pop();
        for(i=0; i<sz(adj[s1]); i++)
        {
            v=adj[s1][i];
            if(!flag[v] && dist_t[s1][v]>0)
            {
                //cout<<v<<endl;
                //if(v==sink)
                // cout<<"in has_path  sink =="<<sink<<endl;
                par[v]=s1;
                if(v==sink)return true;
                flag[v]=1;
                q.push(v);
            }
        }
    }

    return false;
}

void visit_path(int e1)
{
    if(par[e1]==-1)return;
    int v1=par[e1];
    flow=min(flow,dist_t[v1][e1]);
    visit_path(v1);
    dist_t[v1][e1]-=flow;
    dist_t[e1][v1]+=flow;
}

int max_flow()
{
    int res=0;

    while(has_path())
    {
        flow=inf;
        visit_path(sink);
        res+=flow;
    }
    //cout<<"res == "<<res<<endl;
    return res;
}

void solve()
{
    //cout<<"in solve == mot2 == "<<mot2<<endl;
    clr(ans);
    int i,res,j,k;

    for(i=2; i<=n; i++)
    {
        sink=i;

        for(j=1; j<=mot; j++)
        {
            for(k=1; k<=mot; k++)
                dist_t[j][k]=dist[j][k];
        }

        res=max_flow();

        if(res == mot2)
            ans.pb(i-2);
    }
}

int main ()
{
    int i,test,t=1,j;
    dd d,d1;
    scanf("%d",&test);

    while(test--)
    {
        scanf("%d %lf",&n,&d);

        n++;

        mot=(n<<1)+10;

        for(i=2; i<=n; i++)
            scanf("%d %d %d %d",&info[i].a,&info[i].b,&info[i].c,&info[i].d);

        for(i=1; i<=mot; i++)
        {
            clr(adj[i]);
            for(j=1; j<=mot; j++)
                dist[i][j]=0;
        }

        for(i=2; i<=n; i++)
        {
            make_edge(i,i+n,info[i].d);
            make_edge(i+n,i,0);
        }

        mot2=0;

        for(i=2; i<=n; i++)
        {
            mot2+=info[i].c;

            make_edge(1,i,info[i].c);
            make_edge(i,1,0);

            for(j=2; j<=n; j++)
            {
                if(i==j)
                    continue;

                d1=hypot((dd)info[i].a-(dd)info[j].a,(dd)info[i].b-(dd)info[j].b);

                if(d1<d || fabs(d-d1)<eps)
                {
                    //cout<<"dur == "<<d1<<" "<<i<<" "<<j<<endl;
                    make_edge(i+n,j,inf);
                    make_edge(j,i+n,0);
//                    make_edge(j+n,i,info[j].d);
//                    make_edge(i,j+n,0);
                }
            }
        }

        solve();

        printf("Case %d:",t++);

        if(sz(ans))
        {
            for(i=0; i<sz(ans); i++)
                printf(" %d",ans[i]);
            puts("");
        }
        else
            puts(" -1");

    }

    return 0;
}

