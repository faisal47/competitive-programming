
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

#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define mt 500010
#define mod

int seg[mt*4*2];

struct maan
{
    int ind,a,l,r;
};

int ans[mt];
vec_<maan>v,temp;
vec_<int>ques,numbers;
map<int,int>ma;
int maxin;

bool comp(maan a,maan b)
{
    if(a.r == b.r)
        return a.ind < b.ind;
    return a.r > b.r;
}

int ml,mr;

void update(int node,int l,int r)
{
    if(r < ml || l>ml)
        return;
    seg[node]++;
    if(l == r)
        return;
    int mid=(l+r)>>1;
    update(node<<1,l,mid);
    update((node<<1)|1,mid+1,r);
}

void update2(int node,int l,int r)
{
    if(r < ml || l>ml)
        return;
    seg[node]--;
    if(l == r)
        return;
    int mid=(l+r)>>1;
    update2(node<<1,l,mid);
    update2((node<<1)|1,mid+1,r);
}

int query(int node,int l,int r)
{
    if(r<ml || l>mr)
        return 0;
    if(l>=ml && r<=mr)
        return seg[node];
    int mid=(l+r)>>1;
    return query(node<<1,l,mid)+query((node<<1)|1,mid+1,r);
}

void solve(int l,int r)
{
    if(l == r)
        return;
    int i,mid;
    clr(temp);
    mid=(l+r)>>1;
    for(i=l;i<=mid;i++)
        if(!v[i].a)
            temp.pb(v[i]);
    for(i=mid+1;i<=r;i++)
        if(v[i].a)
            temp.pb(v[i]);
    sort(all(temp),comp);

    rep(i,sz(temp))
    {
        ml=mr=temp[i].l;
        if(temp[i].a)
        {
            ml=0;
            ans[temp[i].ind]+=query(1,0,maxin);
            continue;
        }
        update(1,0,maxin);
    }
    rep(i,sz(temp))
    {
        ml=mr=temp[i].l;
        if(temp[i].a)
            continue;
        update2(1,0,maxin);
    }

    solve(l,mid);
    solve(mid+1,r);
}

int main ()
{
    cffi;
    maan temp;
    int i,j,n,a,b;
    char z;

    cin>>n;
    rep(i,n)
    {
        temp.a=0;
        temp.ind=i;
        cin>>z>>a>>b;
        temp.l=a;
        temp.r=b;
        if(z == '?')
            {
                temp.a=1;
                ques.pb(i);
            }
        v.pb(temp);
        if(ma.find(a) == ma.end())
        {
            ma[a]=1;
            numbers.pb(a);
        }
        if(ma.find(b) == ma.end())
        {
            ma[b]=1;
            numbers.pb(b);
        }
    }

    sort(all(numbers));
    rep(i,sz(numbers))
    ma[numbers[i]]=i;
    maxin=sz(numbers)-1;
    rep(i,n)
    {
        v[i].l=ma[v[i].l];
        v[i].r=ma[v[i].r];
    }

    solve(0,n-1);
    rep(i,sz(ques))
    deb(ans[ques[i]]);

    return 0;
}

/*

9
+ 5 10
+ 7 20
+ 3 15
? 9 12
+ 10 20
? 8 9
+ 6 30
? 8 9
? 9 12

*/
