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

#define mt 110

int dp[mt][mt];
string dp2[mt][mt];

string a,b;

int solve1(int i,int j)
{
    if(i>= sz(a) || j>=sz(b))
        return 0;

    int &ret=dp[i][j];

    if(ret!=-1)
        return ret;

    if(a[i] == b[j])
        ret=1+solve1(i+1,j+1);
    else
        ret=max(solve1(i+1,j),solve1(i,j+1));

    return ret;
}

string solve2(int i,int j)
{
    if(i>=sz(a) || j>=sz(b))
        return "";

    string &ret=dp2[i][j];

    if(ret!="-1")
        return ret;

    if(a[i] == b[j])
    {
        ret=a[i]+solve2(i+1,j+1);
    }
    else if(solve1(i+1,j) > solve1(i,j+1))
    {
        ret=solve2(i+1,j);
    }
    else if(solve1(i+1,j) < solve1(i,j+1))
    {
        ret=solve2(i,j+1);
    }
    else
    {
        string a1=solve2(i+1,j);
        string b1=solve2(i,j+1);

        if(a1<=b1)
            ret=a1;
        else
            ret=b1;
    }

    return ret;
}

int main ()
{
    int test,t=1,ans,i,j;
    cin>>test;
    while(test--)
    {
        cin>>a>>b;
        ms(dp,-1);

        ans=solve1(0,0);

        for(i=0; i<=sz(a); i++)
            for(j=0; j<=sz(b); j++)
                dp2[i][j]="-1";

        if(!ans)
            printf("Case %d: :(\n",t++);
        else
        {
            printf("Case %d: ",t++);
            cout<<solve2(0,0)<<endl;
        }
    }

    return 0;
}


