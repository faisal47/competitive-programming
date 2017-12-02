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

string ins[mt],st;

struct tri
{
    int arr[26];
    bool word_shesh;
    tri()
    {
        ms(arr,-1);
        word_shesh=0;
    }
};

vec_<tri>trie;

tri a;

int nodes,ans;

void make_trie(int node,int pos)
{
    int temp=st[pos]-'a',tnode;

//    deb(temp);

    if(pos == sz(st)-1)
    {
        if(trie[node].arr[temp] != -1)
        {
            tnode=trie[node].arr[temp];
            trie[tnode].word_shesh=1;

            return;
        }

        trie[node].arr[temp]=nodes;
        trie.pb(a);
        trie[nodes].word_shesh=1;
        nodes++;
        return;
    }

    if(trie[node].arr[temp] != -1)
    {
        make_trie(trie[node].arr[temp],pos+1);
    }
    else
    {
        trie[node].arr[temp]=nodes;
        trie.pb(a),nodes++;
        make_trie(trie[node].arr[temp],pos+1);
    }
}

void solve(int node,int pos)
{
    if(pos >= sz(st))
        return;

    int temp=st[pos]-'a',tnode;

    if(pos == 0)
    {
        ans++;
        solve(trie[node].arr[temp],pos+1);
        return;
    }

//    if(pos == sz())

    int i,c=0;

    for(i=0;i<26;i++)
        if(trie[node].arr[i] != -1)
        c++;

    if(c>1)
    {
        ans++;
        solve(trie[node].arr[temp],pos+1);
        return;
    }

    if(trie[node].word_shesh==1)
        ans++;

    solve(trie[node].arr[temp],pos+1);

}

int main ()
{
    int i,j,n;

    while(cin>>n)
    {
        clr(trie);
        ans=0;
        nodes=1;
        trie.pb(a);

        for(i=1; i<=n; i++)
        {
            cin>>ins[i];
            st=ins[i];
            make_trie(0,0);
        }

//        for(i=0;i<nodes;i++)
//            deb("in trie ",i,trie[i].word_shesh);

        for(i=1; i<=n; i++)
        {
            st=ins[i];
            solve(0,0);
//            deb("ans ",ans);
        }

//        deb("ans",ans);

        printf("%.2lf\n",(dd)ans/(dd)n);
    }

    return 0;
}

