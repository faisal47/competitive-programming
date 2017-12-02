#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
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
#define fop freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define scch(a) scanf("%c",&a)
#define scll1(a) scanf("%I64d",&a)
#define scll2(a,b) scanf("%I64d %I64d",&a,&b)
#define scll3(a,b,c) scanf("%I64d %I64d %I64d",&a,&b,&c)
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define scd1(a) scanf("%lf",&a)
#define scd2(a,b) scanf("%lf %lf",&a,&b)
#define scd3(a,b,c) scanf("%lf %lf %lf",&a,&b,&c)
#define sz(a) a.size()
#define mt
using namespace std;
typedef long long ll;
//struct data //for dj()
//{
// int node,cost;
// bool operator < (const data& p) const
// {
// return cost > p.cost;
// }
//};
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};
int main ()
{
    int n,flag[300],c,i;
    string a;
    while(cin>>a)
    {
        ms(flag,0);c=0;
        for(i=0;i<sz(a);i++)
        {
            if(!flag[a[i]])
            {
                c++;
                flag[a[i]]=1;
            }
        }
        if(c%2==0)
        {
            cout<<"CHAT WITH HER!"<<endl;
        }
        else
        {
            cout<<"IGNORE HIM!"<<endl;
        }
    }
    return 0;
}

