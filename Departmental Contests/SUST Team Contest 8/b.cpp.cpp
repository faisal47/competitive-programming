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
//struct data //for dj()
//{
//   int node,cost;
//   bool operator < (const data& p) const
//   {
//       return cost > p.cost;
//   }
//};
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};

struct box{
    int w, h, l, area,pp,pq;
} arr[11];

bool comp(const box &a, const box &b)
{
    if(a.l==b.l&&a.w==b.w)
        return a.h>=b.h;
    if(a.l==b.l)
        return a.w>=b.w;
    return a.l >= b.l;
}
bool comp1(const box &a,const box &b)
{
    if(a.l==b.l&&a.w==b.w)
        return a.h>=b.h;
    if(a.w==b.w)
        return a.l>=b.l;
    return a.w >= b.w;
}
bool comp2(const box &a,const box &b)
{
    if(a.h==b.h&&a.w==b.w)
        return a.l>=b.l;
    if(a.h==b.h)
        return a.w>=b.w;
    return a.h >= b.h;
}

int main ()
{
    int i,j, n, l[11], kase = 1;
    box b;
    while(scanf("%d", &n) == 1 && n)
    {
        for(i = 0; i < n; i++)
        {
            scanf("%d %d %d", &b.h, &b.l, &b.w);
            l[i] = 1;
            int s[3] = {b.h, b.l, b.w};
            sort(s, s + 3);
            b.l = s[2];
            b.w = s[1];
            b.h = s[0];
            b.pp=1;
            b.pq=1;
            arr[i] = b;
        }
        sort(arr, arr + n, comp);
        int ans = 1;
        for(i = 0; i < n; i++)
        {
            //cout << arr[i].area << endl;
            for(j = i - 1; j >= 0; j--)
            {
                if(arr[i].l >= arr[j].l && arr[i].w >= arr[j].w)
                {
                    arr[i].pp = max(arr[i].pp, arr[j].pp + 1);
                    ans = max(ans, arr[i].pp);
                }
                if(arr[i].l>=arr[j].w&&arr[i].w>=arr[j].h)
                {

                    arr[i].pp=max(arr[i].pp,arr[j].pq+1);
                    ans = max(ans, arr[i].pp);
                }
                if(arr[i].w>=arr[j].w&&arr[i].h>=arr[j].h)
                {
                    arr[i].pq = max(arr[i].pq, arr[j].pq + 1);
                    ans = max(ans, arr[i].pq);
                }
                if(arr[i].w>=arr[j].l&&arr[i].h>=arr[j].w)
                {
                    arr[i].pq=max(arr[i].pq,arr[j].pp+1);
                    ans=max(ans,arr[i].pq);
                }
            }
        }
        sort(arr, arr + n, comp1);
        for(int i=0;i<n;i++)
            arr[i].pp=arr[i].pq=1;
        for(i = 0; i < n; i++)
        {
            //cout << arr[i].area << endl;
            for(j = i - 1; j >= 0; j--)
            {
                if(arr[i].l >= arr[j].l && arr[i].w >= arr[j].w)
                {
                    arr[i].pp = max(arr[i].pp, arr[j].pp + 1);
                    ans = max(ans, arr[i].pp);
                }
                if(arr[i].l>=arr[j].w&&arr[i].w>=arr[j].h)
                {

                    arr[i].pp=max(arr[i].pp,arr[j].pq+1);
                    ans = max(ans, arr[i].pp);
                }
                if(arr[i].w>=arr[j].w&&arr[i].h>=arr[j].h)
                {
                    arr[i].pq = max(arr[i].pq, arr[j].pq + 1);
                    ans = max(ans, arr[i].pq);
                }
                if(arr[i].w>=arr[j].l&&arr[i].h>=arr[j].w)
                {
                    arr[i].pq=max(arr[i].pq,arr[j].pp+1);
                    ans=max(ans,arr[i].pq);
                }
            }
        }
        sort(arr, arr + n, comp2);
        for(int i=0;i<n;i++)
            arr[i].pp=arr[i].pq=1;
        for(i = 0; i < n; i++)
        {
            //cout << arr[i].area << endl;
            for(j = i - 1; j >= 0; j--)
            {
                if(arr[i].l >= arr[j].l && arr[i].w >= arr[j].w)
                {
                    arr[i].pp = max(arr[i].pp, arr[j].pp + 1);
                    ans = max(ans, arr[i].pp);
                }
                if(arr[i].l>=arr[j].w&&arr[i].w>=arr[j].h)
                {
                    arr[i].pp=max(arr[i].pp,arr[j].pq+1);
                    ans = max(ans, arr[i].pp);
                }
                if(arr[i].w>=arr[j].w&&arr[i].h>=arr[j].h)
                {
                    arr[i].pq = max(arr[i].pq, arr[j].pq + 1);
                    ans = max(ans, arr[i].pq);
                }
                if(arr[i].w>=arr[j].l&&arr[i].h>=arr[j].w)
                {
                    arr[i].pq=max(arr[i].pq,arr[j].pp+1);
                    ans=max(ans,arr[i].pq);
                }
            }
        }
        printf("Case %d: %d\n", kase++, ans);
    }
    return 0;
}


