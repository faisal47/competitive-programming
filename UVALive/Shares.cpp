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
#define pii pair<ll,ll>
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
#define scll1(a) scanf(" %lld",&a)
#define scll2(a,b) scanf(" %lld %lld",&a,&b)
#define scll3(a,b,c) scanf(" %lld %lld %lld",&a,&b,&c)
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

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}


//double dur(int x1,int y1,int x2,int y2)
//{
//    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//}
//template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll B,ll P,ll M){ll R=1;while(P>0){if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}return R;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};
//int X[]={1,1,2,2,-1,-1,-2,-2};//knight move//
//int Y[]={2,-2,1,-1,2,-2,1,-1};//knight move//

#define mt
#define mod

map<pii,ll>ma;
ll n,m;
ll arr1[505],arr2[505],arr[50010],kina[50010],mot;
map<ll,ll>dp,temp;

ll solve()
{
    ll ret=0;
    clr(dp);
    dp[0]=0;
    ll mini,i;
    for(i=0;i<m;i++)
    {
        if(arr[i]<=0)
            continue;
        temp=dp;
        for(auto it:dp)
        {
            if(it.fs+kina[i]<=mot)
            {
                if(temp.find(it.fs+kina[i]) == temp.end())
                    temp[it.fs+kina[i]]=arr[i]+it.sc;
                else
                    temp[it.fs+kina[i]]=max(temp[it.fs+kina[i]],arr[i]+it.sc);
            }
        }
        clr(dp);
        mini=-1;
        for(auto it:temp)
        {
            if(mini < it.sc)
            {
                mini=it.sc;
                dp[it.fs]=it.sc;
            }
        }

    }
    for(auto it:dp)
        ret=max(ret,it.sc);
    return ret;
}

int main ()
{
    int i,j,t=0;
    ll r,a,b;
    while(scll1(mot) == 1)
    {
        if(t++)
            puts("");
        scll2(n,m);
        for(i=1;i<=n;i++)
        scll2(arr1[i],arr2[i]);
        for(i=0;i<m;i++)
        {
            scll1(r);
            arr[i]=0;
            kina[i]=0;
            while(r--)
            {
                scll2(a,b);
                arr[i]+=(arr2[a]*b - arr1[a]*b);
                kina[i]+=(b * arr1[a]);
            }
        }
        printf("%lld\n",solve());
    }
    return 0;
}
/*
200000000
5 30
2800 3500
1400 4800
2900 2800
500 3800
3300 4700
2 2 13 4 15
4 4 1 1 22 3 17 5 22
1 3 2
1 3 6
4 1 11 2 5 3 7 5 15
1 5 1
4 2 26 1 21 3 8 5 26
2 3 5 2 26
4 2 30 4 12 3 7 5 14
3 3 8 2 20 5 3
1 5 30
2 1 29 3 3
5 3 3 1 20 5 26 4 9 2 25
3 1 2 2 16 3 5
2 5 5 4 26
5 2 18 5 10 4 18 1 12 3 30
3 2 5 3 27 5 4
4 3 2 4 8 1 20 2 6
3 2 14 1 1 4 22
5 2 23 3 26 1 27 5 3 4 6
1 2 16
4 1 13 4 10 2 23 5 2
1 1 14
1 2 20
1 3 14
2 3 21 1 22
1 2 27
3 5 24 1 26 3 13
5 4 15 3 3 2 21 1 5 5 16
4 2 22 5 1 4 10 1 30

*/
