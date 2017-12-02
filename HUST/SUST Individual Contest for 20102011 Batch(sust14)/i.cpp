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

#define mt

struct timest
{
    int a,b;
};

vec_<timest>times;
vec_<int>another;

int ans;

bool okay(int t)
{
    sort(all(another));
    int a,i;
    bool flag;
    int st;

    do
    {
        a=another[0];
        st=times[a].a;
        flag=true;
        for(i=0; i<sz(another); i++)
        {
            a=another[i];
            if(st<times[a].a || st>times[a].b)
            {
                flag=false;
                break;
            }
            int j=i+1;
            if(j<sz(another))
            {
                st=max(st+t,times[another[j]].a);
               // st+=t;
            }
        }
        if(flag)
            return true;
    }
    while(next_permutation(all(another)));

    return false;
}

void bs(int l,int h)
{
    int mid;
    ans=-1;

    //sort(another);

    while(l<=h)
    {

        mid=(l+h)>>1;
        if(okay(mid))
        {
            ans=max(ans,mid);
            l=mid+1;
        }
        else
            h=mid-1;

    }

}

int main ()
{
    int n,i,t=1;
    while(cin>>n && n)
    {

        clr(times);
        clr(another);
        int a,b;

        for(i=0; i<n; i++)
        {
            another.pb(i);
            cin>>a>>b;
            a*=60*1000;
            b*=60*1000;
            times.pb({a,b});
        }

        bs(0,1440*60*1000);
        dd ans1=((dd)ans)/1000.;
        int ans2=round(ans1);
        printf("Case %d: %d:%02d\n",t++,ans2/60,ans2%60);

    }

    return 0;
}

