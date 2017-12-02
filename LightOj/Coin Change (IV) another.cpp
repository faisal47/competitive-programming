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

#define mt 20
#define mod

int arr1[mt],arr2[mt],c2,c1,dp[210010];

vec_<int>v1,v2;

int more_bit[mt];
int get_bit(int mask , int pos)
{
    return (mask / more_bit[pos]) % 3;
}
int set_bit(int mask, int pos , int bit)
{
    int tmp = (mask / more_bit[pos]) % 3;
    mask -= tmp * more_bit[pos];
    mask += bit * more_bit[pos];
    return mask;
}
void init(void)
{
    more_bit[0] = 3;
    for(int i = 1; i < mt; i++) more_bit[i] = 3 * more_bit[i - 1];
}

int n,td=1;

void solve2(int mask,bool flag)
{
    if(mask == more_bit[n+1]-3)
        return;
    int i,sum=0,b;
    if(dp[mask] == td)
        return;
    dp[mask]=td;
    for(i=0;i<n;i++)
    {
        b=get_bit(mask,i);

        if(b < 2)
            solve2(set_bit(mask,i,b+1),flag);

        if(b > 0)
        {
            if(flag)
            sum+=(b*arr1[i]);
            else
            sum+=(b*arr2[i]);
        }
    }
    if(flag)
        v1.pb(sum);
    else
        v2.pb(sum);
}

bool solve(int num)
{
    clr(v1);
    clr(v2);
    n=c1;
    td++;
    solve2(0,1);
    if(c2 == 0)
        v2.pb(0);
    else
    {
        n=c2;
        td++;
        solve2(0,0);
        sort(all(v2));
    }
    int baki,i;

    for(i=0;i<sz(v1);i++)
    {
        baki=num-v1[i];
        if(binary_search(all(v2),baki))
            return 1;
    }
    return 0;
}

int main ()
{
    init();
    int n,i,j,test,t=1,k;

    sci1(test);
    while(test--)
    {
        sci2(n,k);
        c1=c2=n/2;
        if(n&1)c1++;
        for(i=0; i<c1; i++)
            sci1(arr1[i]);
        for(i=0; i<c2; i++)
            sci1(arr2[i]);
        if(solve(k))
            printf("Case %d: Yes\n",t++);
        else
            printf("Case %d: No\n",t++);
    }

    return 0;
}

