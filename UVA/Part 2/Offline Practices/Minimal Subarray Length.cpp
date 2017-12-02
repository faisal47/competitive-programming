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
#define scll1(a) scanf(" %lld",&a)
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
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};
//int X[]={1,1,2,2,-1,-1,-2,-2};//knight move//
//int Y[]={2,-2,1,-1,2,-2,1,-1};//knight move//
/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#define mt1  500010
#define mt2  4*500010
#define mod

ll rmax[mt2],arr[mt1],cum_sum[mt1];

ll dsum;

int el,er;

ll build(int node,int s,int e)
{
    if(s == e)
    {
        return rmax[node]=cum_sum[s];
    }
    int mid=(s+e)>>1;

    return rmax[node]=max(build(node<<1,s,mid),build((node<<1)|1,mid+1,e));
}

int query(int node,int s,int e)
{
    if(e<el || s>er)
        return inf;

    if(s>=el && e<=er)
    {
        if(s == e)
        {
            if(rmax[node] >= dsum)
                return s;
            return inf;
        }

        int mid=(s+e)>>1;

        if(rmax[node<<1]>=dsum)
            return query(node<<1,s,mid);

        if(rmax[(node<<1)|1]>=dsum)
            return query((node<<1)|1,mid+1,e);

        return inf;
    }

    int ans=inf,mid;
    mid=(s+e)>>1;

//    if(rmax[node<<1]>=dsum)
    ans=min(ans,query(node<<1,s,mid));

//    if(rmax[(node<<1)|1]>=dsum)
    ans=min(ans,query((node<<1)|1,mid+1,e));

    return ans;
}

int main ()
{
    int i,j,test,n;
    sci1(test);
    ll x;
    int ans,temp;

    while(test--)
    {
        ans=inf;
        sci1(n);
        scll1(x);
        for(i=1; i<=n; i++)
        {
            scll1(arr[i]);
            cum_sum[i]=arr[i] + cum_sum[i-1];
        }

        build(1,1,n);

        er=n;
        for(i=1; i<=n; i++)
        {
            el=i;
            dsum=x+cum_sum[i-1];

            ans=min(ans,query(1,1,n)-i+1);
//            ans=min(ans,temp);
        }

        if(ans >= mt1)
            puts("-1");
        else
            printf("%d\n",ans);

    }
    return 0;
}

