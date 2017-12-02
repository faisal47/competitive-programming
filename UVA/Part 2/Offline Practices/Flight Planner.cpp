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

#define mt

int dp[12][1010];
int arr[12][1010],r,c,n;

int solve(int a,int b)
{
    if(a==2 && b==n)
        return -arr[2][n]+20;

    if(a<2 || a>10 || b<1 || b>n)
        return inf;

    int &ret=dp[a][b];

    if(ret != -1)
        return ret;

    ret=inf;

    ret=min(ret,-arr[a][b]+60+solve(a+1,b+1));
    ret=min(ret,-arr[a][b]+30+solve(a,b+1));

    if(a>2)
        ret=min(ret,-arr[a][b]+20+solve(a-1,b+1));

    return ret;
}

int main ()
{
    int test,i,j;
    sci1(test);
    while(test--)
    {
        sci1(n);

        c=n/100;

        n/=100;

        for(j=10; j>=1; j--)
            for(i=1; i<=c; i++)
                sci1(arr[j][i]),dp[j][i]=-1;

        int ans=60-arr[1][1]+solve(2,2);

        cout<<ans<<endl;

        if(test)
            cout<<endl;
    }

    return 0;
}


