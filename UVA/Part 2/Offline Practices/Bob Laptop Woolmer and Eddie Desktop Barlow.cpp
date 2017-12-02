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
#define dd double
using namespace std;
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};

///***************************************************** ekhon kamer kam ********************************************************************///

#define mt

int dp[105][12][12][12][12],arr1[105],arr2[105],arr3[105],bt,bl,al,n;

int solve(int pos,int mot,int bat,int ball,int alr)
{
    if(pos > n || mot==10)
        return 0;

    int &ret=dp[pos][mot][bat][ball][alr];

    if(ret!=-1)
        return ret;

    ret=0;

    if(bat<bt)
        ret=max(ret,arr1[pos]+solve(pos+1,mot+1,bat+1,ball,alr));

    if(ball<bl)
        ret=max(ret,arr2[pos]+solve(pos+1,mot+1,bat,ball+1,alr));

    if(alr<al)
        ret=max(ret,arr3[pos]+solve(pos+1,mot+1,bat,ball,alr+1));

    ret=max(ret,solve(pos+1,mot,bat,ball,alr));

    return ret;

}

vec_<int>ans1,ans2,ans3;

void path(int pos,int mot,int bat,int ball,int alr)
{
    if(pos > n || mot==10)
        return ;

    int ret=solve(pos,mot,bat,ball,alr);

    if(bat<bt && ret==arr1[pos]+solve(pos+1,mot+1,bat+1,ball,alr))
    {
        ans1.pb(pos);
        path(pos+1,mot+1,bat+1,ball,alr);
        return;
    }

    if(ball<bl && ret==arr2[pos]+solve(pos+1,mot+1,bat,ball+1,alr))
    {
        ans2.pb(pos);
        path(pos+1,mot+1,bat,ball+1,alr);
        return;
    }

    if(alr<al && ret==arr3[pos]+solve(pos+1,mot+1,bat,ball,alr+1))
    {
        ans3.pb(pos);
        path(pos+1,mot+1,bat,ball,alr+1);
        return;
    }

    path(pos+1,mot,bat,ball,alr);

    return;
}


int main ()
{
    //fop
    int i,test=0;
    dd a,b,c;

    while(scanf("%d",&n)==1 && n)
    {
        if(test++)
            puts("");

        for(i=1; i<=n; i++)
        {
            scanf("%lf %lf %lf",&a,&b,&c);
            arr1[i]=round((.8*a + .2*c)+eps);
            arr2[i]=round((.7*b  + .10*a + .2*c) +eps);
            arr3[i]=round((.4*a + .4*b + .2*c)+eps);
        }

        clr(ans1);
        clr(ans2);
        clr(ans3);

        scanf("%d %d %d",&bt,&bl,&al);

        ms(dp,-1);


        printf("Team #%d\nMaximum Effective Score = %d\nBatsmen : ",test,solve(1,0,0,0,0));

        path(1,0,0,0,0);

        for(i=0; i<sz(ans1); i++)
            {
                if(i)
                    cout<<" ";
                printf("%d",ans1[i]);
            }

        printf("\nBowlers : ");

        for(i=0; i<sz(ans2); i++)
            {
                if(i)
                    cout<<" ";
                printf("%d",ans2[i]);
            }

        printf("\nAll-rounders : ");

        for(i=0; i<sz(ans3); i++)
           {
               if(i)
                cout<<" ";
                printf("%d",ans3[i]);
           }
        puts("");

    }

    return 0;
}
