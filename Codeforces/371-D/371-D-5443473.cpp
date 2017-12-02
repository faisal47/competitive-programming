#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
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
#define sort_n(a) sort(a.begin(),a.end())
#define sort_m(a) sort(a.begin(),a.end(),comp)
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
#define deb1(a) cout<<a<<endl;
#define deb2(a,b) cout<<a<<" "<<b<<endl
#define deb3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define mt 2*100010
using namespace std;

ll next[mt],ase[mt],jabe[mt],n;

ll dhalo(ll a,ll b)
{
    if(a>n || b==0)
        return a;
    if(jabe[a]>=b)
    {
        jabe[a]-=b;
        ase[a]+=b;
        return a;
    }

    b-=jabe[a];
    ase[a]+=jabe[a];
    jabe[a]=0;
    return next[a]=dhalo(next[a],b);
}

int main ()
{
    ll i,j;
    scll1(n);
    for(i=1;i<=n;i++)
        {
            next[i]=i+1;
            scll1(jabe[i]);
        }

    ll q,a,b;

    scll1(q);

    while(q--)
    {
        scll1(a);
        if(a==1ll)
        {
            scll2(a,b);
            dhalo(a,b);
        }
        else
        {
            scll1(a);
            printf("%I64d\n",ase[a]);
        }
    }

    return 0;
}