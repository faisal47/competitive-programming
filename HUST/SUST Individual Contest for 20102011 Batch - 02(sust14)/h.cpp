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
#define eps 1E-7
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

#define mt  10010

int low[mt],tim[mt],ti;
vec_<int>adj[mt];
bool col1[mt],col2[mt];
//stack<pii>s;
stack<int>s;

void bcc(int par,int node)
{
    //cout<<node<<endl;
    tim[node]=low[node]=ti++;

    int i,v,us,vs,cnt;

    for(i=0;i<sz(adj[node]);i++)
    {
        v=adj[node][i];
        if(v== par)
            continue;

        if(!tim[v])
        {
            s.push(node);
            s.push(v);
//            s.push(mp(node,v));
            bcc(node,v);
            low[node]=min(low[node],low[v]);

            if(tim[node] <= low[v])
            {
                cnt=0;
                while(!s.empty())
                {
                    vs=s.top();
                    s.pop();
                    us=s.top();
                    s.pop();
//                    us=s.top().fs;
//                    vs=s.top().sc;
//                    s.pop();
                    cnt++;
                    if(cnt == 1 && node == us && v == vs)
                        break;
                    else if(node == us && v == vs)
                    {
                       // cout<<us<<" "<<vs<<endl;
                        col1[us]=col1[vs]=true;
                        break;
                    }
                    else
                    {

                       // cout<<us<<" "<<vs<<endl;
                        col1[us]=col1[vs]=true;
                    }
                }
            }
        }
         else if(tim[node] > tim[v])
                low[node]=min(low[node],tim[v]);
    }

    //cout<<"node == "<<node<<" "<<tim[node]<<" "<<low[node]<<endl;
}

void dfs(int node)
{
    int i,v;
    for(i=0;i<sz(adj[node]);i++)
    {
        v=adj[node][i];
        if(!col1[v] && !col2[v])
        {
            col2[v]=true;
            ti++;
            dfs(v);
        }
    }
}

int main ()
{
   // freopen("output1.txt","w",stdout);
    int test,t=1,n,m,a,b,i;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&m);

        for(i=1;i<=n;i++)
        {
            col1[i]=col2[i]=false;
            clr(adj[i]);
            low[i]=tim[i]=0;
        }

        while(m--)
        {
            scanf("%d %d",&a,&b);
            adj[a].pb(b);
            adj[b].pb(a);
        }

        ti=0;
       // cout<<"\n\n\n\n";
        while(!s.empty())s.pop();

        for(i=1;i<=n;i++)
            if(!tim[i])
            bcc(i,i);


        int ans=0;

        for(i=1;i<=n;i++)
        {
            if(!col1[i] && !col2[i])
            {
                col2[i]=true;
                ti=1;
                dfs(i);
                ans+=(ti*(ti-1))>>1;
            }
        }

        printf("Case #%d: %d\n",t++,ans);

    }
    return 0;
}
