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

#define mt 1000010
#define mod 1000000007

ll dp[mt][4][4];

string st;

ll solve(int asi,int pre,int rakhmu)
{
//    if(indx == n)
//    {
//        if((keep == 0 && (arr[indx] == '0' || arr[indx] == '?')) ||
//           (keep == 1 && (arr[indx] == '1' || arr[indx] == '?') && last == 3) ||
//           (keep == 3 && (arr[indx] == '*' || arr[indx] == '?')))
//            return 1;
//        else
//            return 0;
//    }
    if(asi == sz(st)-1)
    {
//        if((rakhmu == 0 && (st[asi] == '0' || st[asi] == '?'))||
//            (rakhmu == 1 && (st[asi]=='1' || st[asi]=='?') && pre==3)||
//           (rakhmu==3 &&(st[asi]=='*' || st[asi]=='?')))
//           return 1ll;
//        return 0ll;
        //cout<<asi<<" "<<pre<<" "<<rakhmu<<endl;

       if(rakhmu == 2 || st[asi] == '2')
        return 0ll;

        if(st[asi]=='?' && pre !=3 && rakhmu==1)
            return 0ll;

       if(st[asi]=='?')
        return 1ll;

        if(st[asi] == '1' && pre == 3 && rakhmu ==1)
            return 1ll;

        if(st[asi] =='0' && rakhmu ==0)
            return 1ll;

        if(st[asi] =='*' && rakhmu ==3)
            return 1ll;

        return 0ll;
    }

    ll &ret=dp[asi][pre][rakhmu];

    if(ret!=-1ll)
        return ret;

    ret=0ll;

    if(st[asi] == '?')
    {
        if(rakhmu == 0)
        {
            ret=(ret + solve(asi+1,0,0))%mod;
            ret=(ret + solve(asi+1,0,1))%mod;
        }
        else if(rakhmu == 1 && pre == 3)
        {
            ret=(ret + solve(asi+1,1,0))%mod;
            ret=(ret + solve(asi+1,1,1))%mod;
        }
        else if(rakhmu == 1 && pre!=3)
            ret=(ret + solve(asi+1,1,3))%mod;
        else if(rakhmu == 3)
        {
            ret=(ret + solve(asi+1,3,1))%mod;
            ret=(ret + solve(asi+1,3,2))%mod;
            ret=(ret + solve(asi+1,3,3))%mod;
        }
        else if(rakhmu == 2)
            ret=(ret + solve(asi+1,2,3))%mod;
    }
    else if(st[asi] == '*' && rakhmu == 3)
    {
        ret=(ret + solve(asi+1,3,1))%mod;
        ret=(ret + solve(asi+1,3,2))%mod;
        ret=(ret + solve(asi+1,3,3))%mod;
    }
    else if(st[asi] == '0' && rakhmu == 0)
    {
        ret=(ret + solve(asi+1,0,0))%mod;
        ret=(ret + solve(asi+1,0,1))%mod;
    }
    else if(st[asi] == '1' && rakhmu == 1)
    {
        if(pre == 3)
        {
        ret=(ret + solve(asi+1,1,0))%mod;
        ret=(ret + solve(asi+1,1,1))%mod;
        }
        else if(pre!=3)
        ret=(ret + solve(asi+1,1,3))%mod;
    }
    else if(st[asi] == '2' && rakhmu == 2)
    {
        ret=(ret + solve(asi+1,2,3))%mod;
    }

    return ret;
}

int main ()
{
    ms(dp,-1ll);
    cin>>st;

    ll ans=0ll;

    if(st == "?")
    {
        cout<<2;
        return 0;
    }
    else if(st == "0" || st == "*")
    {
        cout<<1;
        return 0;
    }
    else if(st == "1" || st == "2")
    {
        cout<<0;
        return 0;
    }

    if(st[0] == '?')
    {
        ans=(ans + solve(1,0,0))%mod;
        ans=(ans + solve(1,0,1))%mod;
        ans=(ans + solve(1,1,3))%mod;
        ans=(ans + solve(1,3,1))%mod;
        ans=(ans + solve(1,3,3))%mod;
        ans=(ans + solve(1,3,2))%mod;
    }
    else if(st[0] == '0')
    {
        ans=(ans + solve(1,0,0))%mod;
        ans=(ans + solve(1,0,1))%mod;
    }
    else if(st[0] == '1')
    {
        ans=(ans + solve(1,1,3))%mod;
    }
    else if(st[0] == '*')
    {
        ans=(ans + solve(1,3,1))%mod;
        ans=(ans + solve(1,3,3))%mod;
        ans=(ans + solve(1,3,2))%mod;
    }

    cout<<ans;

    return 0;
}