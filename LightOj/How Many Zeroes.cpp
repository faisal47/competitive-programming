/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <math.h>
#include <limits.h>
#include <limits>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
#include <ctime>
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
#define allr(a) a.rbegin(),a.rend()
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
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
using namespace std;

template<class T1> void deb(T1 e)
{
    cout<<e<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
}
//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};
//int X[]={1,1,2,2,-1,-1,-2,-2};//knight move//
//int Y[]={2,-2,1,-1,2,-2,1,-1};//knight move//
/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#define mt
#define mod

ll dp[14][10][2][2];
ll arr[12];

void pre_process(ll a)
{
    ms(arr,0ll);
    int c=0;
    while(a>0ll)
    {
        arr[c++]=a%10;
        a/=10;
    }
}

ll solve(int pos,int pre,bool flag,bool c_flag)
{
    if(pos < 0)
        return 0ll;


    ll &ret=dp[pos][pre][flag][c_flag];

    if(ret != -1ll)
        return ret;

    ret=0ll;
    int i;

    ll temp;

    if(c_flag)
        temp=1ll;
    else
        temp=0ll;

    if(flag)
    {
        for(i=0ll; i<=9; i++)
        {
            if(i==0ll)
                ret+=temp+solve(pos-1,i,1,c_flag);
            else
                ret+=solve(pos-1,i,1,1);
        }
    }
    else
    {
        for(i=0ll; i<=arr[pos]; i++)
        {
            if(i == 0ll)
            {
                if(i<arr[pos])
                    ret+=temp+solve(pos-1,i,1,c_flag);
                else
                    ret+=temp+solve(pos-1,i,0,c_flag);
            }
            else
            {
                if(i < arr[pos])
                    ret+=solve(pos-1,i,1,1);
                else
                    ret+=solve(pos-1,i,0,1);
            }
        }
    }

    return ret;
}

int main ()
{
    int i,j,test,t=1;
    ll a,b,ans;

    sci1(test);
    while(test--)
    {
        scll2(a,b);
        pre_process(b);
        ms(dp,-1ll);
        ans=solve(12,0,0,0)+1;
        a--;
        if(a>=0ll)
        {
            ms(dp,-1ll);
            pre_process(a);
            ans=ans-solve(12,0,0,0)-1;
        }

        printf("Case %d: %lld\n",t++,ans);
    }

    return 0;
}

