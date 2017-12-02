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
    int w, h, l, area;
} arr[11];

bool comp(const box &a, const box &b)
{
    return a.area >= b.area;
}

int main ()
{
    int i,j, n, l[11], kase = 1, my[11];
    box b;
    while(scanf("%d", &n) == 1 && n)
    {
        for(i = 0; i < n; i++)
        {
            scanf("%d %d %d", &b.h, &b.l, &b.w);
            l[i] = 1;
            my[i] = i;
        int s[3] = {b.h, b.l, b.w};
        sort(s, s + 3);
        b.h = s[2];
        b.w = s[1];
        b.l = s[0];
        b.area = b.l * b.w;
        arr[i] = b;
        }
//        sort(arr, arr + n, comp);
        int ans = 1;
        do
        {
            int tem = 1;
            for(i = 0; i < n; i++)
            {
                l[i] = 1;
                for(j = i - 1; j >= 0; j++)
                {
                    if(arr[my[i]].l <= arr[my[j]].l && arr[my[i]].w <= arr[my[j]].w)
                        l[i] = max(l[i], l[j] + 1);
                }
                tem = max(tem, l[i]);
            }
            ans = max(tem, ans);
        }while(next_permutation(my, my + n));
        printf("Case %d: %d\n", kase++, ans);
    }
    return 0;
}


