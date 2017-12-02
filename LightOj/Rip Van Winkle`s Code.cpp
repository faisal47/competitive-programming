#include <bits/stdc++.h>

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
#define inf (1ll << 60)
#define mp make_pair
#define pi acos(-1)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define fs first
#define sc second
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define sf scanf
#define pf printf
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
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
#define sz(a) (int)a.size()
#define ll long long
#define LL long long
#define ull unsigned long long
#define dd double
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)

#define repa(i,n) for(auto i: n)
using namespace std;

#define fop freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

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



#define mt 250010
#define mod

struct maan
{
    ll a,ac,b,bc,sum,val;
};

maan seg[4*mt];

void pre()
{
    rep1(i,4*mt-4)
    {
        seg[i].a=0;
        seg[i].ac=0;
        seg[i].b=0;
        seg[i].bc=0;
        seg[i].val=inf;
        seg[i].sum=0;
    }
}

int qt,ml,mr;
ll nval;

ll go(ll fn,ll mot,ll d)
{
    fn=2*fn+(mot-1)*d;
    mot=mot*fn /2 ;
    return mot;
}

void push_down(int node,int l,int r)
{
    int b1=node<<1;
    int b2=b1|1;
    int mid=l+r >> 1;
    if(seg[node].val!=inf)
    {

        seg[b1].sum=(mid-l+1)*seg[node].val;
//        seg[b1].sum=(mid-l+1)*seg[node].val;
        seg[b2].sum=(r-mid)*seg[node].val;
        seg[b1].val=seg[b2].val=seg[node].val;
        seg[b1].a=seg[b1].ac=seg[b1].b=seg[b1].bc=0;
        seg[b2].a=seg[b2].ac=seg[b2].b=seg[b2].bc=0;
        seg[node].val=inf;
    }
    if(seg[node].a)
    {
        seg[b1].a+=seg[node].a;
        seg[b2].a+=seg[node].a+(mid-l+1)*seg[node].ac;

        seg[b1].sum+=go(seg[node].a,mid-l+1,seg[node].ac);
        seg[b2].sum+=go(seg[node].a+(mid-l+1)*seg[node].ac,r-mid,seg[node].ac);

        seg[b1].ac+=seg[node].ac;
        seg[b2].ac+=seg[node].ac;

        seg[node].a=seg[node].ac=0;
    }
    if(seg[node].b)
    {
        seg[b2].b+=seg[node].b;
        seg[b1].b+=seg[node].b+(r-mid)*seg[node].bc;

        seg[b2].sum+=go(seg[node].b,r-mid,seg[node].bc);
        seg[b1].sum+=go(seg[node].b+(r-mid)*seg[node].bc,mid-l+1,seg[node].bc);

        seg[b1].bc+=seg[node].bc;
        seg[b2].bc+=seg[node].bc;

        seg[node].b=seg[node].bc=0;
    }
}

void update(int node,int l,int r)
{
    if(r<ml || l>mr)
        return;
    int mid=l+r >>1;
    if(l>=ml && r<=mr)
    {
        if(qt==1)
        {
            seg[node].a+=(l-ml+1);
            seg[node].ac++;
            seg[node].sum+=go(l-ml+1,r-l+1,1);
        }
        else if(qt==2)
        {
            seg[node].b+=(mr-r+1);
            seg[node].bc++;
            seg[node].sum+=go(mr-r+1,r-l+1,1);
        }
        else
        {
            seg[node].val=nval;
            seg[node].sum=nval*(ll)(r-l+1);
            seg[node].a=seg[node].ac=seg[node].b=seg[node].bc=0;
        }
        return;
    }
    push_down(node,l,r);
    int b=node<<1;
    update(b,l,mid);
    update(b|1,mid+1,r);
    seg[node].sum=seg[b].sum+seg[b|1].sum;
}

ll query(int node,int l,int r)
{
    if(r<ml || l>mr)
        return 0;
    if(l>=ml && r<=mr)
    return seg[node].sum;

    int mid=l+r >>1;
    push_down(node,l,r);
    int b=node<<1;
    return query(b,l,mid) + query(b|1,mid+1,r);
}

/*
2
9
A 25 55
A 33 90
A 47 60
S 51 97
B 19 47
S 45 94
S 4 4
B 43 89
S 1 100
10
A 4 28
C 45 66 26
A 23 94
S 40 50
S 20 56
C 46 96 48
A 7 18
B 28 34
B 69 72
S 1 100
*/

int main ()
{
    int i,j,test,t=1,n,q;
    char z;
    sci1(test);
    while(test--)
    {
        pre();
        sci1(q);
        printf("Case %d:\n",t++);
        while(q--)
        {
            scanf(" %c",&z);
            sci2(ml,mr);
            if(z=='A')
                {
                    qt=1;
                    update(1,1,250000);
                }
            else if(z=='B')
            {
                qt=2;
                update(1,1,250000);
            }
            else if(z=='C')
            {
                qt=3;
                scll1(nval);
                update(1,1,250000);
            }
            else
                printf("%lld\n",query(1,1,250000));
        }
    }
    return 0;
}










