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
#define sort_n(a) sort(a.begin(),a.end())
#define sort_m(a) sort(a.begin(),a.end(),comp)
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
#define pri1(a) printf("%d ",a)
#define pri2(a,b) printf("%d %d ",a,b)
#define prll1(a) printf("%I64d ",a)
#define prll2(a,b) printf("%I64d %I64d ",a,b)
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define mt
using namespace std;
//struct data //for dj()
//{
//   int node,cost;
//   bool operator < (const data& p) const
//   {
//       return cost > p.cost;
//   }
//};
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};
int main ()
{
    int arr[4][2],t=1;
    int test,i,j,flag,ans,ans1;
    cin>>test;
    while(test--)
    {
        //flag=0;
        for(i=0;i<4;i++)
        cin>>arr[i][0]>>arr[i][1];
        for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        {
            if(i==j)continue;
            ans1=min(abs(arr[i][0]-arr[j][0]),abs(arr[i][1]-arr[j][1]));
            if(ans1<=10)
            {
                ans=-1;
                break;
            }
            else
            ans=min(ans,ans1);
        }
        double ans2=ans/2.;
        if(ans==-1)
        printf("Case %d: no solution\n",t++);
        else
        printf("Case %d: %.2lf\n",t++,ans2-.001);

    }
    return 0;
}


