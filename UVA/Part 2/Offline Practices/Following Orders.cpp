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

#define mt 200

map<char,int>m1;
map<int,char>m2;

char arr[200];
int flag[mt],n;
vec_<int>adj[mt],v,res;

bool comp(int a,int b)
{
    return m2[a]<m2[b];
}

bool check()
{
    if(sz(res))
    {
        int a=res[sz(res)-1];
        int i;
        for(i=0;i<sz(adj[a]);i++)
        {
            if(flag[adj[a][i]])
                return 0;
        }
    }

    return 1;
}

void bt()
{
    if(!check())
        return;
    int i;
    if(sz(res)==sz(v))
    {
        for(i=0; i<sz(res); i++)
            cout<<m2[res[i]];
        cout<<endl;
        return;
    }

    for(i=0; i<sz(v); i++)
    {
        if(!flag[v[i]])
        {
            flag[v[i]]=1;
            res.pb(v[i]);
            bt();
            flag[v[i]]=0;
            res.pop_back();
        }
    }
}

int main ()
{
    int i,len,a1,b1,t=0;
    char a,b;
    while(gets(arr))
    {
        if(t++)
            cout<<endl;
        n=1;
        clr(m1);
        clr(m2);
        clr(v);
        len=strlen(arr);
        for(i=0; i<len; i+=2)
        {
            a=arr[i];
            if(m1.find(a)==m1.end())
            {
                m1[a]=n;
                m2[n]=a;
                v.pb(n);
                n++;
            }
        }
        gets(arr);
       // puts(arr);
        len=strlen(arr);
        for(i=1; i<n; i++)
            clr(adj[i]);
        for(i=0; i<len; i+=4)
        {
            a=arr[i];
            b=arr[i+2];
            a1=m1[a];
            b1=m1[b];
            adj[a1].pb(b1);
        }
        sort(all(v),comp);
        bt();
    }
    return 0;
}



