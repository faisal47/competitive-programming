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
struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
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

int main ()
{
    int i,j,test,m1u,m1n,m2u,m2n,a1,a2,b1,b2,c1,c2;
    point a,b,c,d;
    int temp;
    dd x,y;

    sci1(test);

    puts("INTERSECTING LINES OUTPUT");

    while(test--)
    {
        scanf(" %d %d %d %d %d %d %d %d",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y);

        if(a.x > b.x)
            swap(a,b);
        if(c.x > d.x)
            swap(c,d);

        m1u=(a.y-b.y);
        m1n=(a.x-b.x);
        m2u=(c.y-d.y);
        m2n=(c.x-d.x);

        temp=__gcd(m1u,m1n);
        m1u/=temp;
        m1n/=temp;

        temp=__gcd(m2u,m2n);
        m2u/=temp;
        m2n/=temp;

        a1=a.y-b.y;
        b1=b.x-a.x;
        c1=(a.x*b.y) - (b.x * a.y);

        a2=c.y-d.y;
        b2=d.x-c.x;
        c2=(c.x*d.y) - (d.x * c.y);

        temp=__gcd(a1,__gcd(b1,c1));
        a1/=temp;
        b1/=temp;
        c1/=temp;

        temp=__gcd(a2,__gcd(b2,c2));
        a2/=temp;
        b2/=temp;
        c2/=temp;
        if(m1u == m2u && m1n==m2n)
        {
            if(a1==a2 && b1==b2 && c1==c2)
            {
                puts("LINE");
            }
            else
            {
                puts("NONE");
            }
        }
        else
        {
           x=(dd)((b1*c2)-(c1*b2))/(dd)((a1*b2)-(a2*b1));
           y=(dd)((a2*c1)-(a1*c2)) /(dd)((a1*b2)-(a2*b1));
           printf("POINT %.2lf %.2lf\n",x,y);
        }
    }

    puts("END OF OUTPUT");

    return 0;
}

