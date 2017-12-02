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
#define pri1(a) printf("%d ",a)
#define pri2(a,b) printf("%d %d ",a,b)
#define prll1(a) printf("%I64d ",a)
#define prll2(a,b) printf("%I64d %I64d ",a,b)
#define sz(a) a.size()
#define ll long long
#define mt
using namespace std;
int main ()
{
    int test,t=1,n,m,ans;
    sci1(test);
    while(test--)
    {
        sci2(n,m);
        ans=m;
        ans+=n/2;
        ans+=m/2;
        if(n&1)ans++;
        if(m&1)ans++;
        ans-=2;
        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}

