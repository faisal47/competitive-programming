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
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
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



#define mt 1005
#define mod

int seg[mt*mt*2];
int ma1,ma2,mb1,mb2;

void update(int node,int a1,int b1,int a2,int b2)
{
    if(ma2 < a1 || ma1>a2 || mb2 < b1 || mb1 > b2)
        return;
    if(a1==a2 && b1==b2)
    {
        seg[node]=1;
        return;
    }
    int ba1,ba2,ba3,ba4;
    ba1=(node<<2) -2;
    ba2=(node<<2) -1;
    ba3=(node<<2);
    ba4=(node<<2) +1;
    int m1=a1+a2 >> 1;
    int m2=b1+b2 >> 1;
    update(ba1,a1,b1,m1,m2);
    update(ba2,m1+1,b1,a2,m2);
    update(ba3,m1+1,m2+1,a2,b2);
    update(ba4,a1,m2+1,m1,b2);
    seg[node]=seg[ba1]+seg[ba2]+seg[ba3]+seg[ba4];
}

int query(int node,int a1,int b1,int a2,int b2)
{
    if(ma2 < a1 || ma1>a2 || mb2 < b1 || mb1 > b2)
        return 0;
    if(a1>=ma1 && a2<=ma2 && b1>=mb1 && b2<=mb2)
        return seg[node];

    int ba1,ba2,ba3,ba4;
    ba1=(node<<2) -2;
    ba2=(node<<2) -1;
    ba3=(node<<2);
    ba4=(node<<2) +1;
    int m1=a1+a2 >> 1;
    int m2=b1+b2 >> 1;
    return query(ba1,a1,b1,m1,m2)+query(ba2,m1+1,b1,a2,m2)+query(ba3,m1+1,m2+1,a2,b2)+query(ba4,a1,m2+1,m1,b2);
}

int arr[mt][mt];

int main ()
{
    int i,j,test,t=0,n,q,qt;
    sci1(test);
    while(test--)
    {
        t++;
        ms(seg,0);
        sci1(q);
        printf("Case %d\n",t);
        while(q--)
        {
            sci1(qt);
            if(!qt)
            {
                sci2(ma1,mb1);
                ma2=ma1;
                mb2=mb1;
                if(arr[ma1][mb1]!=t)
                update(1,0,0,1000,1000);
                arr[ma1][mb1]=t;
            }
            else
            {
                sci2(ma1,mb1);
                sci2(ma2,mb2);
                printf("%d\n",query(1,0,0,1000,1000));
            }
        }
    }
    return 0;
}










