//#include <bits/stdc++.h>

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
#define pi acos(-1)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define fs first
#define sc second
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);
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
#define scll1(a) scanf(" %I64d",&a)
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
#define rep(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
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



#define mt 50010
#define mod

int seg[4*mt],arr[mt];

struct maan
{
    int l,r,qt,ind;
};
vec_<maan>qr;

bool comp(maan a,maan b)
{
    if(a.r == b.r)
        return a.qt < b.qt;
    return a.r < b.r;
}
maan temp;
int age[mt];

void update(int node,int l,int r,int num,int ind)
{
    if(r < ind || l>ind)
        return;
    if(l==r)
    {
        seg[node]=max(seg[node],num);
        return;
    }
    int mid=(l+r)>>1;
    update(node<<1,l,mid,num,ind);
    update((node<<1)|1,mid+1,r,num,ind);
    seg[node]=max(seg[node<<1],seg[(node<<1)|1]);
}

int solve(int node,int l,int r,int l1,int r1)
{
//    deb(node,l,r);
    if(r < l1 || l>r1)
        return 0;
    if(l>=l1 && r<=r1)
        return seg[node];
    int mid=(l+r)>>1;
    return max(solve(node<<1,l,mid,l1,r1),solve((node<<1)|1,mid+1,r,l1,r1));
}
vec_<int>dv;
void fdiv(int num)
{
    clr(dv);
    int i;
    dv.pb(num);
    dv.pb(1);
    for(i=2; i*i<=num; i++)
    {
        if(num % i == 0)
        {
            dv.pb(i);
            if(i == (num/i))
                continue;
            dv.pb(num/i);
        }
    }
}
void go(int n,int num,int ind)
{
    int i;
    fdiv(num);
    rep(i,sz(dv))
    {
        num=dv[i];
        if(age[num] == -1)
        {
            age[num]=ind;
            continue;
        }
        update(1,1,n,num,age[num]);
        age[num]=ind;
    }
}

int ans[mt];

int main ()
{
//    cffi;
    int i,j,test,n,q;
    sci1(test);
    while(test--)
    {
        clr(qr);
        ms(seg,0);
        sci1(n);
        rep1(i,n)
        {
            age[i]=-1;
            sci1(arr[i]);
//            cin>>arr[i];
            temp.ind=temp.l=temp.r=i;
            temp.qt=1;
            qr.pb(temp);
        }
        sci1(q);
//        cin>>q;
        rep1(i,q)
        {
            sci2(temp.l,temp.r);
//            cin>>temp.l>>temp.r;
            temp.ind=i;
            temp.qt=2;
            qr.pb(temp);
        }
        sort(all(qr),comp);
        rep(i,sz(qr))
        {
//            deb(qr[i].l,qr[i].r,qr[i].qt);
            if(qr[i].qt == 1)
            {
                go(n,arr[qr[i].l],qr[i].l);
                continue;
            }
            ans[qr[i].ind]=solve(1,1,n,qr[i].l,qr[i].r);
        }
        rep1(i,q)
        printf("%d\n",ans[i]);
    }
    return 0;
}










