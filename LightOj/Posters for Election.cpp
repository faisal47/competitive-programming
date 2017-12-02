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

#define mt 200010
#define SZ 200010
#define mod

#define LL long long

pii arr[mt];

int segtree[SZ * 4], beg, en, sum;
int lazy[SZ * 4];
void lazy_update(int lef, int rig, int cur, int val)
{
    if(lazy[cur])
    {
        segtree[cur] =lazy[cur];
        if(lef != rig)
        {
            lazy[cur << 1] = lazy[cur];
            lazy[(cur << 1) + 1] = lazy[cur];
        }
        lazy[cur] = 0;
    }
    if(lef > en || rig < beg)
        return;
    if(lef >= beg && rig <= en)
    {
        segtree[cur] = val;
        if(rig != lef)
        {
            lazy[cur << 1] = val;
            lazy[(cur << 1) + 1] = val;
        }
        return;
    }
    lazy_update(lef, (lef + rig) >> 1, cur << 1, val);
    lazy_update(((lef + rig) >> 1) + 1, rig, (cur << 1) + 1, val);
//    segtree[cur] = segtree[cur << 1] + segtree[(cur << 1) + 1];
}

map<int,int>ma;

void query(int lef, int rig, int cur)
{
    if(lazy[cur])
    {
        segtree[cur] = lazy[cur];
        if(lef != rig)
        {
            lazy[cur << 1] = lazy[cur];
            lazy[(cur << 1) + 1] = lazy[cur];
        }
        lazy[cur] = 0;
    }
    if(lef == rig)
    {
        ma[segtree[cur]]=1;
        return;
    }
    query(lef, (lef + rig) >> 1, cur << 1);
    query(((lef + rig) >> 1) + 1,rig, (cur << 1) + 1);
}

int main ()
{
    int i,j,test,n,a,b,t=1;
    vec_<int>points;
    sci1(test);
    while(test--)
    {
        clr(ma);
        sci1(n);
        clr(points);
        for(i=1; i<=n; i++)
        {
            sci2(a,b);
            arr[i]=mp(a,b);
            if(ma.find(a) == ma.end())
            {
                ma[a]=1;
                points.pb(a);
            }
            if(ma.find(b) == ma.end())
            {
                ma[b]=1;
                points.pb(b);
            }
        }
        sort(all(points));
        for(i=0; i<sz(points); i++)
            ma[points[i]]=i+1;
        ms(segtree,0);
        for(i=1; i<=n; i++)
        {
            beg=ma[arr[i].fs];
            en=ma[arr[i].sc];
            /// update from now
            lazy_update(1,sz(points),1,i);
        }
        clr(ma);
        query(1,sz(points),1);
        printf("Case %d: %d\n",t++,sz(ma));
    }

    return 0;
}
