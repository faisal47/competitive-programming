/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#include <stdio.h>
#include <iostream>
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

/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#define mt 100010
#define mod 1000000007

int low[mt],exact[mt],t,n,col[mt],cost[mt];
ll ans1,ans2;
vec_<int>v[mt],dag[mt];
stack<int>s;
vec_<int>emne;

void initialize()
{
    int i;
    while(!s.empty())
    s.pop();
    for(i=1;i<=n;i++)
    {
        clr(v[i]);
        exact[i]=low[i]=col[i]=0;
    }
}
void tarjan(int a)
{
    s.push(a);
    col[a]=1;
    low[a]=exact[a]=t++;
    int i,j;
    for(i=0;i<v[a].size();i++)
    {
        j=v[a][i];
        if(!col[j])
        {
           tarjan(j);
           low[a]=min(low[a],low[j]);
        }
        else if(col[j]==1)
         low[a]=min(low[a],exact[j]);
    }
    if(exact[a]==low[a])
    {
        clr(emne);
        int c=1,mini=inf;
        j=-1;
        while(j!=a)
        {
            j=s.top();
            emne.pb(cost[j]);
            s.pop();
            col[j]=2;
            mini=min(mini,j);
        }
        sort(all(emne));
        mini=emne[0];
        for(j=1;j<sz(emne);j++)
        {
            if(mini==emne[j])
                c++;
            else
                break;
        }

        ans1=(ans1+mini);
        ans2=(ans2*c)%mod;
    }
}


int main ()
{
    int i,a,b,m;
    while(sci1(n)==1)
    {
        ans1=0ll;
        ans2=1ll;
        initialize();
        for(i=1;i<=n;i++)
            sci1(cost[i]);

        sci1(m);
        while(m--)
        {
            sci2(a,b);
            v[a].pb(b);
        }

        for(i=1;i<=n;i++)
        if(!col[i])
        tarjan(i);

        printf("%lld %lld\n",ans1,ans2);
    }
    return 0;
}