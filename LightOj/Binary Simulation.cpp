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

#define mt 3*100010

int lp[mt];
char ins[mt];

void build(int s,int e,int node)
{
    lp[node]=0;

    if(s==e)
        return;

    int mid=(s+e)>>1;

    build(s,mid,(node<<1));
    build(mid+1,e,(node<<1)+1);
}

int a,b;

void push_down(int node)
{
    lp[node<<1]=(lp[node]+lp[node<<1])&1;
    lp[(node<<1)+1]=(lp[node]+lp[(node<<1)+1])&1;
    lp[node]=0;
}

void update(int s,int e,int node)
{
    if(e<a || s>b)
        return;

    if(s>=a && e<=b)
    {
        lp[node]=(lp[node]+1)&1;
        return;
    }

    push_down(node);

    int mid=(s+e)>>1;

    update(s,mid,(node<<1));
    update(mid+1,e,(node<<1)+1);
}

int query(int s,int e,int node)
{
    if(s==e)
    {
        return (lp[node]+ins[a-1]-'0')&1;
    }

    push_down(node);

    int mid=(s+e)>>1;

    if(a<=mid)
        return query(s,mid,(node<<1));

    return query(mid+1,e,(node<<1)+1);

}

int main ()
{
    int test,q,n,t=1;
    char z,com;

    scanf(" %d%c",&test,&z);

    while(test--)
    {

        gets(ins);

        n=strlen(ins)+1;
        sci1(q);

        build(1,n,1);

        printf("Case %d:\n",t++);

        while(q--)
        {
            scanf(" %c",&com);

            if(com=='I')
            {
                scanf(" %d %d%c",&a,&b,&z);
                update(1,n,1);
            }
            else
            {
                scanf(" %d%c",&a,&z);
                printf("%d\n",query(1,n,1));
            }
        }
    }

    return 0;
}
