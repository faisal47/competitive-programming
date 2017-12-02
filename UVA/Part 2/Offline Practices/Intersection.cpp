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
#define scll2(a,b) scanf(" %I64d %I64d",&a,&b)
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

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};
//int X[]={1,1,2,2,-1,-1,-2,-2};//knight move//
//int Y[]={2,-2,1,-1,2,-2,1,-1};//knight move//
/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};

#define mt
#define mod

int dik_check(point o,point a,point b)
{
    int maan=(o.x-a.x)*(o.y-b.y) - (o.y-a.y)*(o.x-b.x);
    if(maan==0)
        return 0;
    if(maan<0)
        return -1;
    return 1;
}

bool online_check(point a,point mid,point b)
{
    return (mid.x>=min(a.x,b.x) && mid.x<=max(a.x,b.x)) && (mid.y>=min(a.y,b.y) && mid.y<=max(a.y,b.y));
}

bool intersection_check(point a,point b,point c,point d)
{
    int d1=dik_check(a,b,c);
    int d2=dik_check(a,b,d);
    int d3=dik_check(c,d,a);
    int d4=dik_check(c,d,b);

    if(d1!=d2 && d3!=d4)
        return 1;

    if(d1==0 && online_check(a,c,b))
        return 1;
    if(d2==0 && online_check(a,d,b))
        return 1;
    if(d3==0 && online_check(c,a,d))
        return 1;
    if(d4==0 && online_check(c,b,d))
        return 1;

    return 0;
}

int main ()
{
    int i,j,test;
    sci1(test);

    point ls,le,a,c,b,d;

    while(test--)
    {
        scanf(" %d %d %d %d %d %d %d %d",&ls.x,&ls.y,&le.x,&le.y,&a.x,&a.y,&c.x,&c.y);
        if(ls.x>le.x)
            swap(ls,le);
        if(a.x>c.x)
            swap(a,c);
        b.x=a.x;
        b.y=c.y;
        d.x=c.x;
        d.y=a.y;

        if(intersection_check(ls,le,a,b) || intersection_check(ls,le,b,c) || intersection_check(ls,le,c,d) || intersection_check(ls,le,d,a))
        {
            puts("T");
        }
        else if(dik_check(a,b,ls)==dik_check(b,c,ls) && dik_check(b,c,ls)==dik_check(c,d,ls) && dik_check(c,d,ls)==dik_check(d,a,ls) && dik_check(d,a,ls)==dik_check(a,b,ls))
        {
            puts("T");
        }
        else
        {
            puts("F");
        }
    }

    return 0;
}

