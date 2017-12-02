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

//double dur(int x1,int y1,int x2,int y2)
//{
//    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//}
//template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};
//int X[]={1,1,2,2,-1,-1,-2,-2};//knight move//
//int Y[]={2,-2,1,-1,2,-2,1,-1};//knight move//
/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#define mt 100010
#define mod

string st;

struct trie{
  int adj[27];
  trie()
  {
      ms(adj,-1);
  }
};
int nodeindx;
trie node[mt];

void maketrie(int nodeno,int pos)
{
    if(pos>=sz(st)) return;
    int tem=st[pos]-'a';

    if(node[nodeno].adj[tem]!=-1)
    {
        return maketrie(node[nodeno].adj[tem],pos+1);
    }

    nodeindx++;
    node[nodeno].adj[tem]=nodeindx;
    node[nodeindx]=trie();
    return maketrie(nodeindx,pos+1); //no problem here
}

int dp[mt];

int solve1(int pos)
{
//    if(pos == nodeindx)
//        return 0;
    int &ret=dp[pos];
    if(ret != -1)
        return ret;

    ret=0;

    int i;

    for(i=0;i<26;i++)
        if(node[pos].adj[i] != -1)
        ret  =ret| (!solve1(node[pos].adj[i]));

    return ret;
}


int solve2(int pos)
{
//    if(pos == nodeindx)
//        return 0;
    int &ret=dp[pos];
    if(ret != -1)
        return ret;

    ret=1;

    int i;

    bool ase=false;
    for(i=0;i<26;i++)
        if(node[pos].adj[i] != -1)
        {
            ase=true;
            ret &= (!solve2(node[pos].adj[i]));
        }

    if(!ase)
        return ret=0;

    return ret;
}

int main ()
{
    int i,j,n,k;

    cin>>n>>k;

    nodeindx=0;
    node[0]=trie();

    while(n--)
    {
        cin>>st;
        maketrie(0,0);
    }

    ms(dp,-1);
    int ret1=solve1(0);

    ms(dp,-1);
    int ret2=solve2(0);

    if(ret1)
    {
        if(!ret2)
            puts("First");
        else
        {
            if(k&1)
                puts("First");
            else
                puts("Second");
        }
    }
    else
        puts("Second");


    return 0;
}