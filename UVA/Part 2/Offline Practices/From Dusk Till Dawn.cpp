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
    int node,c,d,blood;
    bool operator < (const data &p)const
    {
        return p.blood < blood;
    }
};

vec_<data>adj[mt];

void dj(int s)
{
    dist[s]=0;
    data u,v;
    int i;
    priority_queue<data>q;
    q.push({s,0,18,0});
    while(!q.empty())
    {
        u=q.top();
        q.pop();

        for(i=0;i<sz(adj[u.node]);i++)
        {
            v=adj[u.node][i];
            v.blood+=u.blood;
            if((u.d>=18 && v.c<u.d && v.c>=18) || (u.d<=6 && (v.c<u.d || v.c>=18)))
                v.blood++;

            if(dist[v.node] > v.blood)
            {
                dist[v.node]=v.blood;
                q.push(v);
            }
        }
    }
}

int main ()
{
    map<string,int>ma;
    int test,n,t=1,m,c,d,i;
    string a,b;

    cin>>test;

    while(test--)
    {
        cin>>m;
        n=1;
        clr(ma);

        for(i=1;i<105;i++)
            clr(adj[i]),dist[i]=inf;

        while(m--)
        {
            cin>>a>>b>>c>>d;

            if(d>12)
                continue;

            d+=c;

            if(d>24)
                d-=24;

            if(ma.find(a)==ma.end())ma[a]=n++;
            if(ma.find(b)==ma.end())ma[b]=n++;

            if((c>=18 || c<6) && (d>18 || d<=6))
            adj[ma[a]].pb({ma[b],c,d,0});

        }

        cin>>a>>b;

        dj(ma[a]);

        printf("Test Case %d.\n",t++);
        if(dist[ma[b]]>=inf)
            cout<<"There is no route Vladimir can take.\n";
        else
            printf("Vladimir needs %d litre(s) of blood.\n",dist[ma[b]]);
    }
    return 0;
}

