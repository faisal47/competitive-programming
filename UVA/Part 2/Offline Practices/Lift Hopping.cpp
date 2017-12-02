#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
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

#define mt 110

int dist[mt];

struct data
{
    int node,cost,lift;

    bool operator < (const data &p)const
    {
        return cost > p.cost;
    }
};

priority_queue<data>q;
vec_<data>adj[mt];

int dj(int e)
{
    //q.push({0,0,1});
    data u,v;

    int i;

    dist[0]=0;

    while(!q.empty())
    {
        u=q.top();
        q.pop();

        for(i=0; i<sz(adj[u.node]); i++)
        {
            v=adj[u.node][i];
            v.cost+=u.cost;

            if(u.lift!=v.lift && u.node)
                v.cost+=60;

            if(dist[v.node] > v.cost)
            {
//                cout<<u.node<<" "<<v.node<<endl;
//                cout<<u.cost<<" "<<v.node<<endl;
//                cout<<u.node<<" "<<v.node<<endl;
                dist[v.node] = v.cost;
                q.push(v);
            }
        }
    }

    return dist[e];
}

int main ()
{
    int ans,n,k,t[mt],num,i,j,e,w;
    string st;
    vec_<int>v;
    while(cin>>n>>e)
    {

        while(!q.empty())q.pop();

        for(i=1; i<=n; i++)
        {
            cin>>t[i];
        }

        for(i=0; i<=105; i++)
        {
            dist[i]=inf;
            clr(adj[i]);
        }
        getchar();

        for(k=1; k<=n; k++)
        {
            getline(cin,st);

            stringstream ss;
            ss<<st;

            clr(v);
            while(ss >> num)
                {
                    v.pb(num);
                    if(!num)
                    q.push({0,0,k});
                }

            for(i=0; i<sz(v); i++)
                for(j=i+1; j<sz(v); j++)
                {
                    w=abs(v[i]-v[j])*t[k];
                    adj[v[i]].pb({v[j],w,k});
                    adj[v[j]].pb({v[i],w,k});
                }
        }

        ans=dj(e);

        if(ans >= inf)
            cout<<"IMPOSSIBLE\n";
        else
            cout<<ans<<endl;
    }
    return 0;
}

