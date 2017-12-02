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

#define mt 50050

struct data
{
    int node,rasta,cost;
    bool operator < (const data& p) const
    {
        return cost > p.cost;
    }
};

priority_queue<data>q;

vec_<data>maan[mt];
int dist[mt];
map<string,int>ras1,city1;
map<int,string>ras2,city2;
struct par1
{
    int node,rasta,cost;
};
par1 par[mt];

void dj(int s,int e)
{
    while(!q.empty())
        q.pop();
    data u,v;
    u.cost=0;
    u.node=s;
    par[s]={s,0,0};
    dist[s]=0;
    u.rasta=0;
    q.push(u);
    int i,d;
    while(!q.empty())
    {
        u=q.top();
        q.pop();
        d=u.cost;
        for(i=0;i<sz(maan[u.node]);i++)
        {
            v=maan[u.node][i];
            v.cost+=d;

            if(dist[v.node]>v.cost)
            {
                dist[v.node]=v.cost;
                q.push(v);
                par[v.node]={u.node,v.rasta,v.cost-d};
                if(v.node==e)
                    return;
            }
        }
    }
}

void sprint(int n)
{
    int i;
    n++;
    for(i=0;i<n;i++)
        cout<<" ";
}

void dfs(int s)
{
    if(s==par[s].node)
        return;
    dfs(par[s].node);
    int i;

    cout<<city2[par[s].node];
    sprint(20-sz(city2[par[s].node]));

    cout<<city2[s];
    sprint(20-sz(city2[s]));

    cout<<ras2[par[s].rasta];
    sprint(10-sz(ras2[par[s].rasta]));

    pf("%5d\n",par[s].cost);

}

void out_put(int s,int e)
{
    cout<<"\n\nFrom                 To                   Route      Miles\n-------------------- -------------------- ---------- -----\n";
    dfs(e);
    cout<<"                                                     -----\n                                          Total      ";
    pf("%5d\n",dist[e]);
}

int main ()
{
    char arr[mt];
    data pdata;
    string temp1,temp2,temp3;
    int temp4;
    int len,i,flag,cr=1,cc=1;
    while(gets(arr))
    {
        len=strlen(arr);
        if(len==0)
            break;
        temp4=0;
        clr(temp1);
        clr(temp2);
        clr(temp3);
        flag=0;

        for(i=0;i<len;i++)
        {
            if(arr[i]==',')
            {
                if(flag==0)
                    flag=1;
                else if(flag==1)
                    flag=2;
                else
                    flag=3;
                continue;
            }
            if(flag==0)
                temp1+=arr[i];
            else if(flag==1)
                temp2+=arr[i];
            else if(flag==2)
                temp3+=arr[i];
            else
                temp4=(temp4*10)+(arr[i]-'0');
        }

        if(city1.find(temp1)==city1.end())
        {
            city1[temp1]=cc;
            city2[cc++]=temp1;
        }

        if(city1.find(temp2)==city1.end())
        {
            city1[temp2]=cc;
            city2[cc++]=temp2;
        }

        if(ras1.find(temp3)==ras1.end())
        {
            ras1[temp3]=cr;
            ras2[cr++]=temp3;
        }

        maan[city1[temp1]].pb({city1[temp2],ras1[temp3],temp4});
        maan[city1[temp2]].pb({city1[temp1],ras1[temp3],temp4});

    }

    while(gets(arr))
    {
        len=strlen(arr);
        for(i=1;i<cc;i++)
            dist[i]=inf;

        flag=0;
        clr(temp1);
        clr(temp2);
        for(i=0;i<len;i++)
        {
            if(arr[i]==',')
            {
                if(flag==0)
                    flag=1;
                continue;
            }
            if(flag==0)
                temp1+=arr[i];
            else if(flag==1)
                temp2+=arr[i];
        }
        dj(city1[temp1],city1[temp2]);
        out_put(city1[temp1],city1[temp2]);
    }
    return 0;
}


