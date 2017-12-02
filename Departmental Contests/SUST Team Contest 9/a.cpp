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
int dx[]={0,-1,-1,-1,0,1,1,1};
int dy[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};
int cnt[25*60+10],ans[1010];
vector<int>in[1010],out[1010];
int main ()
{
    int n,m,hour,month,day;
    while(cin>>n&&n)
    {
        int preday=-1,premonth=-1,id, a;
        char ch;
        ms(ans,0);
        while(n--){
            scanf(" %d/%d %d:%d %c %d",&month,&day,&hour,&m,&ch,&id);
            if(day==preday&&month==premonth)
            {
                a=hour*60+m;
                if(ch=='I')
                    in[id].pb(a);
                if(ch=='O')
                    out[id].pb(a);
            }
            else
            {
                ms(cnt,0);
                for(int i=0;i<in[0].size();i++)
                {
                    for(int j=in[0][i]+1;j<=out[0][i];j++)
                        cnt[j]=1;
                }
                for(int i=1;i<1000;i++)
                {
                    for(int j=0;j<in[i].size();j++)
                    {
                        for(int k=in[i][j]+1;k<=out[i][j];k++)
                            ans[i]+=cnt[k];
                    }
                }
                premonth=month;
                preday=day;
                for(int i=0;i<1000;i++)
                {
                    in[i].clear();
                    out[i].clear();
                }
                a=hour*60+m;
                if(ch=='I')
                    in[id].pb(a);
                if(ch=='O')
                    out[id].pb(a);
            }
        }

        ms(cnt,0);
        for(int i=0;i<in[0].size();i++)
        {
            for(int j=in[0][i]+1;j<=out[0][i];j++)
                cnt[j]=1;
        }
        for(int i=1;i<1000;i++)
        {
            for(int j=0;j<in[i].size();j++)
            {
                for(int k=in[i][j]+1;k<=out[i][j];k++)
                    ans[i]+=cnt[k];
            }
        }
        for(int i=0;i<1000;i++)
        {
            in[i].clear();
            out[i].clear();
        }
        int mx=0;
        for(int i=1;i<1000;i++)
            mx=max(ans[i],mx);
        cout<<mx<<endl;
    }
    return 0;
}


