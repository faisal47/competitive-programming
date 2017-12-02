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
#define scll2(a,b) scanf(" %lld %lld",&a,&b)
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

#define mt
#define mod

string arr;

void convert(int n)
{
    arr="";
    while(n>0ll)
    {
        arr+=(n%10)+'0';
        n/=10;
    }
    string st;
    int i;
    for(i=sz(arr)-1;i>=0;i--)
        st+=arr[i];
    arr=st;
}

ll arr1[12],arr2[12],mot,arr3[12];

ll solve()
{
    ll ret=0ll,t,c,num;
    int i;
    c=sz(arr);
    c--;

    for(i=0;i<sz(arr);i++)
    {
//        cout<<c<<endl;
        if(c==0)
            ret+=arr1[arr[i]-'0'];
        else
        {
            num=(arr[i]-'0');
//            cout<<num<<" "<<arr2[c]<<endl;
            t=num*arr2[c];
            t+=arr3[c-1];
            ret+=t;
        }
        c--;
    }

    return ret;
}


int main ()
{
    int i,j;
    ll ans;
    ll a,b;

    for(i=1;i<10;i++)
        arr1[i]=arr1[i-1]+i;

    for(i=1;i<=10;i++)
    {
        arr3[i]=i*10;
    }

    for(i=1;i<=10;i++)
        arr3[i]+=arr3[i-1];

    mot=arr1[9];
    arr2[1]=mot;
    arr2[2]=(10*mot)+(45*10);
    arr2[3]=arr2[2]*10+(10*45);
    arr2[4]=arr2[3]*10+(10*45);
    arr2[5]=arr2[4]*10+(10*45);
    arr2[6]=arr2[5]*10+(10*45);
    arr2[7]=arr2[6]*10+(10*45);
    arr2[8]=arr2[7]*10+(10*45);
    arr2[9]=arr2[8]*10+(10*45);
    arr2[10]=arr2[9]*10+(10*45);

//    deb(arr2[1]);
//    deb(arr2[2]);
//    deb(arr2[3]);
//    deb(arr2[4]);
//    deb(arr2[5]);
//    deb(arr2[6]);
//    deb(arr2[7]);
//    deb(arr2[8]);
//    deb(arr2[9]);

    while(scll2(a,b)==2)
    {
        if(a==-1ll && b==-1ll)
            break;
        convert(b);
        deb(arr);
        ans=solve();
        deb(ans);
        a--;
        convert(a);

        deb(arr);
        ans-=solve();
        deb(ans);
    }

    return 0;
}

