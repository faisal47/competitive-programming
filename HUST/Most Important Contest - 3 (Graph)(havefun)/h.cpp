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

#define mt 510

int par[mt];
struct data1
{
    int a,b,c;
};

int ans,arr[510];
vec_<data1>data;

bool comp(data1 a,data1 b)
{
    return a.c<b.c;
}

int dur(int a,int b)
{
    int c=0,e,f,g=4;
    while(g--)
    {
        e=a%10;
        f=b%10;
        //deb3(e,f,min(abs(e-f),10-abs(e-f)));
        c+=min(abs(e-f),10-abs(e-f));

        a/=10;
        b/=10;
    }

    return c;
}

int find_par(int s)
{
    if(par[s]==s)
        return s;

    return par[s]=find_par(par[s]);
}

void make_set(int s)
{
    int u=find_par(data[s].a);
    int v=find_par(data[s].b);

    if(u==v)
        return;

    par[u]=v;

    //cout<<arr[data[s].a]<<" "<<arr[data[s].b]<<" "<<data[s].c<<endl;

    ans+=data[s].c;
}

int main ()
{
    int j,i,test,n,k;
    //cout<<dur(5678,9090)<<endl;
    sci1(test);
    arr[0]=0;

    while(test--)
    {
        clr(data);
        sci1(n);
        for(i=1;i<=n;i++)
            sci1(arr[i]);
        ans=0;

        k=inf;

        for(i=1;i<=n;i++)
            k=min(k,dur(0,arr[i]));

        for(i=1;i<=n;i++)
            for(j=1;j<i;j++)
            {
                data.pb({i,j,dur(arr[i],arr[j])});
            }

        sort(all(data),comp);

        for(i=0;i<=n;i++)
            par[i]=i;

        for(i=0;i<sz(data);i++)
            make_set(i);

        printf("%d\n",ans+k);
    }
    return 0;
}


