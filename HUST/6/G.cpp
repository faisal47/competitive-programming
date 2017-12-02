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
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define pli pair<ll,ll>
#define pil pair<ll,ll>
#define fs first
#define sc second
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define sf scanf
#define pf prllf
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
#define sz(a) (ll)a.size()
#define ll long long
#define LL long long
#define ull unsigned long long
#define dd double
#define rep(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
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

#define mt
#define mod 1000000007

int mm,arr[12];

void pre(int n)
{
    ms(arr,0);
    int cn=0;
    while(n>0)
    {
        arr[cn++]=n%10;
        n/=10;
    }
}

ll dp[12][1030][2][2];

ll solve(int pos,int mask,bool flag,bool sf)
{
    if(pos < 0)
        return mask == mm;

    ll &ret = dp[pos][mask][flag][sf];
    if(ret != -1)
        return ret;
    ret=0;
    int i,e;
    if(flag)
        e=9;
    else
        e=arr[pos];
    bool tsf;
    rep(i,e+1)
    {
        tsf=sf | (i>0);
        if(!(mm & (1<<i)) && tsf)
            continue;
        if(tsf)
        ret+=solve(pos-1,mask|(1<<i),flag | (i<e),tsf);
        else
        ret+=solve(pos-1,mask,flag | (i<e),tsf);
    }
    return ret;
}

ll pre2[1030];
ll dp2[1030][1030];

ll solve2(int m1,int m2)
{
    if(m2 >= (1<<10))
        return 1;
    ll &ret=dp2[m1][m2];
    if(ret != -1)
        return ret;
    ret=solve2(m1,m2+1);
    if((m1&m2) == 0)
        ret=(ret+((solve2(m1|m2,m2+1)*pre2[m2])%mod))%mod;
    return ret;
}


int main ()
{
    int i,j,test,n,t=1;
    ll res;
    sci1(test);
    while(test--)
    {
        sci1(n);
        pre(n);
        res=1;
        mm=1<<10;
        ll mot=0;
        while(mm--)
        {
            if(mm<2)
                break;
            ms(dp,-1);
            pre2[mm]=solve(11,0,0,0);
        }
        ms(dp2,-1);
        res=solve2(0,2);
        res=(res -1 + mod)%mod;
        printf("Case %d: %lld\n",t++,res);
    }
    return 0;
}









