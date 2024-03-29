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

//special sieve :P
//bool sieve[SZ];
//ll prime[664579];
//int p;
//void SOE()
//{
//  int i, j, k=0, r;
//  prime[k++] = 2LL;
//  for(i=3; i<=SZ-1; i+=2)
//  {
//      if(sieve[i]==false)
//      {
//          prime[k++] = (ll)(i);
//          if(i<(SZ-1)/i)
//          {
//              r = (i<<1);
//              for(j=(i*i); j<(SZ-1); j+=r)
//              {
//                  sieve[j] = true;
//              }
//          }
//      }
//  }
//  p = k;
//  return ;
//}

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
/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#define mt
#define mod

string arr;
int p,n;

int dp[1010][150][150][2];

bool solve(int pos,int l,int sl,bool boro)
{
    if(pos==n)
        return boro;

    int &ret=dp[pos][l][sl][boro];
    if(ret != -1)
        return ret;
    ret=0;

    if(boro)
    {
        int i;
        for(i='a';i<'a'+p;i++)
        {
            if(i!=l && i!=sl)
            ret|=solve(pos+1,i,l,1);
        }
    }
    else
    {
        for(int i=arr[pos];i<'a'+p;i++)
        {
            if(i!=l && i!=sl)
                ret|=solve(pos+1,i,l,boro);
            boro=1;
        }
    }
    return ret;
}

bool solve2(int pos,int l,int sl,int boro)
{
    if(pos==n)
        return boro;
    bool ret=false;
    if(boro)
    {
        int i;
        for(i='a';i<'a'+p;i++)
        {
            if(i!=l && i!=sl)
                ret=solve(pos+1,i,l,1);
            if(ret)
            {
                cout<<(char)i;
                solve2(pos+1,i,l,1);
                return 0;
            }
        }
    }
    else
    {
        for(int i=arr[pos];i<'a'+p;i++)
        {
            if(i!=l && i!=sl)
                ret=solve(pos+1,i,l,boro);
            if(ret)
            {
                cout<<(char)i;
                solve2(pos+1,i,l,boro);
                return 0;
            }
            boro=1;
        }
    }
    return ret;
}

int main ()
{
    int i,j;

    cin>>n>>p>>arr;
    ms(dp,-1);
    bool ans=solve(0,0,0,0);
    if(ans)
        solve2(0,0,0,0);
    else
        puts("NO");
    return 0;
}