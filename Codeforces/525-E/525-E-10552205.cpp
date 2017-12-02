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
#define inf (1ll<<60)
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

#define mt
#define mod

vec_<ll>v1,v2;

int more_bit[15];
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
    more_bit[0] = 1;
    for(int i = 1; i < 14; i++) more_bit[i] = 3 * more_bit[i - 1];
}

map<ll,ll>ma1[30];
map<ll,ll>ma2[30];

ll fact[20];

void pre()
{
    ll i;
    fact[0]=fact[1]=1;
    for(i=2;i<20;i++)
        fact[i]=fact[i-1]*i;
}

int main ()
{
    cffi;
    pre();
    ll i,j;
    ll n,k,sum,a;
    ll half1,half2;
    int mask;
    cin>>n>>k>>sum;

    half1=n/2;
    half2=n-half1;
    v1.resize(half1);
    v2.resize(half2);
    for(i=0; i<half1; i++)
        cin>>v1[i];

    for(i=0; i<half2; i++)
        cin>>v2[i];


    int bit;
    mask=(int)pow(3,half1);
    init();
    ll now_sum,cnt;
    while(mask--)
    {
        now_sum=cnt=0;
        for(i=0;i<half1;i++)
        {
            bit=get_bit(mask,i);
            if(bit==1)
            {
                cnt++;
                if(v1[i]>19)
                    now_sum+=inf;
                else
                now_sum+=fact[v1[i]];
            }
            else if(bit==2)
                now_sum+=v1[i];
        }
        ma1[cnt][now_sum]++;
    }


    mask=(int)pow(3,half2);

    while(mask--)
    {
        now_sum=cnt=0;
        for(i=0;i<half2;i++)
        {
            bit=get_bit(mask,i);
            if(bit==1)
            {
                cnt++;
                if(v2[i]>19)
                    now_sum+=inf;
                else
                now_sum+=fact[v2[i]];
            }
            else if(bit==2)
                now_sum+=v2[i];
        }
        ma2[cnt][now_sum]++;
    }

    ll ans=0;
    ll baki,sum_baki;
    for(i=0;i<=half1;i++)
    {
        for(auto it : ma1[i])
        {
//            deb(it.fs,it.sc);
            baki=k-i;
            sum_baki=sum-it.fs;
            for(j=0;j<=baki;j++)
                ans+=(it.sc * ma2[j][sum_baki]);
        }
    }

    deb(ans);

    return 0;
}