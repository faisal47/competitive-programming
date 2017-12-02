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
#define ull unsigned long long
#define mt
using namespace std;

struct maan1
{
    int a,b,c,d,e,f;
};
vec_<maan1>maan;

bool comp(maan1 a,maan1 b)
{
    if(a.a!=b.a)
    {
        return a.a<b.a;
    }
    if(a.b!=b.b)
    return a.b<b.b;
    if(a.c!=b.c)
    return a.c<b.c;
    if(a.d!=b.d)
    return a.d<b.d;
    if(a.e!=b.e)
    return a.e<b.e;
    if(a.f!=b.f)
    return a.f<b.f;


}

int main ()
{
    int i,j,k,l,m,n,a;
    for(i=0;i<=15;i++)
    for(j=0;j<=15;j++)
    for(k=0;k<=15;k++)
    for(l=0;l<=15;l++)
    for(m=0;m<=15;m++)
    for(n=0;n<=15;n++)
    {
        if((i+j+k+l+m+n) == 15)
        {
            maan.pb({i,j,k,l,m,n});
        }
    }

    sort_m(maan);

  //  cout<<maan[15503].a<<" "<<maan[15503].b<<" "<<maan[15503].c<<" "<<maan[15503].d<<" "<<maan[15503].e<<" "<<maan[15503].f<<endl;

    char z;
    int kase=1;
    while(cin>>z && z!='e')
    {

        printf("Case %d: ",kase++);
        if(z=='m')
        {
            cin>>i;
            cin>>j;
            cin>>k;
            cin>>l;
            cin>>m;
            cin>>n;
            for(a=0;a<sz(maan);a++)
            {
                if(maan[a].a== i && maan[a].b== j && maan[a].c== k && maan[a].d== l && maan[a].e== m && maan[a].f== n)
                {
                    cout<<a<<endl;
                    break;
                }
            }
        }
        else
        {
            cin>>a;
            for(i=0;i<sz(maan);i++)
            if(a==i)
            {
                cout<<maan[i].a<<" "<<maan[i].b<<" "<<maan[i].c<<" "<<maan[i].d<<" "<<maan[i].e<<" "<<maan[i].f<<endl;
                break;
            }
        }
    }

    return 0;
}


