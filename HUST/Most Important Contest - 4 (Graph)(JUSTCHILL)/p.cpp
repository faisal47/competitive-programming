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

#define mt 40010

struct data
{
    int node,cost;
    char ch;
    bool operator < (const data &p) const
    {
        return cost>p.cost;
    }
};
priority_queue<data>q;
vec_<data>adj[mt];

int dist[mt][30];

int dj(int s,int e,int c)
{
    while(!q.empty())q.pop();
    data u,v;
    u.ch='z'+3;
    u.node=s;
    u.cost=0;
    int i,j,d;
    char a;
    for(i=1; i<=c; i++)
        if(i==s)
        {
            for(j=0; j<26; j++)
                dist[i][j]=0;
        }
        else
        {
            for(j=0; j<26; j++)
                dist[i][j]=inf;
        }

    dist[s][u.ch-'a']=0;

    q.push(u);

    while(!q.empty())
    {
        u=q.top();
        q.pop();
        for(i=0;i<sz(adj[u.node]);i++)
        {
            v=adj[u.node][i];
            if(u.ch!=v.ch)
            {
                d=v.cost;
                a=v.ch;
                if(dist[v.node][a-'a'] > dist[u.node][u.ch-'a'] + d)
                {
                    dist[v.node][a-'a'] = dist[u.node][u.ch-'a'] + d;
                    q.push(v);
                }
            }
        }
    }

    j=inf;

    for(i=0;i<26;i++)
        j=min(j,dist[e][i]);

    return j;
}

int main ()
{
    map<string,int>ma;
    int m,s,e,c,i;
    string st1,st2,word;
    while(cin>>m && m)
    {
        c=1;
        clr(ma);
        cin>>st1>>st2;
        if(ma.find(st1)==ma.end())ma[st1]=c++;
        if(ma.find(st2)==ma.end())ma[st2]=c++;

        s=ma[st1];
        e=ma[st2];



        while(m--)
        {
            cin>>st1>>st2>>word;
            if(ma.find(st1)==ma.end())ma[st1]=c++;
            if(ma.find(st2)==ma.end())ma[st2]=c++;

            adj[ma[st1]].pb({ma[st2],sz(word),word[0]});
            adj[ma[st2]].pb({ma[st1],sz(word),word[0]});
        }

        s=dj(s,e,c);
        if(s==inf)
            pf("impossivel\n");
        else
            cout<<s<<endl;
        for(i=1; i<=c; i++)
            clr(adj[i]);

    }
    return 0;
}

