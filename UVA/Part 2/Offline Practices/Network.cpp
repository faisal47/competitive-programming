/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#include <stdio.h>
#include <iostream>
#include <sstream>
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
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
using namespace std;

template<class T1> void deb(T1 e)
{
    cout<<e<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
}
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};

/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#define mt 110
#define mod

map<int,int>ma;
int low[mt],pre[mt],ti,c,root;
vec_ <int>edge[mt];

void dfs(int u,int p)
{
    int child=0,v,i;
    low[u]=pre[u]=ti;
    ti++;
    for(i=0; i<edge[u].size(); i++)
    {
        v=edge[u][i];
        if(pre[v]==0)
        {
            child++;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=pre[u] && u!=root && ma.find(u)==ma.end())
            {
                c++;
                ma[u]=1;
            }
        }
        else if(v!=p)
        {
            low[u]=min(low[u],pre[v]);
        }
        if(child>=2 && u==root && ma.find(u)==ma.end())
        {
            c++;
            ma[u]=1;
        }
    }
}


int main ()
{
    int i,j,n;
    char arr[mt];
    stringstream ss;
    string st;
    char z;

    while(scanf(" %d",&n)==1 && n)
    {
        scanf("%c",&z);
        clr(ma);
        c=0;
        ti=1;
        for(i=1; i<=n; i++)
        {
            clr(edge[i]);
            low[i]=pre[i]=0;
        }

        while(1)
        {
            //deb("hello");
            gets(arr);
            if(arr[0] == '0')
                break;
            clr(ss);
            st=arr;
            //deb(st);
            ss<<st;
            ss>>i;
            while(ss>>j)
            {
                //deb(i,j);
                edge[i].pb(j);
                edge[j].pb(i);
            }
        }

        for(i=1; i<=n; i++)
        {
            if(pre[i]==0)
            {
                root=i;
                dfs(i,i);
            }
        }

        printf("%d\n",c);

    }

    return 0;
}

