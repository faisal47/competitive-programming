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
#define mt
using namespace std;

//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};
int main ()
{
    ll n,m,i,j,ans=inf,a,b,c,d;

    cin>>n>>m>>i>>j>>a>>b;

    if((i==1 || i==n) && (j==1 || j==m))
    {
        cout<<0;
        return 0;
    }

    if((i-a<1 && i+a>n) || (j-b<1 && j+b>m))
    {
        cout<<"Poor Inna and pony!";
        return 0;
    }

    c=abs(1-i);
    d=abs(m-j);
    if(c%a==0 && d%b==0 && ((c/a)%2==(d/b)%2 ))
            ans=min(ans,max(c/a,d/b));

    c=abs(n-i);
    d=abs(1-j);
    if(c%a==0 && d%b==0 && ((c/a)%2==(d/b)%2 ))
        ans=min(ans,max(c/a,d/b));

    c=abs(n-i);
    d=abs(m-j);
    if(c%a==0 && d%b==0 && ((c/a)%2==(d/b)%2 ))
        ans=min(ans,max(c/a,d/b));

    c=abs(1-i);
    d=abs(1-j);
    if(c%a==0 && d%b==0 && ((c/a)%2==(d/b)%2 ))
        ans=min(ans,max(c/a,d/b));

    if(ans==inf)
        cout<<"Poor Inna and pony!";
    else
        cout<<ans;
    return 0;
}