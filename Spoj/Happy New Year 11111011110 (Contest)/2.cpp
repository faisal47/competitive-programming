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
using namespace std;
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};

///***************************************************** ekhon kamer kam ********************************************************************///

#define mt 1010

double solve(double x1,double x2,double y1,double y2)
{
//    double x=(x1-x2)*(x1-x2);
//    x+=(y1-y2)*(y1-y2);
//    ((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2))
    return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
}

int main ()
{
    int i,t=1,test,n,j;
    double arr[mt][2],d,ans;
    bool flag;
    sci1(test);
    while(test--)
    {
        flag=0;
        sci1(n);
        ans=-1.;

        for(i=1; i<=n; i++)
            scd2(arr[i][0],arr[i][1]);

        for(i=1; i<=n; i++)
        {
            for(j=i+1; j<=n; j++)
            {
                d=solve(arr[i][0],arr[j][0],arr[i][1],arr[j][1]);
                d+=eps;
                if(d<2.000000)
                {
                    flag=1;
                    break;
                }
                ans=max(ans,d);
            }
            if(flag)
                break;
        }
        if(flag)
            pf("-1.000000\n");
        else
            printf("%.6lf\n",ans/2);
    }

    return 0;
}


