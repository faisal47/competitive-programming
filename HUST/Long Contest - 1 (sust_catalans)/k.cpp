
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
#define scll2(a,b) scanf(" %lld %lld",&a,&b)
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

#define mt 12

ll arr1[mt],arr2[mt],arr3[mt];

ll solve(ll s)
{
    if(s<1)return 0;

    ll l=1,b=s,c1;

    while(b)
    {
        arr3[l++]=b%10;
        b/=10;
    }

    ll ans=arr1[arr3[1]],i;

    c1=10;
    ll d,tem,tem2=arr3[1];
    //deb1(l);

    for(i=2;i<l;i++)
    {
        d=arr3[i];
        tem=ans;
        ans=(d*arr2[i-1])+tem;

        if(d)
        {
            ans+=((tem2+1)*d)+(arr1[d-1]*c1);
        }
        tem2=(d*c1)+tem2;
        c1*=10;
    }
///87
    return ans;

}

int main ()
{
    ll a,b,i,j;

    for(i=1;i<=9;i++)
        arr1[i]=arr1[i-1]+i;

    arr2[1]=arr1[9];

    ll c=10;

    for(i=2;i<=11;i++)
        {
            arr2[i]=(10*arr2[i-1])+(arr2[1]*c);
            c*=10;
        }

    //deb1(arr2[10]);

    while(scll2(a,b)==2)
    {
        if(a==-1 && b==-1)
            break;

        a--;
        a=solve(a);
       // deb1(a);
        b=solve(b);
        //deb1(b);
        printf("%lld\n",b-a);

    }
    return 0;
}

