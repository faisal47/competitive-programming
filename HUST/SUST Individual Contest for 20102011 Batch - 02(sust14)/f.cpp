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

#define mt (1<<15)+10

struct maan
{
    string name;
    int date,time;
};

vec_<maan>v;
int dp[mt],n,path1[mt],path2[mt];

int solve(int mask)
{
    if(mask == ((1<<n)-1))
        return 0;

    int &ret=dp[mask];
    if(ret!=-1)
        return ret;
    ret=inf;
    int i,time=0,rettemp,c=0;
    for(i=0; i<n; i++)
        if((mask & (1<<i)))
            time+=v[i].time,c++;

    for(i=0; i<n; i++)
        if(!(mask & (1<<i)))
        {
            if(time+v[i].time <= v[i].date)
                rettemp=solve(mask|(1<<i));
            else
                rettemp=solve(mask|(1<<i))+time+v[i].time - v[i].date;

            if(ret > rettemp)
            {
                ret=rettemp;
                path1[mask]=mask|(1<<i);
                path2[mask]=i;
            }
        }

    return ret;
}

void recur(int mask)
{
    if(mask == ((1<<n)-1))
        return;

    cout<<v[path2[mask]].name<<endl;
    recur(path1[mask]);
}

int main ()
{
    int test,a,ans,i;
    maan maan1;
    cin>>test;
    while(test--)
    {
        ms(dp,-1);
        clr(v);
        cin>>n;
        for(i=0; i<n; i++)
        {
            cin>>maan1.name>>maan1.date>>maan1.time;
            v.pb(maan1);
        }

        ans=solve(0);
       cout<<ans<<endl;

       recur(0);
    }
    return 0;
}
