/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#include <stdio.h>
#include <iostream>
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
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};

/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#define mt 50
#define mod

string a,b,st,sam="018";
char arr[mt];

int dp[mt][2];

int check()
{
//    return 1;
    int i,pos=0;
    for(i=48; i>=0; i--)
        if(arr[i] != '0')
        {
            pos=i;
            break;
        }

    if(pos <=0)
        return 1;
    int l=0;
    while(pos>l)
    {
        if(arr[pos] != arr[l])
            return 0;
        pos--;
        l++;
    }

    return 1;
}

int solve(int pos,bool flag)
{

    if(pos<0)
    {
//        return 1;
        return check();
    }

    int &ret=dp[pos][flag];

    if(ret != -1)
        return ret;

    int i;

    ret=0;

    if(!flag)
    {
        for(i=0; i<sz(sam); i++)
        {
            arr[pos]=sam[i];
            ret+=solve(pos-1,0);
        }
    }
    else
    {
        for(i=0; i<sz(sam); i++)
        {
            if(sam[i]<st[pos])
            {
                arr[pos]=sam[i];
                ret+=solve(pos-1,0);
            }
            else if(sam[i] == st[pos])
            {
//                cout<<"hello"<<endl;
                arr[pos]=sam[i];
                ret+=solve(pos-1,1);
            }
        }
    }

    return ret;
}

int main ()
{
    int i,j,test,ans;
    cin>>test;

    while(test--)
    {
        cin>>a>>b;
        st=b;
        st=string(allr(st));
        for(i=0; i<50; i++)
        {
            arr[i]='0';
            if(i>=sz(st))
                st+='0';
        }
//        cout<<st<<endl;
        ms(dp,-1);
        ans=solve(48,1);
//        deb(ans);
        st=a;
        st=string(allr(st));
        for(i=0; i<50; i++)
        {
            arr[i]='0';
            if(i>=sz(st))
                st+='0';
        }
        ms(dp,-1);
        ans-=solve(48,1);
        for(i=0;i<50;i++)
        {
            if(i>=sz(a))
                arr[i]='0';
            else
                arr[i]=a[i];
        }
        ans+=check();
        printf("%d\n",ans);
    }
    return 0;
}
