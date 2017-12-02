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
#define ull unsigned long long
#define dd double
#define rep(i,n) for(i=0;i<n;i++)
using namespace std;

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}


#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define mt 100010
#define mod

vec_<int>dam[210];
int cnt[mt],arr[mt],mot,ret;

void solve2(int len)
{
    for(int i=1;i<=200;i++)
    {
        while(sz(dam[i])>0 && dam[i][sz(dam[i])-1]==len)
        {
            ret+=i;
            dam[i].pop_back();
        }
    }
}

void solve3(int baki)
{
    int mini;
    for(int i=200;i>=1 && baki>0;i--)
    {
        if(baki>0 && sz(dam[i])>0)
        {
            mini=min(baki,sz(dam[i]));
            ret+=(mini * i);
            baki-=mini;
        }
    }
}

int solve(int len)
{
    ret=0;
    solve2(len);
    int baki=cnt[len]-1;
    solve3(baki);
    return mot-ret;
}

int main ()
{
    cffi;
    int i,j,n,a,maxi=-1,ans;
    ans=inf;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>arr[i],cnt[arr[i]]++;

    for(i=1;i<=n;i++)
    {
        cin>>a;
        mot+=a;
        dam[a].pb(arr[i]);
    }

    for(i=1;i<=200;i++)
        sort(all(dam[i]));

    for(i=100000;i>=1;i--)
    {
        if(cnt[i] < 1)
            continue;
        ans=min(solve(i),ans);
    }

    deb(ans);

    return 0;
}